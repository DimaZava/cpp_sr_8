#include "drawview.h"
#include <QPainter>
#include <QPainterPath>

DrawView::DrawView(DrawViewConfiguration config, QWidget *parent)
    : QWidget(parent)
    , configuration(config)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize DrawView::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize DrawView::sizeHint() const
{
    return QSize(400, 200);
}

void DrawView::setShape(DrawViewConfiguration::Shape shape)
{
    this->configuration.shape = shape;
    update();
}

void DrawView::setPen(const QPen &pen)
{
    this->configuration.pen = pen;
    update();
}

void DrawView::setBrush(const QBrush &brush)
{
    this->configuration.brush = brush;
    update();
}

void DrawView::setAntialiased(bool antialiased)
{
    this->configuration.antialiased = antialiased;
    update();
}

void DrawView::setTransformed(bool transformed)
{
    this->configuration.transformed = transformed;
    update();
}

void DrawView::paintEvent(QPaintEvent * /* event */)
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;

    QPainter painter(this);
    painter.setPen(configuration.pen);
    painter.setBrush(configuration.brush);

    if (configuration.antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    QPoint center = QPoint(width() / 2, height() / 2);
    painter.save();
    painter.translate(center);

    if (configuration.transformed) {
        painter.translate(50, 50);
        painter.rotate(60.0);
        painter.scale(0.6, 0.9);
        painter.translate(-50, -50);
    }

    switch (configuration.shape) {
    case DrawViewConfiguration::Line:
        painter.drawLine(rect.bottomLeft(), rect.topRight());
        break;
    case DrawViewConfiguration::Points:
        painter.drawPoints(points, 4);
        break;
    case DrawViewConfiguration::Polyline:
        painter.drawPolyline(points, 4);
        break;
    case DrawViewConfiguration::Polygon:
        painter.drawPolygon(points, 4);
        break;
    case DrawViewConfiguration::Rect:
        painter.drawRect(rect);
        break;
    case DrawViewConfiguration::RoundedRect:
        painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
        break;
    case DrawViewConfiguration::Ellipse:
        painter.drawEllipse(rect);
        break;
    case DrawViewConfiguration::Arc:
        painter.drawArc(rect, startAngle, arcLength);
        break;
    case DrawViewConfiguration::Chord:
        painter.drawChord(rect, startAngle, arcLength);
        break;
    case DrawViewConfiguration::Pie:
        painter.drawPie(rect, startAngle, arcLength);
        break;
    case DrawViewConfiguration::Path:
    {
        QPainterPath path;
        path.moveTo(20, 80);
        path.lineTo(20, 30);
        path.cubicTo(80, 0, 50, 50, 80, 80);

        painter.drawPath(path);
        break;
    }
    case DrawViewConfiguration::Text:
        painter.drawText(rect,
                         Qt::AlignCenter,
                         tr("Qt by\nThe Qt Company"));
        break;
    case DrawViewConfiguration::Pixmap:
        //painter.drawPixmap(10, 10, pixmap);
        break;
    }

    painter.restore();

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
