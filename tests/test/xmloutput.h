#ifndef XMLOUTPUT_H
#define XMLOUTPUT_H

#include <QDomImplementation>
#include <QDomDocument>
#include <QDomElement>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDebug>


class xmlOutput
{
public:
    xmlOutput();
    void writeToFile(QDomDocument doc, QString name);
    QDomDocument create_testcase_data(QDomDocument doc, QDomElement parent, QString element, QString filePath, QString fileName, QString size, QString suffix);
    QDomDocument create_testcase_file(QDomDocument doc, QDomElement parent, QString filePath, QString fileName, QString size, QString suffix);
    QDomDocument create_testcase_directory(QDomDocument doc, QDomElement parent, QString filePath, QString fileName);
    void create_testcase1_data ();

    void create_testcase2_data ();

    void create_testcase3_data ();

    void create_testcase4_data ();

    void create_testcase5_data ();

    void create_testcase6_data ();

    void create_testcase7_data ();

    void create_testcase8_data ();
};

#endif // XMLOUTPUT_H
