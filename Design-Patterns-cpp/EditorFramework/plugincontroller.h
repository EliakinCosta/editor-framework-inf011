#ifndef PLUGINCONTROLLER_H
#define PLUGINCONTROLLER_H

#include <../EditorFrameworkInterfaces/iplugincontroller.h>
#include <../EditorFrameworkInterfaces/iplugin.h>

template<typename>
class QList;
class ICore;

class PluginController: public IPluginController
{
public:
    PluginController(ICore* core);
    virtual ~PluginController();
    virtual bool loadPlugins();
    virtual QList<IPlugin*>* loadedPlugins() const;
private:
    QList<IPlugin*>* m_loadedPlugins;
    ICore* m_core;
};

#endif // PLUGINCONTROLLER_H
