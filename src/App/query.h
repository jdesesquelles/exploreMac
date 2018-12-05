#ifndef QUERY_H
#define QUERY_H

#include <QObject>
#include <QDomDocument>

class Query
{

public:
    explicit Query();
    QDomDocument* queryDirectory(QString directory);

signals:

public slots:
};

#endif // QUERY_H
