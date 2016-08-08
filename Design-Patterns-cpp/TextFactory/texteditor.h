#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <../EditorFrameworkInterfaces/ieditor.h>

class TextEditor: public IEditor
{
public:
    TextEditor(){}
    virtual ~TextEditor(){}
    virtual QWidget* view() const;
};

#endif // TEXTEDITOR_H
