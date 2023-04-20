#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>

#include "drawtoolsdock.h"

class DrawView;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QAction;
class QMenu;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
    , public DrawToolsDockControllerDelegate
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newFile();
    void open();
    void save();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();

    #pragma region DrawToolsDockControllerDelegate

    void didChangeShape(DrawViewConfiguration::Shape shape) override;
    void didChangePen(QPen pen) override;
    void didChangeBrush(QBrush brush) override;
    void didChangeAntialiased(bool isAntialiased) override;
    void didChangeTransformed(bool isTransformed) override;

    #pragma endregion DrawToolsDockControllerDelegate
private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;

    QAction *aboutAct;

    std::unique_ptr<DrawView> drawView;
    std::unique_ptr<DrawToolsDock> drawToolsDock;

    void configureUI();
    void createMenus();
    void createActions();
    void about();
    void setupToolsToolbar();
};
#endif // MAINWINDOW_H
