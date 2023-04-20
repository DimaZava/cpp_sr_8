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
    DrawView(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void updateConfiguration(DrawViewConfiguration configuration);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    DrawViewConfiguration _configuration;
};

#endif // DRAWVIEW_H
