#ifndef ICORE_H
#define ICORE_H

#include "editorframeworkinterfaces_global.h"

class IUiController;
class IPluginController;
class IDocumentController;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT ICore
{

public:
    ICore();
    virtual ~ICore(){}
    virtual IUiController* uiController() const = 0;
    virtual IDocumentController* documentController() const = 0;
    virtual IPluginController* pluginController() const = 0;
};

#endif // ICORE_H
