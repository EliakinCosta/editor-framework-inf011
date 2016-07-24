#ifndef CORE_H
#define CORE_H

#include <../EditorFrameworkInterfaces/icore.h>

class IUiController;
class IDocumentController;
class IPluginController;

class Core : public ICore
{
public:
    Core();
    virtual ~Core();
    virtual IUiController* uiController() const;
    virtual IDocumentController* documentController() const;
    virtual IPluginController* pluginController() const;

private:
    IUiController* m_uiController;
    IDocumentController* m_documentController;
    IPluginController* m_pluginController;
};


#endif // CORE_H
