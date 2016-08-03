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
    m_prototypes.insert("Editor", new ImageEditor);
    m_prototypes.insert("Document", new ImageDocument);
    return true;
}

IPrototype *ImageFactory::create(QString namePrototype) const
{
    if(m_prototypes.contains(namePrototype))
    {
        return m_prototypes[namePrototype]->clone();
    }
}
