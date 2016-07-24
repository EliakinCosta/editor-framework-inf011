#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <../EditorFrameworkInterfaces/ieditor.h>

class QWidget;

class ImageEditor: public IEditor
{
public:
    ImageEditor(){}
    virtual ~ImageEditor(){}
    virtual QWidget* view() const;
};

#endif // IMAGEEDITOR_H
