#ifndef CCTVPROTOCOLL_H
#define CCTVPROTOCOLL_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

#define CCTVPROT_DISCOVER_NODE_PORT                 "nodePort"
#define CCTVPROT_DISCOVER_NODE_TYPE                 "nodeType"
#define CCTVPROT_DISCOVER_NODE_IP                   "nodeIP"
#define CCTVPROT_DISCOVER_NODE_HOSTNAME             "nodeHostename"

#define CCTVPROT_OPERATIONAL_NODE_PORT              "nodePort"
#define CCTVPROT_OPERATIONAL_NODE_TYPE              "nodeType"
#define CCTVPROT_OPERATIONAL_NODE_IP                "nodeIP"
#define CCTVPROT_OPERATIONAL_NODE_HOSTNAME          "nodeHostname"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG            "nodeConfiguration"

#define CCTVPROT_OPERATIONAL_NODE_CONFIG_FW         "framewidth"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_FH         "frameheight"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_FR         "framerate"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_DESTIP     "destIP"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_DESTPORT   "destPort"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_SRCIP      "srcIP"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_PORT       "port"
#define CCTVPROT_OPERATIONAL_NODE_CONFIG_OPCODE     "opCode"

#define CCTVPROT_SHUTDOWN_NODE_FROM                 "fromHostname"
#define CCTVPROT_SHUTDOWN_NODE_TO                   "toHostname


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
    QString operational_getMessage(QJsonObject object);
    QString operational_getMessage(QString nodePort,
                                   QString nodeIP,
                                   QString nodeHostname,
                                   QString nodeType,
                                   QJsonObject configuration);

    QJsonObject operational_getConfigCam(QString framewidth,
                                         QString frameheight,
                                         QString framerate,
                                         QString destIP,
                                         QString destPort);

    QJsonObject operational_getConfigDisp(QString framewidth,
                                          QString frameheight,
                                          QString framerate,
                                          QString srcIP,
                                          QString port);

    QJsonObject operational_getConfigAuth(QString opCode);

    /*
     * --------------------------------------------------------------- METHODS FOR SHUTDOWN PROCESS
     */

    QString shutdown_getMessage(QString fromHostname, QString toHostname);
};

#endif // CCTVPROTOCOLL_H
