#ifndef CORE_H
#define CORE_H

#include <../EditorFrameworkInterfaces/icore.h>

class IUiController;
class IDocumentController;
class IPluginController;

class Core : public ICore
{
public:
    static Core* getInstance();
    virtual ~Core();
    virtual IUiController* uiController() const;
    virtual IDocumentController* documentController() const;
    virtual IPluginController* pluginController() const;

private:
    Core();
    static Core* m_singleton;
    IUiController* m_uiController;
    IDocumentController* m_documentController;
    IPluginController* m_pluginController;
};


#endif // CORE_H
