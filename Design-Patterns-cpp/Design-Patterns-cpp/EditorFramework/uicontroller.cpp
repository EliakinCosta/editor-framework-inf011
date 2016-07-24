#include "uicontroller.h"
#include <../EditorFrameworkInterfaces/icore.h>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QWidget>
#include <QObject>
#include "ui_mainwindow.h"


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
    addMenu(QObject::tr("&File"), QObject::tr("&File"));
    addAction(tr("&File"), tr("&Open"), this, SLOT(UiController::teste()),QKeySequence(Qt::CTRL + Qt::Key_O));
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

void UiController::teste(){

}
