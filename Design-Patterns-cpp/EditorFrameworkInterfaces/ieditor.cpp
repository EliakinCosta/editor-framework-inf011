#include "ieditor.h"
#include "idocument.h"

IEditor::~IEditor()
{
    delete m_document;
}

void IEditor::setDocument(IDocument *document)
{
    m_document = document;
}
