#ifndef IPROTOTYPE_H
#define IPROTOTYPE_H

<<<<<<< HEAD
#include "editorframeworkinterfaces_global.h"
#include <QtCore/QObject>

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IPrototype
{
public:
    IPrototype();
    virtual ~IPrototype(){}
    virtual IPrototype *clone() = 0;
};

Q_DECLARE_INTERFACE(IPrototype, "org.qt-project.EditorFrameworkInterfaces.IPrototype")

=======

class IPrototype
{
public:
    IPrototype();
    virtual IPrototype* clone() const;
};

>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b
#endif // IPROTOTYPE_H
