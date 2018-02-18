#include "cctvprotocoll.h"

CctvProtocoll::CctvProtocoll()
{

}













/**
 * @brief   CctvProtocoll::operational_getMessage
 *          This method generates a transmission message for the operational process from
 *          the control-node to one of the other nodes
 * @param   object
 * @return  NULL - if an error occured
 * @return  QString object containing the data to transmit to the node
 */
QString CctvProtocoll::operational_getMessage(QJsonObject object) {
    int err;

    err=0;

    if(object.isEmpty()) { err=1; }

    // check if object contains the right content for the node
    if(!err) {
        if(     !object.contains(CCTVPROT_OPERATIONAL_NODE_PORT)
            ||  !object.contains(CCTVPROT_OPERATIONAL_NODE_TYPE)
            ||  !object.contains(CCTVPROT_OPERATIONAL_NODE_IP)
            ||  !object.contains(CCTVPROT_OPERATIONAL_NODE_HOSTNAME)
            ||  !object.contains(CCTVPROT_OPERATIONAL_NODE_CONFIG))
        {
            err=1;
        }
    }

    if(!err) {
        QJsonDocument doc(object);
        QString rtnString(doc.toJson(QJsonDocument::Indented));
        return rtnString;
    }
    return NULL;
}


/**
 * @brief   CctvProtocoll::operational_getMessage
 *          This method generates a QString representation of the operational-datapackage to be
 *          transmitted from the control node to the other nodes.
 * @param   nodePort
 * @param   nodeIP
 * @param   nodeHostname
 * @param   nodeType
 * @param   configuration
 * @return  NULL - if somthing went wrong
 * @return  QString object containing the data to be transmitted
 */
QString CctvProtocoll::operational_getMessage(QString nodePort,
                                              QString nodeIP,
                                              QString nodeHostname,
                                              QString nodeType,
                                              QJsonObject configuration)
{
    int err;

    err=0;

    /*
     * -------------------------------------------------------------------------------- PARAM CHECK
     */
    if(     nodePort==""        ||  nodePort == NULL
        ||  nodeIP == ""        ||  nodeIP == NULL
        ||  nodeHostname == ""  ||  nodeHostname == NULL
        ||  nodeType == ""      ||  nodeType == NULL
        ||  configuration.isEmpty())
    {
        err=1;
    }

    if(!err) {
        QJsonObject object;
        object.insert(CCTVPROT_OPERATIONAL_NODE_PORT, nodePort);
        object.insert(CCTVPROT_OPERATIONAL_NODE_IP, nodeIP);
        object.insert(CCTVPROT_OPERATIONAL_NODE_HOSTNAME, nodeHostname);
        object.insert(CCTVPROT_OPERATIONAL_NODE_TYPE, nodeType);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG, configuration);

        QJsonDocument doc(object);
        QString rtnString(doc.toJson(QJsonDocument::Indented));
        return rtnString;
    }
    return NULL;
}


/**
 * @brief   CctvProtocoll::operational_getConfigCam
 *          This method generates a QJSonObject for camera-nodes containing the
 *          information the camera needs.
 * @param   framewidth
 * @param   frameheight
 * @param   framerate
 * @param   destIP
 * @param   destPort
 * @return  QJsonObject containing the configuration of the camera-node if everything went OK
 */
QJsonObject CctvProtocoll::operational_getConfigCam(QString framewidth,
                                                    QString frameheight,
                                                    QString framerate,
                                                    QString destIP,
                                                    QString destPort)
{
    int err;
    QJsonObject object;

    err=0;

    /*
     * -------------------------------------------------------------------------------- PARAM CHECK
     */
    if(     framewidth == ""    || framewidth == NULL
        ||  frameheight == ""   || frameheight == NULL
        ||  framerate == ""     || framerate == NULL
        ||  destIP == ""        || destIP == NULL
        ||  destPort == ""      || destPort == NULL)
    {
        err=1;
    }

    if(!err) {

        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_FW, framewidth);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_FH, frameheight);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_FR, framerate);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_DESTIP, destIP);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_DESTPORT, destPort);
    }
    return object;
}


/**
 * @brief   CctvProtocoll::operational_getConfigDisp
 *          This method generates the configuration-object for the data-package in the
 *          operational phase. This package is only allowed to be sent by the control-node.
 * @param   framewidth
 * @param   frameheight
 * @param   framerate
 * @param   srcIP
 * @param   port
 * @return  QJsonObject object. In case everything went OK, it contains the entire
 *          confirguration needed. Otherwise it is an empty object.
 */
QJsonObject CctvProtocoll::operational_getConfigDisp(QString framewidth,
                                                     QString frameheight,
                                                     QString framerate,
                                                     QString srcIP,
                                                     QString port)
{
    int err;
    QJsonObject object;

    err=0;

    if(     framewidth == ""    ||  framewidth == NULL
        ||  frameheight == ""   ||  frameheight == NULL
        ||  framerate == ""     ||  framerate == NULL
        ||  srcIP == ""         ||  srcIP == NULL
        ||  port == ""          ||  port == NULL)
    {
        err=1;
    }

    if(!err) {
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_FW, framewidth);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_FH, frameheight);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_FR, framerate);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_SRCIP, srcIP);
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_PORT, port);
    }
    return object;
}





/**
 * @brief   CctvProtocoll::operational_getConfigAuth
 *          This method generates the configuration-object for the data-package
 *          in the operational-phase. This package is only allowed to be sent by the control-node.
 * @param   opCode
 * @return  QJsonObject object. In case everything went OK, it contains the entire
 *          configuration needed for the authentication-node. Otherwise an empty object is returned.
 */
QJsonObject CctvProtocoll::operational_getConfigAuth(QString opCode)
{
    int err;
    QJsonObject object;

    err=0;

    if(opCode == "" || opCode == NULL) { err=1; }

    if(!err) {
        object.insert(CCTVPROT_OPERATIONAL_NODE_CONFIG_OPCODE, opCode);
    }
    return object;
}



/**
 * @brief   CctvProtocoll::shutdown_getMessage
 *          This method generates the neccessary shutdown-message for all nodes for
 *          the shutdown-procedure.
 * @param   fromHostname
 * @return  NULL - if an error occurred
 * @return  QString object representing the shutdown-message
 */
QString CctvProtocoll::shutdown_getMessage(QString fromHostname, QString toHostname)
{
    int err;
    QJsonObject object;

    err=0;

    if(     fromHostname == ""  || fromHostname == NULL
        ||  toHostname == ""    || toHostname == NULL)
    {
        err=1;
    }

    if(!err) {
        object.insert(CCTVPROT_SHUTDOWN_NODE_FROM, fromHostname);
        object.insert(CCTVPROT_SHUTDOWN_NODE_TO, toHostname);
        QJsonDocument doc(object);
        QString rtnString(doc.toJson(QJsonDocument::Indented));
        return rtnString;
    }
    return NULL;
}






