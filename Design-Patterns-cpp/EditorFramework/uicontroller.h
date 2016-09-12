#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <../EditorFrameworkInterfaces/iuicontroller.h>
#include <../EditorFrameworkInterfaces/icore.h>
#include <../EditorFrameworkInterfaces/ieditor.h>
#include "mainwindow.h"

class QStringList;
class QActionGroup;
class QTabWidget;

class UiController:public IUiController
{
    Q_OBJECT
public:
    UiController(ICore* core);
    virtual ~UiController();
    virtual QMenu* addMenu(const QString& title, const QString& parentMenuName);
    virtual bool addAction(const QString &menuName, const QString &text, const QObject *receiver, const char *member, const QKeySequence &shortcut = QKeySequence());
    virtual void setEditor(const IEditor *editor);
    virtual void populateMenus(QObject *plugin, QMenu *menu);
private:
    void initialize();
    void addPluginToMenu(QObject *plugin, QMenu *menu, const char *member, QActionGroup *actionGroup);
    void clearMenu(QMenu *menu);
    MainWindow* m_mainWindow;
    ICore* m_core;
    QTabWidget *m_tabs;
    QActionGroup *m_compressionAlgorithmGroup;
private Q_SLOTS:
    void actionOpen();
    void actionCompress();
    void actionUncompress();
    void changeCompressionAlgorithm();
    void closeTab_(int index);
};

#endif // UICONTROLLER_H
