#include "imagedocument.h"
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>
#include <QPixmap>
#include <QFile>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>

ImageDocument::ImageDocument():m_image(new QPixmap)
{

}

ImageDocument::ImageDocument(ImageDocument &prototype):m_image(new QPixmap)
{
    this->m_image = prototype.m_image;
}

ImageDocument::~ImageDocument()
{
    delete m_image;
}

QPixmap* ImageDocument::image() const{
    return m_image;
}

bool ImageDocument::open(QString fileName)
{
    m_fileName = fileName;
    m_image->load(m_fileName);
    if (m_image->isNull())
        return false;

    QBuffer buffer(&m_imageByteArray);
    buffer.open(QIODevice::WriteOnly);
    m_fileExtension = m_fileName.split(".").at(1);
    m_image->save(&buffer, m_fileExtension.toUtf8().constData());

    return true;
}
bool ImageDocument::save()
{

}

bool ImageDocument::close()
{

}


bool ImageDocument::compress()
{
    if(m_compressionAlgorithm)
    {
        m_imageByteArray = m_compressionAlgorithm->compress(m_imageByteArray);

        QFile compressedFile(m_fileName);
        compressedFile.open(QIODevice::WriteOnly);
        compressedFile.write(m_imageByteArray);
        compressedFile.close();
        return true;
    }
    return false;
}
bool ImageDocument::uncompress()
{
    if(m_compressionAlgorithm)
    {

        return true;
    }
    return false;
}

IPrototype *ImageDocument::clone()
{
    return new ImageDocument(*this);
}
