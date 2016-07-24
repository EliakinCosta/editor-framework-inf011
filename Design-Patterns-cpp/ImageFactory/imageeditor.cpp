#include "imageeditor.h"
#include "imagedocument.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtGui>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>

QWidget* ImageEditor::view() const{
    QPixmap image = QPixmap::fromImage(*dynamic_cast<ImageDocument *>(this->m_document)->image());
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(image);

    QGraphicsView* view = new QGraphicsView(scene);

    return view;
}
