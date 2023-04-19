#include "drawtoolsdockcontroller.h"

DrawToolsDockController::DrawToolsDockController(DrawToolsDockControllerDelegate &delegate) :
    _delegate(delegate)
{}

DrawToolsDockController::DrawToolsDockController(const DrawToolsDockController &controller) :
    _delegate(controller._delegate)
{
}

DrawToolsDockController::DrawToolsDockController(DrawToolsDockController &&controller) :
    _delegate(controller._delegate)
{
}

void DrawToolsDockController::updateShape(DrawViewConfiguration::Shape shape)
{
    _delegate.didChangeShape(shape);
}

void DrawToolsDockController::updatePen(QPen pen)
{
    _delegate.didChangePen(pen);
}

void DrawToolsDockController::updateBrush(QBrush brush)
{
    _delegate.didChangeBrush(brush);
}

void DrawToolsDockController::updateAntialiased(bool isAntialiased)
{
    _delegate.didChangeAntialiased(isAntialiased);
}

void DrawToolsDockController::updateTransformed(bool isTransformed)
{
    _delegate.didChangeTransformed(isTransformed);
}
