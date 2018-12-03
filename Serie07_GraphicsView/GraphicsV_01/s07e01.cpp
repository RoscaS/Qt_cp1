#include <QtWidgets>

#include "s07e01.h"

S07E01::S07E01(QWidget *parent) : QGraphicsView(parent) {
    setFixedSize(800, 800);

    QImage image("Smiley.jpg");

    scene = new QGraphicsScene(this);
    setScene(scene);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Line
    line = new QGraphicsLineItem();
    scene->addItem(line);
    line->setZValue(-1);
    line->setFlag(QGraphicsItem::ItemIsMovable);
    line->setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue);
    auto *t1 = scene->addSimpleText(
        tr("Les différentes formes avec Qt et QGraphicsView")
    );

    t1->setPos(0, 0);
    t1->setBrush(brush);

    // Slice
    auto *ellipse = scene->addEllipse(
        10, 40, 200, 100, QPen(), QBrush(Qt::blue)
    );
    ellipse->setStartAngle(30 * 16);
    ellipse->setSpanAngle(120 * 16);

    // Rect
    scene->addRect(10, 100, 200, 100, QPen(), QBrush(Qt::red));

    // Polygon
    auto *polygon = scene->addPolygon(
        QPolygonF(QVector< QPointF >{
            QPointF(110., 280.),
            QPointF(120., 210.),
            QPointF(180., 230.),
            QPointF(190., 270.)
        }),
        QPen(),
        QBrush(Qt::red)
    );

    //QPixmap
    auto *itemPixmap = scene->addPixmap(
        QPixmap("Smiley.jpg").scaled(QSize(50, 50))
    );
    itemPixmap->setPos(10, 280);

    // QImage
    auto *itemPixmapFromImage = scene->addPixmap(
        QPixmap(QPixmap::fromImage(
            QImage("Smiley.jpg").scaled(QSize(50, 50))
                )
        ));
    itemPixmapFromImage->setPos(10, 350);

    // Round rect
    QPainterPath path;
    path.addRoundedRect(10, 420, 200, 100, 20.0, 20.0);
    scene->addPath(path, QPen(), QBrush(Qt::yellow));

    // Ellipse
    scene->addEllipse(10, 540, 100, 50, QPen(), QBrush(Qt::green));


    auto *t0 = scene->addSimpleText("addSimpleText");
    t0->setPos(400, 10);

    auto *t2 = scene->addSimpleText("addEllipse");
    t2->setPos(300,70);

    auto *t3 = scene->addSimpleText("addRect");
    t3->setPos(300, 170);

    auto *t4 = scene->addSimpleText("addPolygon");
    t4->setPos(300, 250);

    auto *t5 = scene->addSimpleText("addPixmap");
    t5->setPos(300, 300);

    auto *t6 = scene->addSimpleText("QPixmap::fromImage puis addPixmap");
    t6->setPos(300, 380);

    auto *t7 = scene->addSimpleText("path.addRoundedRect puis addPath");
    t7->setPos(300, 470);

    auto *t8 = scene->addSimpleText("addEllipse");
    t8->setPos(300, 570);

    auto *t9 = scene->addSimpleText("addLine");
    t9->setPos(530, 400);

    foreach(QGraphicsItem *item, scene->items()) {
        item->setFlag(QGraphicsItem::ItemIsMovable);
        item->setFlag(QGraphicsItem::ItemIsSelectable);
    }
}

void S07E01::resizeEvent(QResizeEvent *) {
    line->setLine(0, 0, width(), height());
}
