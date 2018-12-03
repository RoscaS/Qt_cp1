#pragma once

#include <QGraphicsView>

class S07E02 : public QGraphicsView {
Q_OBJECT

public:
    explicit S07E02(QWidget *parent = nullptr);
    void applyTransform();
    void drawAxis();

protected:
    void keyReleaseEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void resizeEvent(QResizeEvent *e) override;
    void wheelEvent(QWheelEvent *e) override;

private:
    void draw(QMouseEvent *e);
    void updateText();

    QGraphicsTextItem *txtLogicalCoords;
    QGraphicsTextItem *txtPhysicalCoords;
    QGraphicsTextItem *txtNbLines;

    QGraphicsScene *scene;

    QPoint startPoint, endPoint, posRot;

    int nbLines;
    float zoom;
    int angle;

};
