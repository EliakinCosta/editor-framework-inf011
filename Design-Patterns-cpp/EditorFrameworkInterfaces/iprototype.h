#ifndef IPROTOTYPE_H
#define IPROTOTYPE_H

#include "editorframeworkinterfaces_global.h"
#include <QtCore/QObject>

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IPrototype
{
public:
    IPrototype();
    virtual ~IPrototype(){}
    virtual IPrototype *clone() = 0;
    virtual bool addPrototype(IPrototype *prototype) = 0;
};

Q_DECLARE_INTERFACE(IPrototype, "org.qt-project.EditorFrameworkInterfaces.IPrototype")

#endif // IPROTOTYPE_H
