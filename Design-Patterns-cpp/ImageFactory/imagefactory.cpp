#include "imagefactory.h"
#include <../EditorFrameworkInterfaces/ieditor.h>
#include <../EditorFrameworkInterfaces/idocument.h>
#include "imageeditor.h"
#include "imagedocument.h"
#include <QObject>


ImageFactory::ImageFactory(QObject *parent):IPlugin(parent)
{
}

ImageFactory::~ImageFactory()
{
}

bool ImageFactory::initialize(ICore *core){
    return true;
}

IEditor* ImageFactory::createEditor() const{
    return new ImageEditor;
}

IDocument* ImageFactory::createDocument() const{
    return new ImageDocument;
}

QString ImageFactory::createSupportedExtensions() const{
    return tr("Image Files (*.png *.jpg *.bmp)");
}
