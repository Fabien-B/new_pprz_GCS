#include "map2d.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <string>
#include "pprz_dispatcher.h"
#include "ui_dispatcher.h"

#define SIZE 10000

/*
 * Fake map just for illustration.
 *
 *
 */

Map2D::Map2D(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(0,0, 2*SIZE, 2*SIZE, parent);
    setScene(scene);
    QPixmap pixmap = QPixmap("://fake_map.png");
    QGraphicsPixmapItem *pixmapItem = scene->addPixmap(pixmap);
    pixmapItem->setPos(SIZE - pixmapItem->boundingRect().width()/2, SIZE - pixmapItem->boundingRect().height()/2);

    current_ac = new QGraphicsTextItem("AC : None");
    current_ac->setScale(4);
    scene->addItem(current_ac);
    current_ac->setPos(SIZE, SIZE);

    setDragMode(QGraphicsView::ScrollHandDrag);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setBackgroundBrush(QBrush(Qt::darkGreen));

    connect(UiDispatcher::get(), SIGNAL(ac_selected(int)), this, SLOT(acChanged(int)));
}


void Map2D::wheelEvent(QWheelEvent* event) {
    setTransformationAnchor(QGraphicsView::NoAnchor);
    qreal zoomFactor = 1.25;
    if(event->delta() < 0) {
        zoomFactor = 1/zoomFactor;
    }

    QPointF oldPos = mapToScene(event->pos());

    scale(zoomFactor, zoomFactor);

    QPointF newPos = mapToScene(event->pos());
    QPointF delta = newPos - oldPos;
    translate(delta.x(), delta.y());
}

void Map2D::acChanged(int ac_id) {
    current_ac->setPlainText("AC : " + QString::number(ac_id));
}
