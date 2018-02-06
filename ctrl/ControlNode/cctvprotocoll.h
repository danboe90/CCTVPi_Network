#ifndef CCTVPROTOCOLL_H
#define CCTVPROTOCOLL_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>




/**
 * @brief   The CctvProtocoll class
 *          This class covers the entire functionality for generating the coresponding
 *          messages to the different nodes
 */
class CctvProtocoll
{
public:
    CctvProtocoll();

    QString discover_getMessage();
};

#endif // CCTVPROTOCOLL_H
