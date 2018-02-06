#ifndef CCTVPROTOCOLL_H
#define CCTVPROTOCOLL_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

#define CCTVPROT_DISCOVER_NODE_PORT         "nodePort"
#define CCTVPROT_DISCOVER_NODE_TYPE         "nodeType"
#define CCTVPROT_DISCOVER_NODE_IP           "nodeIP"
#define CCTVPROT_DISCOVER_NODE_HOSTNAME     "nodeHostename"


/**
 * @brief   The CctvProtocoll class
 *          This class covers the entire functionality for generating the coresponding
 *          messages to the different nodes
 */
class CctvProtocoll
{
public:
    CctvProtocoll();

    QString discover_getMessage(QJsonObject object);
};

#endif // CCTVPROTOCOLL_H
