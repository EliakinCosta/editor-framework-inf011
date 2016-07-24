#ifndef DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H

#include <../EditorFrameworkInterfaces/idocumentcontroller.h>

class IDocument;

class DocumentController:public IDocumentController
{
public:
    DocumentController();
    virtual ~DocumentController(){}
};

#endif // DOCUMENTCONTROLLER_H
