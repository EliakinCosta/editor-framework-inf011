#ifndef IABSTRACTFACTORY_H
#define IABSTRACTFACTORY_H

#include "editorframeworkinterfaces_global.h"
#include <QtCore/QObject>

class IEditor;
class IDocument;
class QString;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IAbstractFactory
{
public:
    IAbstractFactory();
    virtual ~IAbstractFactory();
    virtual IEditor* createEditor() const = 0;
    virtual IDocument* createDocument() const = 0;
    virtual QString createSupportedExtensions() const = 0;
};

Q_DECLARE_INTERFACE(IAbstractFactory, "org.qt-project.EditorFrameworkInterfaces.IAbstractFactory")

#endif // IABSTRACTFACTORY_H
