#ifndef IMAGEDOCUMENT_H
#define IMAGEDOCUMENT_H

#include <../EditorFrameworkInterfaces/idocument.h>
#include <QPixmap>

class ImageDocument: public IDocument
{
public:
    ImageDocument();
    virtual ~ImageDocument();
    virtual bool open(QString fileName);
    virtual bool save();
    virtual bool close();
    QPixmap* image() const;
private:
    QPixmap* m_image;

};

#endif // IMAGEDOCUMENT_H
