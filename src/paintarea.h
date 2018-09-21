#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QtGui>


class PaintArea : public QWidget
{
    Q_OBJECT

public:
    PaintArea(QWidget *parent = 0);
    ~PaintArea(){}
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clear();
    void print();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(const QSize &newSize);
    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
    QBrush background;
};

#endif // PAINTAREA_H
