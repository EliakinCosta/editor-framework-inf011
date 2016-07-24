#include "plugincontroller.h"
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/iabstractfactory.h>
#include <../EditorFrameworkInterfaces/icore.h>
#include <QDir>
#include <QPluginLoader>
#include <QApplication>

PluginController::PluginController(ICore* core):m_loadedPlugins(new QList<IPlugin*>),
                                     m_core(core)
{

}

PluginController::~PluginController()
{
    delete m_loadedPlugins;
    delete m_core;
}

bool PluginController::loadPlugins()
{
    bool flagLoadSucess = true;
    QDir pluginsDir = QDir(qApp->applicationDirPath());

    #if defined(Q_OS_WIN)
        if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
            pluginsDir.cdUp();
    #elif defined(Q_OS_MAC)
        if (pluginsDir.dirName() == "MacOS") {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #endif
    pluginsDir.cd("plugins");

    IPlugin* plugin = 0;

    foreach (QString pluginFileName, pluginsDir.entryList(QDir::Files))
       {
           QPluginLoader loader(pluginsDir.absoluteFilePath(pluginFileName));
           plugin = dynamic_cast<IPlugin *>(loader.instance());
           if (plugin)
           {
               plugin->initialize(m_core);
               m_loadedPlugins->append(plugin);
           }
           else{
               flagLoadSucess = false;
           }
       }
    return flagLoadSucess;
}

QList<IPlugin*>* PluginController::loadedPlugins() const{
    return m_loadedPlugins;
}




