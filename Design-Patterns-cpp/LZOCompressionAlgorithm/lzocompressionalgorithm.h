#ifndef LZOCOMPRESSIONALGORITHM_H
#define LZOCOMPRESSIONALGORITHM_H

#include "lzocompressionalgorithm_global.h"
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>
#include <QtLzo>

class QByteArray;
class QObject;

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
    QByteArray *m_lzoData;
    QByteArray *m_sourceData;
    QtLzo teste;
};


#endif // LZOCOMPRESSIONALGORITHM_H
