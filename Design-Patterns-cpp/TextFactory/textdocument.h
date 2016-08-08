#ifndef TEXTDOCUMENT_H
#define TEXTDOCUMENT_H

#include <../EditorFrameworkInterfaces/idocument.h>
#include <QStringList>

class TextDocument: public IDocument
{
public:
    TextDocument();
    virtual ~TextDocument();
    virtual bool open(QString fileName);
    virtual bool save();
    virtual bool close();
    QStringList* text() const;
private:
    QStringList* m_text;
};

#endif // TEXTDOCUMENT_H
