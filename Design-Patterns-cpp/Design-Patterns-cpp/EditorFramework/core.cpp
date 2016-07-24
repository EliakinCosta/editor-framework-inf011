#include "core.h"
#include "uicontroller.h"
#include "documentcontroller.h"

Core::Core() :
    m_uiController(new UiController(this)),
    m_documentController(new DocumentController)
{
}

Core::~Core()
{
    delete m_uiController;
    delete m_documentController;
}

IUiController *Core::uiController() const
{
    return m_uiController;
}

IDocumentController *Core::documentController() const
{
    return m_documentController;
}
