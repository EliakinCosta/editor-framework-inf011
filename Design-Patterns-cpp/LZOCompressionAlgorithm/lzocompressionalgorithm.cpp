#include "lzocompressionalgorithm.h"


LZOCompressionAlgorithm::LZOCompressionAlgorithm(QObject *parent):IPlugin(parent)
{
}


QByteArray LZOCompressionAlgorithm::compress(const QByteArray &data) const
{
    return qCompress(data);
}

QByteArray LZOCompressionAlgorithm::umcompress(const QByteArray &data) const
{
    return qUncompress(data);
}
