#include "lzocompressionalgorithm.h"
#include <../libs/QtLzo/QtLzo>

LZOCompressionAlgorithm::LZOCompressionAlgorithm(QObject *parent):IPlugin(parent)
{
}

LZOCompressionAlgorithm::~LZOCompressionAlgorithm()
{
    delete m_lzoCompressor;
    delete m_lzoData;
    delete m_sourceData;
}


QByteArray LZOCompressionAlgorithm::compress(const QByteArray &data) const
{
    ToLZO(data, *m_lzoData);
    return *m_lzoData;
}

QByteArray LZOCompressionAlgorithm::umcompress(const QByteArray &data) const
{
    FromLZO(data, *m_sourceData);
    return *m_sourceData;
}
