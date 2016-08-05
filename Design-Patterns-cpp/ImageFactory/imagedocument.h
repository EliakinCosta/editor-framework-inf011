#ifndef IMAGEDOCUMENT_H
#define IMAGEDOCUMENT_H

#include <../EditorFrameworkInterfaces/idocument.h>
#include <../EditorFrameworkInterfaces/iprototype.h>
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>
#include <QPixmap>
#include <QByteArray>

class ImageDocument: public IDocument,
                     public IPrototype
{
public:
    ImageDocument();
    ImageDocument(ImageDocument &prototype);
    virtual ~ImageDocument();
    virtual bool open(QString fileName);
    virtual bool save();
    virtual bool close();
    virtual bool compress();
    virtual bool uncompress();
    QPixmap* image() const;
    virtual IPrototype *clone();
private:
    QString m_fileName;
    QPixmap* m_image;
    QByteArray m_imageByteArray;
    QString m_fileExtension;
};

#endif // IMAGEDOCUMENT_H
