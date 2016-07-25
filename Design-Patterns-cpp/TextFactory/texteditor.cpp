#include "texteditor.h"
#include "textdocument.h"
#include <QTextEdit>
#include <QString>

QWidget *TextEditor::view() const
{
    QTextEdit *view = new QTextEdit();
    foreach (QString line, *dynamic_cast<TextDocument *>(m_document)->text())
        view->append(line + "\n");

    return view;
}
