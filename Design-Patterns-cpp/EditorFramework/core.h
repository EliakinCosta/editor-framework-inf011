#ifndef CORE_H
#define CORE_H

#include <../EditorFrameworkInterfaces/icore.h>

class IUiController;
class IDocumentController;
class IPluginController;

class Core : public ICore
{
public:
<<<<<<< HEAD
=======
    static Core* getInstance();
>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b
    virtual ~Core();
    virtual IUiController* uiController() const;
    virtual IDocumentController* documentController() const;
    virtual IPluginController* pluginController() const;
    static Core* getInstance();

private:
    Core();
<<<<<<< HEAD
=======
    static Core* m_singleton;
>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b
    IUiController* m_uiController;
    IDocumentController* m_documentController;
    IPluginController* m_pluginController;
    static Core *m_singleton;
};


#endif // CORE_H
