#include "uicontroller.h"
#include <../EditorFrameworkInterfaces/icore.h>
#include <../EditorFrameworkInterfaces/iabstractfactory.h>
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/iplugincontroller.h>
#include <../EditorFrameworkInterfaces/ieditor.h>
#include <../EditorFrameworkInterfaces/idocument.h>
#include <../EditorFrameworkInterfaces/iprototype.h>
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>
#include "documentcontroller.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QWidget>
#include <QDir>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QTabWidget>

UiController::UiController(ICore* core):m_mainWindow(new MainWindow),
                                                         m_core(core),
                                                         m_tabs(new QTabWidget())
{
    m_mainWindow->show();
    m_tabs->setTabsClosable(true);
    m_mainWindow->setCentralWidget(m_tabs);
    initialize();
}

UiController::~UiController()
{
    delete m_mainWindow;
}

QMenu* UiController::addMenu(const QString& title, const QString& parentMenuName)
{
    QList<QMenu *> children = m_mainWindow->ui->menuBar->findChildren<QMenu *>(parentMenuName);
    QMenu *parentMenu = children.isEmpty() ? 0:children.first();
    QMenu *newMenu;
    if (parentMenu){
        newMenu = parentMenu->addMenu(title);
    }
    else
        newMenu = m_mainWindow->ui->menuBar->addMenu(title);
    newMenu->setObjectName(title);
    return newMenu;
}


void UiController::initialize()
{
    addMenu(tr("&File"), tr("&File"));
    addAction(tr("&File"), tr("&Open"), this, SLOT(actionOpen()),QKeySequence(Qt::CTRL + Qt::Key_O));
    addMenu(tr("&Save Settins"), tr("&File"));
    addAction(tr("&Save Settins"), tr("&Compress"), this, SLOT(actionCompress()),QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_C));
    addAction(tr("&Save Settins"), tr("&Uncompress"), this, SLOT(actionUncompress()),QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_U));
    addMenu(tr("&Plugins"), tr("&Plugins"));
    addMenu(tr("&Compression Plugins"), tr("&Plugins"));

    m_compressionAlgorithmGroup = new QActionGroup(m_mainWindow);

    connect(m_tabs, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab_(int)));
}


bool UiController::addAction(const QString &menuName, const QString &text, const QObject *receiver, const char *member, const QKeySequence &shortcut)
{
    QList<QMenu *> children = m_mainWindow->ui->menuBar->findChildren<QMenu*>(menuName);
    if(children.isEmpty())
    {
        return false;
    }
    children.first()->addAction(text, receiver, member, shortcut);
    return true;
}

void UiController::actionOpen(){
    QFileDialog *fileDialog = new QFileDialog(m_mainWindow);

    if (fileDialog->exec())
    {
        QString selectedFile = fileDialog->selectedFiles().at(0);
        qDebug()<<"nome arquivo: "<<selectedFile;
        QString fileExtension = "*."+selectedFile.split(".").at(1);
        qDebug()<<"extensao: "<<fileExtension;
        IPluginController* pluginController = m_core->pluginController();
        pluginController->clear();
        pluginController->loadPlugins();
        clearMenu(m_mainWindow->ui->menuBar->findChildren<QMenu*>(tr("&Compression Plugins")).first());
        IEditor *editorPrototype = 0;
        IDocument *documentPrototype = 0;

        foreach(IPlugin *plugin, *pluginController->loadedPlugins())
        {
            populateMenus(plugin, m_mainWindow->ui->menuBar->findChildren<QMenu *>("&Compression Plugins").first());
            IAbstractFactory* factory = dynamic_cast<IAbstractFactory*>(plugin);
            if(factory)
            {
                qDebug()<<"Plugin carregado!!"<<factory;
                editorPrototype =  dynamic_cast<IEditor*>(factory->create(QString("Editor")));
                documentPrototype = dynamic_cast<IDocument*>(factory->create(QString("Document")));
                qDebug()<<"antes do cast";
                qDebug()<<editorPrototype;
                m_core->documentController()->setActiveDocument(documentPrototype);
                documentPrototype->open(selectedFile);
                editorPrototype->setDocument(documentPrototype);
                setEditor(editorPrototype);
            }
        }
    }
}

void UiController::actionCompress()
{
    m_core->documentController()->activeDocument()->compress();
}

void UiController::actionUncompress()
{
    m_core->documentController()->activeDocument()->uncompress();
}

void UiController::setEditor(const IEditor *editor)
{
    QWidget *view = editor->view();
    m_tabs->addTab(view, tr("&Tab"));
}

void UiController::populateMenus(QObject *plugin, QMenu *menu)
{
    ICompressionAlgorithm *icompresionAlgorithm = qobject_cast<ICompressionAlgorithm *>(plugin);
    qDebug() << icompresionAlgorithm;
    if (icompresionAlgorithm)
        addPluginToMenu(plugin,
                  menu,
                  SLOT(changeCompressionAlgorithm()),
                  m_compressionAlgorithmGroup);
}

void UiController::addPluginToMenu(QObject *plugin,
                           QMenu *menu, const char *member,
                           QActionGroup *actionGroup)
{
    QAction *action = new QAction(plugin->metaObject()->className(), plugin);

    connect(action, SIGNAL(triggered()), this, member);
    menu->addAction(action);

    if (actionGroup) {
        action->setCheckable(true);
        actionGroup->addAction(action);
    }
}

void UiController::changeCompressionAlgorithm()
{
    qDebug() << "Ativo";
    QAction *action = qobject_cast<QAction *>(sender());
    ICompressionAlgorithm *iCompressionAlgorithm = qobject_cast<ICompressionAlgorithm *>(action->parent());

    m_core->documentController()->activeDocument()->setCompressionAlgorithm(iCompressionAlgorithm);
}


void UiController::clearMenu(QMenu *menu)
{
    menu->clear();
}

void UiController::closeTab_(int index)
{
    qDebug() << "ativo" << index;
    m_tabs->removeTab(index);
}
