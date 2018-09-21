#include <QtGui>
#include"paintarea.h"

PaintArea::PaintArea(QWidget *parent)
    : QWidget(parent), modified(false)
{
    setAttribute(Qt::WA_StaticContents);
    background = QBrush(QColor(127, 127, 127));
    //this->resize(100, 100);

    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
    const QSize s(1000, 1000);
    this->resizeImage(s);
}

void PaintArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void PaintArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void PaintArea::mousePressEvent(QMouseEvent *event)
{
    //rozpocznij zczytywanie do mousegesturerecognizer
    if(event->button() == Qt::RightButton)
    {
        lastPoint = event->pos();
        scribbling = true;
    }

}

void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}

void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling)
    {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), background);
    painter.save();
    painter.end();
}

void PaintArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void PaintArea::resizeImage(const QSize &newSize)
{
    if (image.size() == newSize) return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), image);
    image = newImage;
}

void PaintArea::clear()
{

}

void PaintArea::print()
{
}
