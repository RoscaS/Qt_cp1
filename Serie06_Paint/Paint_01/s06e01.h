#pragma once

#include <QWidget>

class S06E01 : public QWidget {
    Q_OBJECT

public:
    explicit S06E01(QWidget* parent=nullptr);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QPainter *painter;
    QPixmap *pixmap;
    QImage *image;
};

