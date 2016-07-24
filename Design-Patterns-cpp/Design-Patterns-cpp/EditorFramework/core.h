#ifndef CORE_H
#define CORE_H


#include <../EditorFrameworkInterfaces/icore.h>

class IUiController;
class IDocumentController;

class Core : public ICore
{
public:
    Core();
    ~Core();
    virtual IUiController *uiController() const;
    virtual IDocumentController *documentController() const;

private:
    IUiController *m_uiController;
    IDocumentController *m_documentController;
};


#endif // CORE_H
