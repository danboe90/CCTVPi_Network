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
        ||  nodeIP   == ""      || nodeIP == NULL
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





















