#include "deflatecompressionalgorithm.h"
#include <QObject>
#include <../EditorFrameworkInterfaces/iplugin.h>
#include <QByteArray>

DeflateCompressionAlgorithm::DeflateCompressionAlgorithm(QObject *parent):IPlugin(parent)
{
}

DeflateCompressionAlgorithm::~DeflateCompressionAlgorithm()
{

}

QByteArray DeflateCompressionAlgorithm::compress(const QByteArray &data) const
{
    return qCompress(data);
}

QByteArray DeflateCompressionAlgorithm::umcompress(const QByteArray &data) const
{
    return qUncompress(data);
}
