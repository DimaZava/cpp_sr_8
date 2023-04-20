#ifndef DRAWTOOLSDOCKCONTROLLER_H
#define DRAWTOOLSDOCKCONTROLLER_H

#include "drawviewconfiguration.h"

class DrawToolsDockControllerDelegate
{
public:
    virtual void didChangeConfiguration(DrawViewConfiguration configuration) {};
};

class DrawToolsDockController
{
public:
    DrawToolsDockController(DrawViewConfiguration configuration, DrawToolsDockControllerDelegate &delegate);
    DrawToolsDockController(const DrawToolsDockController &controller);
    DrawToolsDockController(DrawToolsDockController &&controller);

    void reloadConfiguration();
    void updateShape(DrawViewConfiguration::Shape shape);
    void updatePen(QPen pen);
    void updateBrush(QBrush brush);
    void updateAntialiased(bool isAntialiased);
    void updateTransformed(bool isTransformed);

private:
    DrawToolsDockControllerDelegate &_delegate;
    DrawViewConfiguration _configuration;
};

#endif // DRAWTOOLSDOCKCONTROLLER_H
