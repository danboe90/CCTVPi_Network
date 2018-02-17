#ifndef NODEINFO_H
#define NODEINFO_H

#include <QJsonObject>


class NodeInfo
{

private:
    QJsonObject object;

public:
    NodeInfo();
    NodeInfo(QJsonObject object);
};

#endif // NODEINFO_H
