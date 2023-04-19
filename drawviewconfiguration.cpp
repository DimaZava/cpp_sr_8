#include "drawviewconfiguration.h"

DrawViewConfiguration::DrawViewConfiguration()
{
}

DrawViewConfiguration DrawViewConfiguration::makeDefault()
{
    DrawViewConfiguration config = DrawViewConfiguration();
    config.shape = Polygon;

    config.brushColor = QColor(Qt::red);
    config.brushStyle = Qt::SolidPattern;
    config.brush = QBrush(config.brushColor, config.brushStyle);

    config.penWidth = 2;
    config.penStyle = Qt::SolidLine;
    config.penCap = Qt::SquareCap;
    config.penJoin = Qt::BevelJoin;

    config.pen = QPen(config.brush, config.penWidth, config.penStyle, config.penCap, config.penJoin);

    config.antialiased = false;
    config.transformed = false;

    return config;
}
