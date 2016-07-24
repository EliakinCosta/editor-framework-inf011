#include "uicontroller.h"
#include <../EditorFrameworkInterfaces/icore.h>
#include <../EditorFrameworkInterfaces/iabstractfactory.h>
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/iplugincontroller.h>
#include <../EditorFrameworkInterfaces/ieditor.h>
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
    QString fileName = QFileDialog::getOpenFileName(m_mainWindow, tr("Open Image"), QDir::currentPath(), tr("All Files (*.*)"));
    QString fileExtension = fileName.split(".")[1];

    IPluginController* pluginController = m_core->pluginController();
    foreach(IPlugin *plugin, *pluginController->loadedPlugins())
    {
        IAbstractFactory* factory = dynamic_cast<IAbstractFactory*>(plugin);
        if(factory && factory->createSupportedExtensions().contains(fileExtension))
        {
              IEditor* editor =  factory->createEditor();
              IDocument* document = factory->createDocument();
              editor->setDocument(document);
              setEditor(editor);
        }
    }
}

void UiController::setEditor(const IEditor *editor)
{
    QWidget *view = editor->view();
    m_mainWindow->setCentralWidget(view);
}
