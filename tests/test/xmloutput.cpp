#include "xmloutput.h"

xmlOutput::xmlOutput()
{

}

void xmlOutput::writeToFile(QDomDocument document, QString name)
{
    // Writing to a file
    QFile file(name);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open the file for writing failed";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Writing is done";
    }
}

QDomDocument xmlOutput::create_testcase_data(QDomDocument doc, QDomElement parent, QString element, QString filePath, QString fileName, QString size, QString suffix)
{
    if (element == "directory")
    {

     return create_testcase_directory( doc,  parent,  filePath,  fileName);

    }
    else if (element == "file")
    {
       return create_testcase_file(doc,  parent,  filePath,  fileName, size, suffix);
    }
    return doc;
}

QDomDocument xmlOutput::create_testcase_file(QDomDocument doc, QDomElement parent, QString filePath, QString fileName, QString size, QString suffix)
{
    QDomElement EntryNode = doc.createElement("directory");
    EntryNode.setAttribute("filePath",filePath);
    EntryNode.setAttribute("fileName",fileName);
    EntryNode.setAttribute("size",size);
    EntryNode.setAttribute("suffix",suffix);
    parent.appendChild(EntryNode);
    return doc;
}

QDomDocument xmlOutput::create_testcase_directory(QDomDocument doc, QDomElement parent, QString filePath, QString fileName)
{
    QDomElement EntryNode = doc.createElement("directory");
    EntryNode.setAttribute("filePath",filePath);
    EntryNode.setAttribute("fileName",fileName);
    parent.appendChild(EntryNode);
    return doc;
}

void xmlOutput::create_testcase1_data () {

    QString name = "testcase1_data";
    QDomDocument doc;
    QDomElement Entrydir1Node = doc.createElement("directory");
    Entrydir1Node.setAttribute("filePath","C:/TDD_testdir/dir1");
    Entrydir1Node.setAttribute("fileName","dir1");
    doc.appendChild(Entrydir1Node);

//    QString filePath = "C:/TDD_testdir/dir1";
//    QString fileName = "dir1";
//    QDomDocument doc;
//    doc = create_testcase_data(doc, doc.firstChildElement(), "directory", filePath, fileName, "", "");
    writeToFile(doc, name);
}

void xmlOutput::create_testcase2_data () {

    QString name = "testcase2_data";
    QDomDocument doc;
    QDomElement Entrydir2Node = doc.createElement("directory");
    Entrydir2Node.setAttribute("filePath","C:/TDD_testdir/dir2");
    Entrydir2Node.setAttribute("fileName","dir2");
    doc.appendChild(Entrydir2Node);

//    QString filePath = "C:/TDD_testdir/dir2";
//    QString fileName = "dir2";
//    doc = create_testcase_data(doc, doc.firstChildElement(), "directory", filePath, fileName, "", "");

    QDomElement Entrysdir1Node = doc.createElement("directory");
    Entrysdir1Node.setAttribute("filePath","C:/TDD_testdir/dir2/sdir1");
    Entrysdir1Node.setAttribute("fileName","sdir1");
    Entrydir2Node.appendChild(Entrysdir1Node);

//    filePath = "C:/TDD_testdir/dir2/sdir1";
//    fileName = "sdir1";
//    doc = create_testcase_data(doc, doc.firstChildElement(), "directory", filePath, fileName, "", "");

    writeToFile(doc, name);
}

void xmlOutput::create_testcase3_data () {

    QString name = "testcase3_data";
    QDomDocument doc;
    QDomElement Entrydir3Node = doc.createElement("directory");
    Entrydir3Node.setAttribute("filePath","C:/TDD_testdir/dir3");
    Entrydir3Node.setAttribute("fileName","dir3");
    doc.appendChild(Entrydir3Node);
    QDomElement Entrysdir1Node = doc.createElement("directory");
    Entrysdir1Node.setAttribute("filePath","C:/TDD_testdir/dir3/sdir1");
    Entrysdir1Node.setAttribute("fileName","sdir1");
    Entrydir3Node.appendChild(Entrysdir1Node);
    QDomElement Entrysdir2Node = doc.createElement("directory");
    Entrysdir2Node.setAttribute("filePath","C:/TDD_testdir/dir3/sdir2");
    Entrysdir2Node.setAttribute("fileName","sdir2");
    Entrydir3Node.appendChild(Entrysdir2Node);
    writeToFile(doc, name);
}

void xmlOutput::create_testcase4_data () {

    QString name = "testcase4_data";
    QDomDocument doc;
    QDomElement Entrydir4Node = doc.createElement("directory");
    Entrydir4Node.setAttribute("filePath","C:/TDD_testdir/dir4");
    Entrydir4Node.setAttribute("fileName","dir4");
    doc.appendChild(Entrydir4Node);
    QDomElement Entrysdir1Node = doc.createElement("directory");
    Entrysdir1Node.setAttribute("filePath","C:/TDD_testdir/dir4/sdir1");
    Entrysdir1Node.setAttribute("fileName","sdir1");
    Entrydir4Node.appendChild(Entrysdir1Node);
    QDomElement Entrysdir2Node = doc.createElement("directory");
    Entrysdir2Node.setAttribute("filePath","C:/TDD_testdir/dir4/sdir2");
    Entrysdir2Node.setAttribute("fileName","sdir2");
    Entrydir4Node.appendChild(Entrysdir2Node);
    QDomElement Entryfile1Node = doc.createElement("file");
    Entryfile1Node.setAttribute("filePath","C:/TDD_testdir/dir4/file1");
    Entryfile1Node.setAttribute("fileName","file1");
    Entryfile1Node.setAttribute("size","C:/TDD_testdir/dir4/file1");
    Entryfile1Node.setAttribute("suffix","file1");
    Entrydir4Node.appendChild(Entryfile1Node);
    writeToFile(doc, name);
}

void xmlOutput::create_testcase5_data () {

    QString name = "testcase5_data";
    QDomDocument doc;
    QString filePath = "C:/TDD_testdir/dir5";
    QString fileName = "dir5";
    QString size = ""; //","C:/TDD_testdir/dir5/file1");
    QString suffix = ""; //"
    doc = create_testcase_data(doc, doc.firstChildElement(), "directory", filePath, fileName, size, suffix);

    filePath = "C:/TDD_testdir/dir5/sdir1";
    fileName = "sdir1";
    doc = create_testcase_data(doc, doc.firstChildElement(), "directory", filePath, fileName, size, suffix);

    filePath = "C:/TDD_testdir/dir5/sdir2";
    fileName = "sdir2";
    doc = create_testcase_data(doc, doc.firstChildElement(), "directory", filePath, fileName, size, suffix);

    filePath = "C:/TDD_testdir/dir5/file1";
    fileName = "file1";
    size = "0";
    suffix = "";
    doc = create_testcase_data(doc, doc.firstChildElement(), "file", filePath, fileName, size, suffix);

    //QDomElement Entryfile2Node = doc.createElement("file");
    filePath = "C:/TDD_testdir/dir5/file2";
    fileName = "file2";
    size = "0";
    suffix = "";
    doc = create_testcase_data(doc, doc.firstChildElement(), "file", filePath, fileName, size, suffix);

    writeToFile(doc, name);
}

void xmlOutput::create_testcase6_data () {

    QString name = "testcase6_data";
    QDomDocument doc;
    QDomElement Entrydir6Node = doc.createElement("directory");
    Entrydir6Node.setAttribute("filePath","C:/TDD_testdir/dir6");
    Entrydir6Node.setAttribute("fileName","dir6");
    doc.appendChild(Entrydir6Node);
    QDomElement Entrysdir1Node = doc.createElement("directory");
    Entrysdir1Node.setAttribute("filePath","C:/TDD_testdir/dir6/sdir1");
    Entrysdir1Node.setAttribute("fileName","sdir1");
    Entrydir6Node.appendChild(Entrysdir1Node);
    QDomElement Entryfile1Node = doc.createElement("file");
    Entryfile1Node.setAttribute("filePath","C:/TDD_testdir/dir6/file1");
    Entryfile1Node.setAttribute("fileName","file1");
    Entryfile1Node.setAttribute("size","C:/TDD_testdir/dir6/file1");
    Entryfile1Node.setAttribute("suffix","file1");
    Entrydir6Node.appendChild(Entryfile1Node);
    QDomElement Entryfile2Node = doc.createElement("file");
    Entryfile2Node.setAttribute("filePath","C:/TDD_testdir/dir6/file2");
    Entryfile2Node.setAttribute("fileName","file2");
    Entryfile2Node.setAttribute("size","C:/TDD_testdir/dir6/file2");
    Entryfile2Node.setAttribute("suffix","file2");
    Entrydir6Node.appendChild(Entryfile2Node);

    writeToFile(doc, name);
}

void xmlOutput::create_testcase7_data () {

    QString name = "testcase7_data";
    QDomDocument doc;
    QDomElement Entrydir7Node = doc.createElement("directory");
    Entrydir7Node.setAttribute("filePath","C:/TDD_testdir/dir7");
    Entrydir7Node.setAttribute("fileName","dir7");
    doc.appendChild(Entrydir7Node);
    QDomElement Entryfile1Node = doc.createElement("file");
    Entryfile1Node.setAttribute("filePath","C:/TDD_testdir/dir7/file1");
    Entryfile1Node.setAttribute("fileName","file1");
    Entryfile1Node.setAttribute("size","C:/TDD_testdir/dir7/file1");
    Entryfile1Node.setAttribute("suffix","file1");
    Entrydir7Node.appendChild(Entryfile1Node);
    QDomElement Entryfile2Node = doc.createElement("file");
    Entryfile2Node.setAttribute("filePath","C:/TDD_testdir/dir7/file2");
    Entryfile2Node.setAttribute("fileName","file2");
    Entryfile2Node.setAttribute("size","C:/TDD_testdir/dir7/file2");
    Entryfile2Node.setAttribute("suffix","file2");
    Entrydir7Node.appendChild(Entryfile2Node);

    writeToFile(doc, name);
}

void xmlOutput::create_testcase8_data () {

    QString name = "testcase8_data";
    QDomDocument doc;
    QDomElement Entrydir8Node = doc.createElement("directory");
    Entrydir8Node.setAttribute("filePath","C:/TDD_testdir/dir8");
    Entrydir8Node.setAttribute("fileName","dir8");
    doc.appendChild(Entrydir8Node);
    QDomElement Entryfile1Node = doc.createElement("file");
    Entryfile1Node.setAttribute("filePath","C:/TDD_testdir/dir8/file1");
    Entryfile1Node.setAttribute("fileName","file1");
    Entryfile1Node.setAttribute("size","C:/TDD_testdir/dir8/file1");
    Entryfile1Node.setAttribute("suffix","file1");
    Entrydir8Node.appendChild(Entryfile1Node);

    writeToFile(doc, name);
}


