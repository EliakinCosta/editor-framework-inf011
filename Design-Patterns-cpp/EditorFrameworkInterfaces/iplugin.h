#ifndef IPLUGIN_H
#define IPLUGIN_H

#include "editorframeworkinterfaces_global.h"
#include <QObject>

class ICore;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IPlugin: public QObject
{
public:
    IPlugin(QObject* parent = 0);
    virtual ~IPlugin(){}
    virtual bool initialize(ICore* core) = 0;
};

#endif // IPLUGIN_H
