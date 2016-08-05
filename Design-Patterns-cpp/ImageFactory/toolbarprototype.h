#ifndef TOOLBARPROTOTYPE_H
#define TOOLBARPROTOTYPE_H

#include <../EditorFrameworkInterfaces/iprototype.h>

class ToolBarPrototype:public IPrototype
{
public:
    ToolBarPrototype();
    virtual IPrototype* clone() const;
};

#endif // TOOLBARPROTOTYPE_H
