#ifndef IUICONTROLLER_H
#define IUICONTROLLER_H

#include "editorframeworkinterfaces_global.h"
#include <QtGui/QKeySequence>
#include <QObject>

class QMenu;
class QAction;
class QString;
class IEditor;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IUiController:public QObject
{
    Q_OBJECT
public:
    IUiController(QObject* parent = 0);
    virtual ~IUiController();
    virtual QMenu* addMenu(const QString& title, const QString& parentMenuName) = 0;
    virtual bool addAction(const QString& menuName, const QString& text, const QObject* receiver, const char* member, const QKeySequence& shortcut = QKeySequence()) = 0;
    virtual void setEditor(const IEditor *editor) = 0;
    virtual void populateMenus(QObject *plugin, QMenu *menu) = 0;
} ;

#endif // IUICONTROLLER_H
