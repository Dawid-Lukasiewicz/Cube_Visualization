#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::on_MainWindow_ConnectButton_clicked()
{
    /* Creating socket */
    _socket = new QTcpSocket(this);
    connect( _socket, SIGNAL(connected()), this, SLOT(connected()) );
    connect( _socket, SIGNAL(disconnected()), this, SLOT(disconnected()) );
    connect( _socket, SIGNAL(readyRead()), this, SLOT(readyRead()) );
    connect( _socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)) );

    _socket->connectToHost("192.168.100.13", 1234);
    qDebug() << "Connecting...";

    if (_socket->state() != QAbstractSocket::ConnectedState
            && !_socket->waitForConnected(5000))
    {
        qDebug() << "Error while connecting: " << _socket->error() << "\n";
    }

}

void MainWindow::connected()
{
    qDebug() << "Connected";
}

void MainWindow::disconnected()
{
    qDebug() << "Disconnected";
    _socket->close();
}

void MainWindow::readyRead()
{
    qDebug() << "Reading: " << _socket->bytesAvailable(); // Print amount of data to debug console
//    qDebug() << _socket->readAll(); // Actual data print on SocketData Box [TO DO]
    _ui->SocketData->append(_socket->readAll());
    _socket->write("S\r\n");
}

void MainWindow::bytesWritten(const qint64 &bytes)
{
    qDebug() << "Written " << bytes << " bytes";
}



void MainWindow::on_MainWindow_DisconnectButton_clicked()
{
    qDebug() << "Disconnecting...\n";
    _socket->disconnectFromHost();
    if (_socket->state() != QAbstractSocket::UnconnectedState
            && !_socket->waitForDisconnected())
    {
        qDebug() << "Error while disconnecting: " << _socket->error() << "\n";
    }
}

