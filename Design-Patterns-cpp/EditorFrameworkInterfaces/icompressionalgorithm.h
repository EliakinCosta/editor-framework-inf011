#ifndef ICOMPRESSIONALGORITHM_H
#define ICOMPRESSIONALGORITHM_H

#include "editorframeworkinterfaces_global.h"
#include <QtCore/QObject>

class QByteArray;

class EDITORFRAMEWORKINTERFACESSHARED_EXPORT ICompressionAlgorithm
{
public:
    ICompressionAlgorithm();
    virtual ~ICompressionAlgorithm(){}
    virtual QByteArray compress(const QByteArray &data) const = 0;
    virtual QByteArray umcompress(const QByteArray &data) const = 0;
};

Q_DECLARE_INTERFACE(ICompressionAlgorithm, "org.qt-project.EditorFrameworkInterfaces.ICompressionAlgorithm")

#endif // ICOMPRESSIONALGORITHM_H
