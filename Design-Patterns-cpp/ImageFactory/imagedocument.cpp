#include "imagedocument.h"
#include <QPixmap>

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
    m_image->load(fileName);
    if (m_image->isNull())
        return false;
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
    return true;
}
bool ImageDocument::uncompress()
{
    return true;
}

IPrototype *ImageDocument::clone()
{
    return new ImageDocument(*this);
}

void ImageDocument::setCompressionAlgorithm(ICompressionAlgorithm *compressionAlgorithm)
{

}
