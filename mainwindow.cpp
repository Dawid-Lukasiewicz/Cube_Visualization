#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    /* Creating socket */
    _socket = new QTcpSocket(this);
    connect( _socket, SIGNAL(connected()), this, SLOT(connected()) );
    connect( _socket, SIGNAL(disconnected()), this, SLOT(disconnected()) );
    connect( _socket, SIGNAL(readyRead()), this, SLOT(readyRead()) );
    connect( _socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)) );
}

MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::on_MainWindow_ConnectButton_clicked()
{
    _socket->connectToHost("192.168.100.13", 1234);
//    _socket->connectToHost("google.com", 80);
    qDebug() << "Connecting...";
//    if (!_socket->waitForConnected(5000))
//        qDebug() << "Not connected";

//    _socket->write("hello pico\r\n\r\n\r\n\r\n");

//    _socket->waitForBytesWritten(3000);
//    _socket->waitForReadyRead(10000);

}

void MainWindow::connected()
{
    qDebug() << "Connected";
    _socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n");
}

void MainWindow::disconnected()
{
    qDebug() << "Disconnected";
    _socket->close();
}

void MainWindow::readyRead()
{
    qDebug() << "Reading: " << _socket->bytesAvailable(); // Print amount of data to debug console
    qDebug() << _socket->readAll(); // Actual data print on SocketData Box [TO DO]

}

void MainWindow::bytesWritten(const qint64 &bytes)
{

}


