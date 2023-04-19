#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPixmap>

#include "drawviewconfiguration.h"

class DrawView: public QWidget
{
    Q_OBJECT

public:
    DrawView(DrawViewConfiguration config, QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setShape(DrawViewConfiguration::Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    DrawViewConfiguration configuration;
};

#endif // DRAWVIEW_H
