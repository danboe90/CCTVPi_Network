#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * --------------------------------------------------------------------- UDP SOCKET (DISCOVERY)
     */
    this->discoverySocket = new QUdpSocket();
    this->discoverySocket->bind(QHostAddress::AnyIPv4, 49200);
    connect(this->discoverySocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readPendingDatagrams() {
    char data[CCTVPROT_DISCOVER_NODE_MSG_PKGSIZE] = {0};


    while (this->discoverySocket->hasPendingDatagrams()) {
        this->discoverySocket->readDatagram(data, CCTVPROT_DISCOVER_NODE_MSG_PKGSIZE);
    }
}
