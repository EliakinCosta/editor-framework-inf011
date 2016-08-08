#ifndef IDOCUMENTCONTROLLER_H
#define IDOCUMENTCONTROLLER_H

#include "editorframeworkinterfaces_global.h"

class IDocument;
class QString;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IDocumentController
{
public:
    IDocumentController();
    virtual ~IDocumentController(){}
    virtual void setActiveDocument(IDocument *document) = 0;
    virtual IDocument *activeDocument() = 0;
protected:
    IDocument *m_activeDocument;
};

#endif // IDOCUMENTCONTROLLER_H
