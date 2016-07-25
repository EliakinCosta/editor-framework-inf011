#include "textfactory.h"
#include <../EditorFrameworkInterfaces/ieditor.h>
#include <../EditorFrameworkInterfaces/idocument.h>
#include "texteditor.h"
#include "textdocument.h"
#include <QObject>


TextFactory::TextFactory(QObject *parent):IPlugin(parent)
{
}

TextFactory::~TextFactory()
{
}

bool TextFactory::initialize(ICore *core){
    return true;
}

IEditor* TextFactory::createEditor() const{
    return new TextEditor;
}

IDocument* TextFactory::createDocument() const{
    return new TextDocument;
}

QString TextFactory::createSupportedExtensions() const{
    return tr("Image Files (*.txt)");
}
