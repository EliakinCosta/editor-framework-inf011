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

UiController::UiController(ICore* core):m_mainWindow(new MainWindow),
                                                         m_core(core)
{
    m_mainWindow->show();
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
    addMenu(tr("&Plugins"), tr("&Plugins"));
    addMenu(tr("&Compression Plugins"), tr("&Plugins"));

    m_compressionAlgorithmGroup = new QActionGroup(m_mainWindow);
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
                break;
            }
        }
    }
}

void UiController::setEditor(const IEditor *editor)
{
    QWidget *view = editor->view();
    m_mainWindow->setCentralWidget(view);
}

void UiController::populateMenus(QObject *plugin, QMenu *menu)
{
    ICompressionAlgorithm *icompresionAlgorithm = qobject_cast<ICompressionAlgorithm *>(plugin);
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
    m_core->documentController()->activeDocument()->compress();
}


void UiController::clearMenu(QMenu *menu)
{
    menu->clear();
}
