#ifndef NODEINFO_H
#define NODEINFO_H

#include <QJsonObject>
#include "cctvprotocoll.h"
#include <QHostAddress>


class NodeInfo
{

private:
    QJsonObject object;

public:
    NodeInfo();
    NodeInfo(QJsonObject object);

    QString getHostname();
    QString getHostPort();
    QHostAddress getHostaddress();
};

#endif // NODEINFO_H
