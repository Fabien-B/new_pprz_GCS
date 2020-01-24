#ifndef MAP2D_H
#define MAP2D_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QGraphicsTextItem>

class Map2D : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Map2D(QWidget *parent = nullptr);

signals:

public slots:

protected:
    virtual void wheelEvent(QWheelEvent* event);

private slots:
    void acChanged(int);

private:
    QGraphicsScene* scene;
    QGraphicsTextItem* current_ac;
};

#endif // MAP2D_H
