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
