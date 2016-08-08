#include "textdocument.h"
#include <QString>
#include <QStringList>
#include <QFile>
#include <QIODevice>
#include <QBuffer>
#include <QTextStream>

TextDocument::TextDocument():m_text(new QStringList)
{

}

TextDocument::~TextDocument()
{
    delete m_text;
}

bool TextDocument::open(QString fileName)
{
    m_text->clear();

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    while (!out.atEnd())
    {
        QString line = out.readLine();
        m_text->append(line);
    }
    file.close();
    return true;
}

bool TextDocument::save()
{
    return false;
}

bool TextDocument::close()
{
    return false;
}

QStringList *TextDocument::text() const
{
    return m_text;
}

