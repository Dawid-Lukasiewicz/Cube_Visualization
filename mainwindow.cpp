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

    connect( _socket, SIGNAL(hostFound()), this, SLOT(sendLedData()) );

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
    _socket->write("X2:Y2:Z2:");
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
    quint32 valueX = QRandomGenerator::global()->generate()%5;
    quint32 valueY = QRandomGenerator::global()->generate()%5;
    quint32 valueZ = QRandomGenerator::global()->generate()%5;
    QString data_output = "X" + QString::number(valueX) + ":Y" + QString::number(valueY) + ":Z" + QString::number(valueZ) + ":";
    _socket->write(data_output.toStdString().c_str());
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

