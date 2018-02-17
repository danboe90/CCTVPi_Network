#include "nodeinfo.h"


/**
 * @brief   NodeInfo::NodeInfo
 */
NodeInfo::NodeInfo() { }


/**
 * @brief   NodeInfo::NodeInfo
 *          Constructor of the class
 * @param   object
 */
NodeInfo::NodeInfo(QJsonObject object)
{
    if(!object.isEmpty()) {
        this->object = object;
    }
}


/**
 * @brief   NodeInfo::getHostname
 * @return
 */
QString NodeInfo::getHostname() {
    return this->object.value(CCTVPROT_OPERATIONAL_NODE_HOSTNAME).toString();
}


/**
 * @brief   NodeInfo::getHostPort
 * @return
 */
QString NodeInfo::getHostPort() {
    return this->object.value(CCTVPROT_OPERATIONAL_NODE_PORT).toString();
}


/**
 * @brief   NodeInfo::getHostaddress
 * @return
 */
QHostAddress NodeInfo::getHostaddress() {
    return QHostAddress(this->object.value(CCTVPROT_OPERATIONAL_NODE_IP).toString());
}








