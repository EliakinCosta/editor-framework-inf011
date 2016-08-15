#include "lzocompressionalgorithm.h"

LZOCompressionAlgorithm::LZOCompressionAlgorithm(QObject *parent):IPlugin(parent)
{

}

LZOCompressionAlgorithm::~LZOCompressionAlgorithm()
{
    delete m_lzoData;
    delete m_sourceData;
}


QByteArray LZOCompressionAlgorithm::compress(const QByteArray &data) const
{
    QByteArray t;
    return *m_lzoData;
}

QByteArray LZOCompressionAlgorithm::umcompress(const QByteArray &data) const
{
    return *m_sourceData;
}
