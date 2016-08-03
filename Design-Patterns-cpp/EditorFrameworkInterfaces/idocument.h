#ifndef IDOCUMENT_H
#define IDOCUMENT_H

#include "editorframeworkinterfaces_global.h"
#include "icompressionalgorithm.h"

class QString;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT IDocument
{
public:
    IDocument();
    virtual ~IDocument();
    virtual bool open(QString fileName) = 0;
    virtual bool save() = 0;
    virtual bool close() = 0;
    virtual bool compress() = 0;
    virtual bool uncompress() = 0;
protected:
    virtual void setCompressionAlgorithm(ICompressionAlgorithm *compressionAlgorithm) = 0;
private:
    ICompressionAlgorithm compressionAlgorithm;
};

#endif // IDOCUMENT_H
