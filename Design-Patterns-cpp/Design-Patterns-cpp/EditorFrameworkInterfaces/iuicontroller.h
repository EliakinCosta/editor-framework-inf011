#ifndef IUICONTROLLER_H
#define IUICONTROLLER_H

#include "editorframeworkinterfaces_global.h"
#include <QtGui/QKeySequence>

class QMenu;
class QString;
class QObject;


class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IUiController
{
public:
    IUiController();
    virtual ~IUiController();
    virtual QMenu* addMenu(const QString& title, const QString& parentMenuName) = 0;
    virtual bool addAction(const QString& menuName, const QString& text, const QObject* receiver, const char* member, const QKeySequence& shortcut = QKeySequence()) = 0;
};

#endif // IUICONTROLLER_H
