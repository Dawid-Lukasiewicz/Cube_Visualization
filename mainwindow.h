#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void bytesWritten(const qint64 &bytes);

private slots:

    void on_MainWindow_ConnectButton_clicked();

    void on_MainWindow_DisconnectButton_clicked();

private:
    Ui::MainWindow *_ui;

    QTcpSocket *_socket;
};
#endif // MAINWINDOW_H
