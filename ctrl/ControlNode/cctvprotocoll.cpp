#include "cctvprotocoll.h"

CctvProtocoll::CctvProtocoll()
{

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






