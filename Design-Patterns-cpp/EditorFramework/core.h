#ifndef CORE_H
#define CORE_H

#include <../EditorFrameworkInterfaces/icore.h>

class IUiController;
class IDocumentController;
class IPluginController;

class Core : public ICore
{
public:
    virtual ~Core();
    virtual IUiController* uiController() const;
    virtual IDocumentController* documentController() const;
    virtual IPluginController* pluginController() const;
    static Core* getInstance();

private:
    Core();
    IUiController* m_uiController;
    IDocumentController* m_documentController;
    IPluginController* m_pluginController;
    static Core *m_singleton;
};


#endif // CORE_H
