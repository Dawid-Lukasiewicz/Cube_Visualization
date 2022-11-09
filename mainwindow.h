#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <memory>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_MainWindow_ConnectButton_clicked();

private:
    Ui::MainWindow *ui;

    std::shared_ptr<QTcpSocket> _socket_connection;
};
#endif // MAINWINDOW_H
