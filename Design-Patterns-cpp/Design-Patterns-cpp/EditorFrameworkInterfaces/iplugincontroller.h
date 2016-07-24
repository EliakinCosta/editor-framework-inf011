#ifndef IPLUGINCONTROLLER_H
#define IPLUGINCONTROLLER_H

#include "editorframeworkinterfaces_global.h"

template<typename>
class QList;
class QString;
class IPlugin;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IPluginController
{
public:
    IPluginController();
    virtual ~IPluginController(){}
    virtual bool loadPlugins() const = 0;
    virtual QList<IPlugin*>* loadedPlugins() const = 0;
};

#endif // IPLUGINCONTROLLER_H
