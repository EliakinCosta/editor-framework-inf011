#ifndef DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H

#include <../EditorFrameworkInterfaces/idocumentcontroller.h>

class IDocument;

class DocumentController:public IDocumentController
{
public:
    DocumentController();
    virtual ~DocumentController(){}
    virtual void setActiveDocument(IDocument *document);
    virtual IDocument *activeDocument();
};

#endif // DOCUMENTCONTROLLER_H
