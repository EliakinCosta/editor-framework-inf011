#ifndef IMAGEDOCUMENT_H
#define IMAGEDOCUMENT_H

#include <../EditorFrameworkInterfaces/idocument.h>

class QImage;

class ImageDocument: public IDocument
{
public:
    ImageDocument();
    virtual ~ImageDocument();
    virtual bool open(QString fileName);
    virtual bool save();
    virtual bool close();
    QImage* image() const;
private:
    QImage* m_image;

};

#endif // IMAGEDOCUMENT_H
