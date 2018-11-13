#include <QString>
#include <QtTest>
#include "directoryhierarchy.h"
#include "xmloutput.h"
using namespace std;


class TestTest : public QObject
{
    Q_OBJECT

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
    void testCase1();
};

TestTest::TestTest()
{
}

TestTest::~TestTest()
{
    cleanDataSet();
}

//void TestTest::createTestDir(QString path)
//{
//    QDir cdir(QDir::current());
//    QDir dir(path);
//    if(!dir.exists())
//        {
//            qDebug() << "Creating " << path << "directory";
//            cdir.mkpath(path);
//        }
//        else
//        {
//            qDebug() << path << " already exists";
//        }
//}

//void TestTest::createTestFile(QString fileName)
//{
//    QFile file(fileName);
//        // Trying to open in WriteOnly and Text mode
//        if(!file.open(QFile::WriteOnly |
//                      QFile::Text))
//        {
//            qDebug() << " Could not open file for writing";
//            return;
//        }

//        // To write text, we use operator<<(),
//        // which is overloaded to take
//        // a QTextStream on the left
//        // and data types (including QString) on the right

//        QTextStream out(&file);
//        out << "test file";
//        file.flush();
//        file.close();
//}

//void TestTest::createTestHierarchy()
//{
//    QString path = "tmp";
//    createTestDir(path);
//     path = "tmp/dir1";
//     createTestDir(path);
//     qDebug() << QDir::currentPath();
//     path = "tmp/dir2";
//     createTestDir(path);
//     qDebug() << QDir::currentPath();
//     createTestDir("tmp/dir2");
//     createTestDir(path);
//     qDebug() << QDir::currentPath();
//     path = "tmp/dir4";
//     createTestDir(path);
//     path = "tmp/dir5";
//     createTestDir(path);
//     path = "tmp/dir6";
//     createTestDir(path);
//     path = "tmp/dir7";
//     createTestDir(path);
//     path = "tmp/dir8";
//     createTestDir(path);
//     path = "tmp/dir2/sdir1";
//     createTestDir(path);

//     path = "tmp/dir3/sdir1";
//     createTestDir(path);
//     path = "tmp/dir3/sdir2";
//     createTestDir(path);
//       qDebug() << QDir::currentPath();
//     path = "tmp/dir4/sdir1";
//     createTestDir(path);
//     qDebug() << QDir::currentPath();
//     path = "tmp/dir4/sdir2";
//     createTestDir(path);
//     qDebug() << QDir::currentPath();
//     path = "tmp/dir4/file1";
//     createTestFile(path);

//     path = "tmp/dir5/sdir1";
//     createTestDir(path);
//     path = "tmp/dir5/sdir2";
//     createTestDir(path);
//     path = "tmp/dir5/file1";
//     createTestFile(path);
//     path = "tmp/dir5/file2";
//     createTestFile(path);
//     path = "tmp/dir6/sdir1";
//     createTestDir(path);
//     path = "tmp/dir6/file1";
//     createTestFile(path);
//     path = "tmp/dir6/file2";
//     createTestFile(path);

//     path = "tmp/dir7/file1";
//     createTestFile(path);
//     path = "tmp/dir7/file2";
//     createTestFile(path);

//     path = "tmp/dir8/file1";
//     createTestFile(path);
//}

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


void TestTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void TestTest::testCase1()
{
    initDataSet();
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
