#include "documentcontroller.h"

DocumentController::DocumentController()
{

}

void DocumentController::setActiveDocument(IDocument *document)
{
    m_activeDocument = document;
}
IDocument *DocumentController::activeDocument()
{
    return m_activeDocument;
}
