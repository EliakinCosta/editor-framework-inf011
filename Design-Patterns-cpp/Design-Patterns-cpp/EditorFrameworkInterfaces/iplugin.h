#ifndef IPLUGIN_H
#define IPLUGIN_H

#include "editorframeworkinterfaces_global.h"

class ICore;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IPlugin
{
public:
    IPlugin();
    virtual ~IPlugin(){}
    virtual bool initialize(ICore* core) = 0;
};

#endif // IPLUGIN_H
