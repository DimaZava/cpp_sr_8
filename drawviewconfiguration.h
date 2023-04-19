#ifndef DRAWVIEWCONFIGURATION_H
#define DRAWVIEWCONFIGURATION_H

#include <QBrush>
#include <QPen>
#include <QPixmap>

class DrawViewConfiguration
{
public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap };

    static DrawViewConfiguration makeDefault();

    DrawViewConfiguration();

    Shape shape;

    QBrush brush;
    QColor brushColor;
    Qt::BrushStyle brushStyle;

    QPen pen;

    qreal penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCap;
    Qt::PenJoinStyle penJoin;

    bool antialiased;
    bool transformed;
};

#endif // DRAWVIEWCONFIGURATION_H
