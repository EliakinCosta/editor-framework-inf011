#ifndef IABSTRACTFACTORY_H
#define IABSTRACTFACTORY_H

#include "editorframeworkinterfaces_global.h"
#include <QtCore/QObject>

class IPrototype;
class QString;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IAbstractFactory
{
public:
    IAbstractFactory();
    virtual ~IAbstractFactory();
    virtual IPrototype* create(QString namePrototype) const = 0;
};

Q_DECLARE_INTERFACE(IAbstractFactory, "org.qt-project.EditorFrameworkInterfaces.IAbstractFactory")

#endif // IABSTRACTFACTORY_H
