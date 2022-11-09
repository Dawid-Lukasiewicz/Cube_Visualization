#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MainWindow_ConnectButton_clicked()
{
    _socket_connection = std::make_shared<QTcpSocket>(this);

    _socket_connection->connectToHost("google.com", 80);

    if (_socket_connection->waitForConnected(5000))
        qDebug() << "Connected";
    else
        qDebug() << "Not connected";
}

