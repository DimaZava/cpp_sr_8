#include "drawtoolsdock.h"

#include <QToolBar>
#include <QPen>

DrawToolsDock::DrawToolsDock(std::shared_ptr<DrawToolsDockController> controller)
    : _controller(controller)
{
    setupToolsToolbar();
}

DrawToolsDock::DrawToolsDock(const DrawToolsDock &source)
    : _controller(source._controller)
{
    setupToolsToolbar();
}

DrawToolsDock::DrawToolsDock(DrawToolsDock &&source)
    : _controller(source._controller)
{
    setupToolsToolbar();
}

DrawToolsDock::~DrawToolsDock()
{
}

void DrawToolsDock::setupToolsToolbar()
{
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QToolBar *toolsToolbar = new QToolBar();
    toolsToolbar->setOrientation(Qt::Orientation::Vertical);

    QAction *setShapeAction = new QAction(tr("Change &Shape"), this);
    setShapeAction->setStatusTip(tr("Create a new shape"));
    connect(setShapeAction, SIGNAL(triggered()), this, SLOT(setNewShape()));
    toolsToolbar->addAction(setShapeAction);

    QAction *setPenAction = new QAction(tr("Set &Pen"), this);
    setPenAction->setStatusTip(tr("Set a new pen"));
    connect(setPenAction, SIGNAL(triggered()), this, SLOT(setNewPen()));
    toolsToolbar->addAction(setPenAction);

    QAction *setBrushAction = new QAction(tr("Set &Brush"), this);
    setBrushAction->setStatusTip(tr("Set a new brush"));
    connect(setBrushAction, SIGNAL(triggered()), this, SLOT(setNewBrush()));
    toolsToolbar->addAction(setBrushAction);

    QAction *setAntialiasedAction = new QAction(tr("Set &Antialiased"), this);
    setAntialiasedAction->setStatusTip(tr("Toggle antialiased"));
    connect(setAntialiasedAction, SIGNAL(triggered()), this, SLOT(toggleAntialiased()));
    toolsToolbar->addAction(setAntialiasedAction);

    QAction *setTransformedAction = new QAction(tr("Set &Transformed"), this);
    setTransformedAction->setStatusTip(tr("Toggle transformed"));
    connect(setTransformedAction, SIGNAL(triggered()), this, SLOT(toggleTransformed()));
    toolsToolbar->addAction(setTransformedAction);

    setWidget(toolsToolbar);
}

// Down there are some hardcoded predefined values
// Ideally one have to get some indexes or corresponding metadata / DTOs
// Based on interactable controls
// Which will be passed to controller to perform changes

void DrawToolsDock::setNewShape()
{
    qInfo("Invoked setNewShape");
    _controller.get()->updateShape(DrawViewConfiguration::Shape::Pie);
}

void DrawToolsDock::setNewPen()
{
    qInfo("Invoked setNewPen");
    QPen newPen = QPen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    _controller.get()->updatePen(newPen);
}

void DrawToolsDock::setNewBrush()
{
    qInfo("Invoked setNewBrush");
    QBrush newBrush = QBrush(Qt::red, Qt::DiagCrossPattern);
    _controller.get()->updateBrush(newBrush);
}

void DrawToolsDock::toggleAntialiased()
{
    qInfo("Invoked toggleAntialiased");
    _controller.get()->updateAntialiased(true);
}

void DrawToolsDock::toggleTransformed()
{
    qInfo("Invoked toggleTransformed");
     _controller.get()->updateTransformed(true);
}
