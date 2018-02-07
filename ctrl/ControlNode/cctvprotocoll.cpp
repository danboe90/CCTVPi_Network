#include "cctvprotocoll.h"

CctvProtocoll::CctvProtocoll()
{

}



/**
 * @brief   CctvProtocoll::discover_getMessage
 *          This method creates a QString object out of the given QJSonObject
 * @param   object - contains the discovery parameters
 * @return  NULL - if an error occured
 * @return  QString object representation of object
 */
QString CctvProtocoll::discover_getMessage(QJsonObject object){
    int err;

    err=0;

    if(object.isEmpty()) {
        err=1;
    }

    if(     !object.contains(CCTVPROT_DISCOVER_NODE_PORT)
        ||  !object.contains(CCTVPROT_DISCOVER_NODE_IP)
        ||  !object.contains(CCTVPROT_DISCOVER_NODE_HOSTNAME)
        ||  !object.contains(CCTVPROT_DISCOVER_NODE_TYPE))
    {
        err=1;
    }

    QJsonDocument doc(object);
    if(doc.isEmpty()) {
        err=1;
    }

    if(!err) {
        QString rtnString(doc.toJson(QJsonDocument::Indented));
        return rtnString;
    }
    return NULL;
}


/**
 * @brief   CctvProtocoll::discover_getMessage
 *          This is an overloaded method.
 * @param   nodePort
 * @param   nodeIP
 * @param   nodeHostname
 * @param   nodeType
 * @return  NULL if any errors occured
 * @return  Qstring object containing a valid discovery message.
 */
QString CctvProtocoll::discover_getMessage( QString nodePort,
                                            QString nodeIP,
                                            QString nodeHostname,
                                            QString nodeType)
{
    int err;
    QJsonObject object;

    err=0;

    if(     nodePort == ""      || nodePort == NULL
        ||  nodeIP == ""        || nodeIP == NULL
        ||  nodeHostname == ""  || nodeHostname == NULL
        ||  nodeType == ""      || nodeType == NULL)
    {
        err=1;
    }

    if(!err) {
        object.insert(CCTVPROT_DISCOVER_NODE_IP, nodeIP);
        object.insert(CCTVPROT_DISCOVER_NODE_PORT, nodePort);
        object.insert(CCTVPROT_DISCOVER_NODE_HOSTNAME, nodeHostname);
        object.insert(CCTVPROT_DISCOVER_NODE_TYPE, nodeType);
        QJsonDocument doc(object);
        QString rtnString(doc.toJson(QJsonDocument::Indented));
        return rtnString;
    }
    return NULL;
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












