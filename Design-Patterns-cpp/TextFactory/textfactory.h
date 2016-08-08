#ifndef TEXTFACTORY_H
#define TEXTFACTORY_H

#include "textfactory_global.h"
#include <../EditorFrameworkInterfaces/iabstractfactory.h>
#include <../EditorFrameworkInterfaces/iplugin.h>

class IEditor;
class IDocument;

class TEXTFACTORYSHARED_EXPORT TextFactory : public IPlugin,
                                             public IAbstractFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.EditorFrameworkInterfaces.IAbstractFactory" FILE "TextFactory.json")
    Q_INTERFACES(IAbstractFactory)


public:
    TextFactory(QObject *parent = 0);
    virtual ~TextFactory();
    virtual bool initialize(ICore *core);
    virtual IEditor* createEditor() const Q_DECL_OVERRIDE;
    virtual IDocument* createDocument() const Q_DECL_OVERRIDE;
    virtual QString createSupportedExtensions() const Q_DECL_OVERRIDE;
};

#endif // TEXTFACTORY_H
