#include "imageeditor.h"
#include "imagedocument.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtGui>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>

ImageEditor::ImageEditor(ImageEditor &prototype)
{
    //copia de atributos se houvesse
}

QWidget* ImageEditor::view() const{
    QLabel *imageLabel = new QLabel;;
    QScrollArea *scrollArea = new QScrollArea;
    imageLabel->setPixmap(*dynamic_cast<ImageDocument *>(this->m_document)->image());
    scrollArea->setWidget(imageLabel);
    return scrollArea;
}


IPrototype *ImageEditor::clone()
{
    return new ImageEditor(*this);
}
