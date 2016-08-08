#ifndef IEDITOR_H
#define IEDITOR_H

#include "editorframeworkinterfaces_global.h"

class QWidget;
class IDocument;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IEditor
{
public:
    IEditor(){}
    virtual ~IEditor();
    void setDocument(IDocument *document);
    virtual QWidget *view() const = 0;

protected:
    IDocument *m_document;

};
#endif // IEDITOR_H
