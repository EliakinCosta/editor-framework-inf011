#ifndef LZOCOMPRESSIONALGORITHM_H
#define LZOCOMPRESSIONALGORITHM_H

#include "lzocompressionalgorithm_global.h"
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>

class QtLzo;

class LZOCOMPRESSIONALGORITHMSHARED_EXPORT LZOCompressionAlgorithm: public IPlugin,
                                                                    public ICompressionAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.EditorFrameworkInterfaces.ICompressionAlgorithm" FILE "LZOCompressionAlgorithm.json")
    Q_INTERFACES(ICompressionAlgorithm)
public:
    LZOCompressionAlgorithm(QObject *parent = 0);
    virtual ~LZOCompressionAlgorithm();
    virtual QByteArray compress(const QByteArray &data) const;
    virtual QByteArray umcompress(const QByteArray &data) const;
    virtual bool initialize(ICore *core){}
private:
    QtLzo *m_lzoCompressor;
    QByteArray *m_lzoData;
    QByteArray *m_sourceData;
};

#endif // LZOCOMPRESSIONALGORITHM_H
