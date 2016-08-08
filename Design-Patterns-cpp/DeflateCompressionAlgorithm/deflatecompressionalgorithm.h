#ifndef DEFLATECOMPRESSIONALGORITHM_H
#define DEFLATECOMPRESSIONALGORITHM_H

#include "deflatecompressionalgorithm_global.h"
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>

class QByteArray;
class QObject;

class DEFLATECOMPRESSIONALGORITHMSHARED_EXPORT DeflateCompressionAlgorithm: public IPlugin,
                                                                            public ICompressionAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.EditorFrameworkInterfaces.ICompressionAlgorithm" FILE "DeflateCompressionAlgorithm.json")
    Q_INTERFACES(ICompressionAlgorithm)
public:
    DeflateCompressionAlgorithm(QObject *parent = 0);
    virtual ~DeflateCompressionAlgorithm();
    virtual QByteArray compress(const QByteArray &data) const;
    virtual QByteArray umcompress(const QByteArray &data) const;
    virtual bool initialize(ICore *core){}
};

#endif // DEFLATECOMPRESSIONALGORITHM_H
