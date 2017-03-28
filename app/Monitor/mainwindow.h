#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraImageCapture>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectCamera();

private:
    Ui::MainWindow *ui;

//    Camera *camera;
    QCamera *camera;
    QCameraImageCapture *imageCapture;
};

#endif // MAINWINDOW_H
