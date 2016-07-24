#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <../EditorFrameworkInterfaces/iuicontroller.h>
#include <../EditorFrameworkInterfaces/icore.h>
#include <../EditorFrameworkInterfaces/ieditor.h>
#include "mainwindow.h"

class QStringList;

class UiController:public IUiController
{
    Q_OBJECT
public:
    UiController(ICore* core);
    virtual ~UiController();
    virtual QMenu* addMenu(const QString& title, const QString& parentMenuName);
    virtual bool addAction(const QString &menuName, const QString &text, const QObject *receiver, const char *member, const QKeySequence &shortcut = QKeySequence());
    virtual void setEditor(const IEditor *editor);
private:
    void initialize();
    MainWindow* m_mainWindow;
    ICore* m_core;
private Q_SLOTS:
    void actionOpen();
};

#endif // UICONTROLLER_H
