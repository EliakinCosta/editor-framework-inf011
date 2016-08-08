#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <../EditorFrameworkInterfaces/ieditor.h>
#include <../EditorFrameworkInterfaces/iprototype.h>

class QWidget;

class ImageEditor: public IEditor,
                   public IPrototype
{
public:
    ImageEditor(){}
    ImageEditor(ImageEditor &prototype);
    virtual ~ImageEditor(){}
    virtual QWidget* view() const;
    virtual IPrototype *clone();
};

#endif // IMAGEEDITOR_H
