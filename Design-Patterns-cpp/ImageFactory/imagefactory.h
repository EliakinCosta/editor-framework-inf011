#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H

#include "imagefactory_global.h"
#include <../EditorFrameworkInterfaces/iabstractfactory.h>
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/iprototype.h>
#include <QMap>

using namespace std;

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
    virtual IPrototype *create(QString namePrototype) const;
private:
    QMap<QString, IPrototype*> m_prototypes;
};

#endif // IMAGEFACTORY_H
