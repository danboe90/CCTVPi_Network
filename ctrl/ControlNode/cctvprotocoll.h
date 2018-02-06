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


    /*
     * -------------------------------------------------------------- METHODES FOR DISCOVER PROCESS
     */
    QString discover_getMessage(QJsonObject object);
    QString discover_getMessage(QString nodePort,
                                QString nodeIP,
                                QString nodeHostname,
                                QString nodeType);

    /*
     * ------------------------------------------------------------ METHODS FOR OPERATIONAL PROCESS
     */


    /*
     * --------------------------------------------------------------- METHODS FOR SHUTDOWN PROCESS
     */
};

#endif // CCTVPROTOCOLL_H
