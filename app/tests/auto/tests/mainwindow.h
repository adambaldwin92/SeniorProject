#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setCamera(const QCameraInfo &cameraInfo);

    void startCamera();
    void stopCamera();

    void updateCameraDevice(QAction *action);

    void displayViewfinder();


protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QMediaRecorder* mediaRecorder;

    QImageEncoderSettings imageSettings;
    QAudioEncoderSettings audioSettings;
    QVideoEncoderSettings videoSettings;
    QString videoContainerFormat;
    bool isCapturingImage;
    bool applicationExiting;
};


#endif // MAINWINDOW_H
