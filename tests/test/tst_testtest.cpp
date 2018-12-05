#include <QString>
#include <QtTest>
#include <QXmlQuery>
#include "directoryhierarchy.h"
#include "xmloutput.h"
#include "../../src/App/query.h"
#include "filetree.h"
#include <QXmlFormatter>
using namespace std;


class TestTest : public QObject
{
    Q_OBJECT

    const QXmlNamePool  m_namePool;
    const FileTree      m_fileTree;
    QXmlNodeModelIndex  m_fileNode;

public:
    TestTest();
    ~TestTest();

private:
    void initDataSet();
    void cleanDataSet();
    // void createTestHierarchy();
    // void createTestDir(QString path);
    // void createTestFile(QString fileName);

private Q_SLOTS:
    void testCase1_data();
    void testCase2_data();
    void testCase3_data();
    void testCase4_data();
    void testCase5_data();
    void testCase6_data();
    void testCase7_data();
    void testCase8_data();
    void testCase1();
    //    void testCase2();
    //    void testCase3();
    //    void testCase4();
    //    void testCase5();
    //    void testCase6();
    //    void testCase7();
    //    void testCase8();
};
TestTest::TestTest() : m_fileTree(m_namePool)
{
}

TestTest::~TestTest()
{
    cleanDataSet();
}

void TestTest::initDataSet()
{
    directoryHierarchy* test_hierarchy = new directoryHierarchy();
    test_hierarchy->createTestHierarchy();

    xmlOutput* output = new xmlOutput();
    output->create_testcase1_data();
    output->create_testcase2_data();
    output->create_testcase3_data();
    output->create_testcase4_data();
    output->create_testcase5_data();
    output->create_testcase6_data();
    output->create_testcase7_data();
    output->create_testcase8_data();
}

void TestTest::cleanDataSet()
{
    QString path = "tmp";
    QDir dir(path);
    dir.removeRecursively();
}

void TestTest::testCase1_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir1") << "directory"<< "tmp/dir1" <<"dir1"<<"0"<<"";
}
void TestTest::testCase2_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir2") << "directory"<< "tmp/dir2"<<"dir2"<<"0"<<"";
    QTest::newRow("sdir1") << "directory"<< "tmp/dir2/sdir1"<<"sdir1"<<"0"<<"";
}
void TestTest::testCase3_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir3") << "directory"<< "tmp/dir3"<<"dir3"<<"0"<<"";
    QTest::newRow("sdir1") << ""<< "tmp/dir3/sdir1"<<"sdir1"<<"0"<<"";
    QTest::newRow("sdir2") << ""<< "tmp/dir3/sdir2"<<"sdir2"<<"0"<<"";
}
void TestTest::testCase4_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir4") << "directory"<< "tmp/dir4"<<"dir4"<<"0"<<"";
    QTest::newRow("sdir1") << ""<< "tmp/dir4/sdir1"<<"sdir1"<<"0"<<"";
    QTest::newRow("sdir2") << ""<< "tmp/dir4/sdir2"<<"sdir2"<<"0"<<"";
    QTest::newRow("file1") << ""<< "tmp/dir4/file1"<<"file1"<<"0"<<"";
}
void TestTest::testCase5_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir5") << ""<< "tmp/dir5"<<"dir5"<<"0"<<"";
    QTest::newRow("sdir1") << ""<< "tmp/dir5/sdir1"<<"sdir1"<<"0"<<"";
    QTest::newRow("sdir2") << ""<< "tmp/dir5/sdir2"<<"sdir2"<<"0"<<"";
    QTest::newRow("file1") << ""<< "tmp/dir5/file1"<<"file1"<<"0"<<"";
    QTest::newRow("file2") << ""<< "tmp/dir5/file2"<<"file2"<<"0"<<"";
}
void TestTest::testCase6_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir6") << ""<< "tmp/dir6"<<"dir6"<<"0"<<"";
    QTest::newRow("sdir1") << ""<< "tmp/dir6/sdir1"<<"sdir1"<<"0"<<"";
    QTest::newRow("file1") << ""<< "tmp/dir6/file1"<<"file1"<<"0"<<"";
    QTest::newRow("file2") << ""<< "tmp/dir6/file2"<<"file2"<<"0"<<"";
}
void TestTest::testCase7_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir7") << ""<< "tmp/dir7"<<"dir7"<<"0"<<"";
    QTest::newRow("file1") << ""<< "tmp/dir7/file1"<<"file1"<<"0"<<"";
    QTest::newRow("file2") << ""<< "tmp/dir7/file2"<<"file2"<<"0"<<"";
}
void TestTest::testCase8_data(){
    QTest::addColumn<QString>("element");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("size");
    QTest::addColumn<QString>("suffix");
    QTest::newRow("dir8") << ""<< "tmp/dir8"<<"dir8"<<"0"<<"";
    QTest::newRow("file1") << ""<< "tmp/dir8/file1"<<"file1"<<"0"<<"";
}

void TestTest::testCase1()
{
    initDataSet();
    QFETCH(QString, element);
    QFETCH(QString, filePath);
    QFETCH(QString, fileName);
    QFETCH(QString, size);
    QFETCH(QString, suffix);
    QVERIFY2(true, "Failure");

    m_fileNode = m_fileTree.nodeFor("tmp/dir5");
    QXmlQuery query(m_namePool);
    query.bindVariable("fileTree", m_fileNode);
    query.setQuery(QUrl("qrc:/queries/wholeTree.xq"));

    QByteArray output;
    QBuffer buffer(&output);
    buffer.open(QIODevice::WriteOnly);

    QXmlFormatter formatter(query, &buffer);
    query.evaluateTo(&formatter);

qDebug() << "Result";
    qDebug() << QString::fromLatin1(output.constData());


    //Query* query = new Query();
    //QDomDocument* doc = query->queryDirectory("tmp/dir1");
    //QDomElement element = doc.getElement();

    //QCOMPARE()

    //    QTest::addColumn<QString>("element");
    //    QTest::addColumn<QString>("filePath");
    //    QTest::addColumn<QString>("fileName");
    //    QTest::addColumn<QString>("size");
    //    QTest::addColumn<QString>("suffix");
    //    QTest::newRow("dir1") << "directory"<< "tmp/dir1" <<"dir1"<<"0"<<"";
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
