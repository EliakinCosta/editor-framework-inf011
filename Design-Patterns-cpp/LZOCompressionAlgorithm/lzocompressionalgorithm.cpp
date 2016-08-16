#include "lzocompressionalgorithm.h"
#include <LZO/qtlzo.h>
#include <QByteArray>

LZOCompressionAlgorithm::LZOCompressionAlgorithm(QObject *parent):IPlugin(parent)
{

}

LZOCompressionAlgorithm::~LZOCompressionAlgorithm()
{
}


QByteArray LZOCompressionAlgorithm::compress(const QByteArray &data) const
{
    QByteArray image;
    ToLZO(data, image);
    return image;
}

QByteArray LZOCompressionAlgorithm::umcompress(const QByteArray &data) const
{
    QByteArray image;
    FromLZO(data, image);
    return image;
}
