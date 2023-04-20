#include "drawtoolsdockcontroller.h"

DrawToolsDockController::DrawToolsDockController(
DrawViewConfiguration configuration,
DrawToolsDockControllerDelegate &delegate
)
    : _configuration(configuration)
    , _delegate(delegate)
{
}

void DrawToolsDockController::reloadConfiguration()
{
    _delegate.didChangeConfiguration(_configuration);
}

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
    _configuration.shape = shape;
    _delegate.didChangeConfiguration(_configuration);
}

void DrawToolsDockController::updatePen(QPen pen)
{
    _configuration.pen = pen;
    _delegate.didChangeConfiguration(_configuration);
}

void DrawToolsDockController::updateBrush(QBrush brush)
{
    _configuration.brush = brush;
    _delegate.didChangeConfiguration(_configuration);
}

void DrawToolsDockController::updateAntialiased(bool isAntialiased)
{
    _configuration.antialiased = isAntialiased;
    _delegate.didChangeConfiguration(_configuration);
}

void DrawToolsDockController::updateTransformed(bool isTransformed)
{
    _configuration.transformed = isTransformed;
    _delegate.didChangeConfiguration(_configuration);
}
