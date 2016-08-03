#ifndef IMAGEDOCUMENT_H
#define IMAGEDOCUMENT_H

#include <../EditorFrameworkInterfaces/idocument.h>
#include <../EditorFrameworkInterfaces/iprototype.h>
#include <../EditorFrameworkInterfaces/icompressionalgorithm.h>
#include <QPixmap>

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
    virtual void setCompressionAlgorithm(ICompressionAlgorithm *compressionAlgorithm);
    QPixmap* image() const;
    virtual IPrototype *clone();
private:
    QPixmap* m_image;
};

#endif // IMAGEDOCUMENT_H
