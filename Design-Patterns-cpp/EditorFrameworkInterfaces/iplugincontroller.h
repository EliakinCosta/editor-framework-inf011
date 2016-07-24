#ifndef IPLUGINCONTROLLER_H
#define IPLUGINCONTROLLER_H

#include "editorframeworkinterfaces_global.h"

class QString;
class IPlugin;
template<typename>
class QList;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IPluginController
{
public:
    IPluginController();
    virtual ~IPluginController(){}
    virtual bool loadPlugins() = 0;
    virtual QList<IPlugin*>* loadedPlugins() const = 0;
};

#endif // IPLUGINCONTROLLER_H
