#include <QDebug>
#include <QMessageBox>
#include <QToolBar>
#include <QDockWidget>

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "drawview.h"
#include "drawtoolsdockcontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _controller = std::shared_ptr<DrawToolsDockController>(new DrawToolsDockController(DrawViewConfiguration::makeDefault(), *this));
    drawView = std::unique_ptr<DrawView>(new DrawView());
    drawToolsDock = std::unique_ptr<DrawToolsDock>(new DrawToolsDock(_controller));

    configureUI();
}

MainWindow::~MainWindow()
{
    drawView.release();
    drawToolsDock.release();
    delete ui;
}

void MainWindow::configureUI()
{
    setCentralWidget(drawView.get());

    createActions();
    createMenus();
    setupToolsToolbar();
    _controller.get()->reloadConfiguration();
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, &QAction::triggered, this, &MainWindow::undo);

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, &QAction::triggered, this, &MainWindow::redo);

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
}

void MainWindow::setupToolsToolbar()
{
    addDockWidget(Qt::LeftDockWidgetArea, drawToolsDock.get());
}

void MainWindow::newFile()
{
    qInfo("Invoked <b>File|New</b>");
}

void MainWindow::open()
{
    qInfo("Invoked <b>File|Open</b>");
}

void MainWindow::save()
{
    qInfo("Invoked <b>File|Save</b>");
}

void MainWindow::print()
{
    qInfo("Invoked <b>File|Print</b>");
}

void MainWindow::undo()
{
    qInfo("Invoked <b>Edit|Undo</b>");
}

void MainWindow::redo()
{
    qInfo("Invoked <b>Edit|Redo</b>");
}

void MainWindow::cut()
{
    qInfo("Invoked <b>Edit|Cut</b>");
}

void MainWindow::copy()
{
    qInfo("Invoked <b>Edit|Copy</b>");
}

void MainWindow::paste()
{
    qInfo("Invoked <b>Edit|Paste</b>");
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Menu"),
                       tr("Dmitry Zavadsky 2023."));
}

#pragma region DrawToolsDockControllerDelegate

void MainWindow::didChangeConfiguration(DrawViewConfiguration configuration)
{
    drawView->updateConfiguration(configuration);
}

#pragma endregion DrawToolsDockControllerDelegate
