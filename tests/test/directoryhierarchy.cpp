#include "directoryhierarchy.h"

directoryHierarchy::directoryHierarchy()
{

}

void directoryHierarchy::createTestHierarchy()
{
    QString path = "tmp";
    createTestDir(path);
     path = "tmp/dir1";
     createTestDir(path);
     qDebug() << QDir::currentPath();
     path = "tmp/dir2";
     createTestDir(path);
     qDebug() << QDir::currentPath();
     createTestDir("tmp/dir2");
     createTestDir(path);
     qDebug() << QDir::currentPath();
     path = "tmp/dir4";
     createTestDir(path);
     path = "tmp/dir5";
     createTestDir(path);
     path = "tmp/dir6";
     createTestDir(path);
     path = "tmp/dir7";
     createTestDir(path);
     path = "tmp/dir8";
     createTestDir(path);
     path = "tmp/dir2/sdir1";
     createTestDir(path);

     path = "tmp/dir3/sdir1";
     createTestDir(path);
     path = "tmp/dir3/sdir2";
     createTestDir(path);
       qDebug() << QDir::currentPath();
     path = "tmp/dir4/sdir1";
     createTestDir(path);
     qDebug() << QDir::currentPath();
     path = "tmp/dir4/sdir2";
     createTestDir(path);
     qDebug() << QDir::currentPath();
     path = "tmp/dir4/file1";
     createTestFile(path);

     path = "tmp/dir5/sdir1";
     createTestDir(path);
     path = "tmp/dir5/sdir2";
     createTestDir(path);
     path = "tmp/dir5/file1";
     createTestFile(path);
     path = "tmp/dir5/file2";
     createTestFile(path);
     path = "tmp/dir6/sdir1";
     createTestDir(path);
     path = "tmp/dir6/file1";
     createTestFile(path);
     path = "tmp/dir6/file2";
     createTestFile(path);

     path = "tmp/dir7/file1";
     createTestFile(path);
     path = "tmp/dir7/file2";
     createTestFile(path);

     path = "tmp/dir8/file1";
     createTestFile(path);
}


void directoryHierarchy::createTestDir(QString path)
{
    QDir cdir(QDir::current());
    QDir dir(path);
    if(!dir.exists())
        {
            qDebug() << "Creating " << path << "directory";
            cdir.mkpath(path);
        }
        else
        {
            qDebug() << path << " already exists";
        }
}

void directoryHierarchy::createTestFile(QString fileName)
{
    QFile file(fileName);
        // Trying to open in WriteOnly and Text mode
        if(!file.open(QFile::WriteOnly |
                      QFile::Text))
        {
            qDebug() << " Could not open file for writing";
            return;
        }

        // To write text, we use operator<<(),
        // which is overloaded to take
        // a QTextStream on the left
        // and data types (including QString) on the right

        QTextStream out(&file);
        out << "test file";
        file.flush();
        file.close();
}
