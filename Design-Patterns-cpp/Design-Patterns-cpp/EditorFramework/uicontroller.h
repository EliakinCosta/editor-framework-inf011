#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <../EditorFrameworkInterfaces/iuicontroller.h>
#include <../EditorFrameworkInterfaces/icore.h>
#include "mainwindow.h"
#include <QObject>

class QString;
class QMenu;
class MainWindow;

class UiController:public IUiController,
                   public QObject
{
public:
    UiController(ICore* core);
    virtual ~UiController();
    virtual QMenu* addMenu(const QString& title, const QString& parentMenuName);
    virtual bool addAction(const QString &menuName, const QString &text, const QObject *receiver, const char *member, const QKeySequence &shortcut = QKeySequence());
private:
    void initialize();
    MainWindow* m_mainWindow;
    ICore* m_core;
private Q_SLOTS:
    void teste();
};

#endif // UICONTROLLER_H
