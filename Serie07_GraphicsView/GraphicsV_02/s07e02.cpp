#include <QtWidgets>
#include "s07e02.h"

S07E02::S07E02(QWidget *parent) : QGraphicsView(parent) {
    nbLines = 0;
    zoom = 1.0;
    angle = 0;

    setWindowTitle(tr("Lignes avec QGRaphicsView"));
//    resize(800, 600);
    setFixedSize(800, 800);

    scene = new QGraphicsScene;
    setScene(scene);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    drawAxis();
    applyTransform();
}

void S07E02::drawAxis() {
    scene->addLine(0., 0., 100., 0., QPen(Qt::red));
    scene->addLine(0., 0., 0., 100., QPen(Qt::green));

    txtNbLines = scene->addText(
        QString("Zoom%1, Lignes:%2").arg(zoom).arg(nbLines)
    );
    txtNbLines->setPos(0, 20);
    txtNbLines->setTransform(QTransform::fromScale(1., -1.));

    txtPhysicalCoords = scene->addText(
        QString("Coordonnées physiques: (%1, %2)").arg(0).arg(0)
    );
    txtPhysicalCoords->setPos(0, 35);
    txtPhysicalCoords->setTransform(QTransform::fromScale(1., -1.));

    txtLogicalCoords = scene->addText(
        QString("Coordonnées logiques: (%1, %2").arg(0).arg(0)
    );
    txtLogicalCoords->setPos(0, 50);
    txtLogicalCoords->setTransform(QTransform::fromScale(1., -1.));
}

void S07E02::keyReleaseEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Space) {
        zoom = 1.0;
        angle = 0;
        applyTransform();
    }
}

void S07E02::mousePressEvent(QMouseEvent *e) {
    if (e->buttons() == Qt::LeftButton) {
        startPoint = e->pos();
    }
}

void S07E02::mouseMoveEvent(QMouseEvent *e) {
    if (e->buttons() == Qt::LeftButton) {
        draw(e);
    }
    else if (e->buttons() == Qt::RightButton) {
        angle = (angle + (posRot.y() > e->pos().y() ? 10 : -10)) % 360;
        posRot = e->pos();
        applyTransform();
    }
}

void S07E02::applyTransform() {
    setSceneRect(-width() / 2., -height() / 2., width(), height());
    resetMatrix();
    scale(zoom, -zoom);
    rotate(angle);

    txtNbLines->setPlainText(
        QString("Zoom:%1, Lignes:%2").arg(zoom).arg(nbLines)
    );
}

void S07E02::draw(QMouseEvent *e) {
    endPoint = e->pos();
    QPen pen(Qt::blue);
    scene->addLine(QLineF(mapToScene(startPoint), mapToScene(endPoint)), pen);
    ++nbLines;
    updateText();
    startPoint = endPoint;
}

void S07E02::updateText() {
    auto s1 = QString("Zoom:%1, Lignes:%2");
    auto s2 = QString("Coordonnées physiques: (%1, %2)");
    auto s3 = QString("Coordonnées logiques: (%1, %2)");

    txtNbLines->setPlainText(
        s1.arg(zoom).arg(nbLines)
    );
    txtPhysicalCoords->setPlainText(
        s2.arg(endPoint.rx()).arg(endPoint.ry())
    );
    txtLogicalCoords->setPlainText(
        s3.arg(mapToScene(endPoint).rx()).arg(mapToScene(endPoint).ry())
    );
}

void S07E02::resizeEvent(QResizeEvent *e) {
    applyTransform();
}

void S07E02::wheelEvent(QWheelEvent *e) {
    zoom += e->angleDelta().y() > 0 ? 0.1 : -0.1;
    zoom = static_cast<float>(zoom < 0.3 ? 0.3 : zoom);
    zoom = zoom > 9 ? 9 : zoom;
    applyTransform();
}






