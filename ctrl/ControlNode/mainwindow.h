#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <cctvprotocoll.h>
#include <nodeinfo.h>

#include <QUdpSocket>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}


/**
 * @brief   The MainWindow class
 *          The MainWindow class provides all objects for a successful launch of the application.
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    NodeInfo listAuthNodes;
    NodeInfo listCamNodes;
    NodeInfo listDispNodes;

    QUdpSocket *discoverySocket;

private slots:
    void readPendingDatagrams();
};

#endif // MAINWINDOW_H
