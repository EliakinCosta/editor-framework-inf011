#include "core.h"
#include "uicontroller.h"
#include "documentcontroller.h"
#include "plugincontroller.h"

<<<<<<< HEAD
Core* Core::m_singleton = 0;

=======

Core* Core::m_singleton = 0;


>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b
Core::Core() : m_uiController(new UiController(this)),
               m_documentController(new DocumentController),
               m_pluginController(new PluginController(this))
{
}

Core::~Core()
{
    delete m_uiController;
    delete m_documentController;
    delete m_pluginController;
}

IUiController *Core::uiController() const
{
    return m_uiController;
}

IDocumentController *Core::documentController() const
{
    return m_documentController;
}

IPluginController *Core::pluginController() const
{
    return m_pluginController;
}

<<<<<<< HEAD
Core *Core::getInstance(){
    if(!m_singleton)
       m_singleton = new Core;
=======

Core* Core::getInstance(){
    if (!m_singleton){
        m_singleton = new Core;
    }
>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b
    return m_singleton;
}
