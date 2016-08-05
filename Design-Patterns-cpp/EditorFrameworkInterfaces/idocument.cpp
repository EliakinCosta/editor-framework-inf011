#include "idocument.h"

IDocument::IDocument()
{

}

IDocument::~IDocument(){
    delete m_compressionAlgorithm;
}


void IDocument::setCompressionAlgorithm(ICompressionAlgorithm *compressionAlgorithm)
{
    m_compressionAlgorithm = compressionAlgorithm;
}
