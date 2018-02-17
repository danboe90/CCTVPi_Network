#include "nodeinfo.h"


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
