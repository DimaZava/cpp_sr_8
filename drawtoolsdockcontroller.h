#ifndef DRAWTOOLSDOCKCONTROLLER_H
#define DRAWTOOLSDOCKCONTROLLER_H

#include "drawviewconfiguration.h"

class DrawToolsDockControllerDelegate
{
public:
    virtual void didChangeShape(DrawViewConfiguration::Shape shape) {};
    virtual void didChangePen(QPen pen) {};
    virtual void didChangeBrush(QBrush brush) {};
    virtual void didChangeAntialiased(bool isAntialiased) {};
    virtual void didChangeTransformed(bool isTransformed) {};
};

class DrawToolsDockController
{
public:
    DrawToolsDockController(DrawToolsDockControllerDelegate &delegate);
    DrawToolsDockController(const DrawToolsDockController &controller);
    DrawToolsDockController(DrawToolsDockController &&controller);

    void updateShape(DrawViewConfiguration::Shape shape);
    void updatePen(QPen pen);
    void updateBrush(QBrush brush);
    void updateAntialiased(bool isAntialiased);
    void updateTransformed(bool isTransformed);
private:
    DrawToolsDockControllerDelegate &_delegate;

};

#endif // DRAWTOOLSDOCKCONTROLLER_H
