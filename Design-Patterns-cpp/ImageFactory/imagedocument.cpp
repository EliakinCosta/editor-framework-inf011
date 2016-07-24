#include "imagedocument.h"
#include <QPixmap>

ImageDocument::ImageDocument()
{

}

ImageDocument::~ImageDocument()
{
    delete m_image;
}

QImage* ImageDocument::image() const{
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
