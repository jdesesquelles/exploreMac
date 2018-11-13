#ifndef DIRECTORYHIERARCHY_H
#define DIRECTORYHIERARCHY_H
#include <QString>
#include<QDir>
#include<QFile>
#include<QDebug>

class directoryHierarchy
{
public:
    directoryHierarchy();
    void createTestDir(QString path);
    void createTestFile(QString fileName);
    void createTestHierarchy();
};

#endif // DIRECTORYHIERARCHY_H
