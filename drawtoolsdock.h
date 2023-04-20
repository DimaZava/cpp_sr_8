#ifndef DRAWTOOLSDOCK_H
#define DRAWTOOLSDOCK_H

#include <QDockWidget>
#include "DrawToolsDockController.h"

class DrawToolsDock : public QDockWidget
{
    Q_OBJECT

public:
    DrawToolsDock(std::shared_ptr<DrawToolsDockController> controller);
    DrawToolsDock(const DrawToolsDock &source);
    DrawToolsDock(DrawToolsDock &&source);
    ~DrawToolsDock();

private:
    std::shared_ptr<DrawToolsDockController> _controller;

    void setupToolsToolbar();

private slots:
    void setNewShape();
    void setNewPen();
    void setNewBrush();
    void toggleAntialiased();
    void toggleTransformed();
};

#endif // DRAWTOOLSDOCK_H
