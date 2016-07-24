#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H

#include "imagefactory_global.h"
#include <../EditorFrameworkInterfaces/iabstractfactory.h>
#include <../EditorFrameworkInterfaces/iplugin.h>

class IEditor;
class IDocument;

class IMAGEFACTORYSHARED_EXPORT ImageFactory : public IPlugin,
                     public IAbstractFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.EditorFrameworkInterfaces.IAbstractFactory" FILE "ImageFactory.json")
    Q_INTERFACES(IAbstractFactory)


public:
    ImageFactory(QObject *parent = 0);
    virtual ~ImageFactory();
    virtual bool initialize(ICore *core);
    virtual IEditor* createEditor() const Q_DECL_OVERRIDE;
    virtual IDocument* createDocument() const Q_DECL_OVERRIDE;
    virtual QString createSupportedExtensions() const Q_DECL_OVERRIDE;
};

#endif // IMAGEFACTORY_H
