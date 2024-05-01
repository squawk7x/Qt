#include <QCoreApplication>
#include <QTest>

#include "./../patternMaker.h"

class PatternSize : public QObject
{
    Q_OBJECT

public:
    PatternSize();
    ~PatternSize();

private:
    PatternMaker* pm;

private slots:
    // not treated as test functions:

    void initTestCase();
    // will be called before the first test function is executed

    void initTestCase_data();
    // will be called to create a global test data table

    void cleanupTestCase();
    // will be called after the last test function was executed

    void init();
    // will be called before each test function is executed

    void cleanup();
    // will be called after every test function

    // test functions:
    void test_case1();
};

PatternSize::PatternSize()
{
    pm = new PatternMaker(5);
}
PatternSize::~PatternSize()
{
    delete pm;
}
void PatternSize::initTestCase() {}
void PatternSize::initTestCase_data() {}
void PatternSize::cleanupTestCase() {}
void PatternSize::init() {}
void PatternSize::cleanup() {}

void PatternSize::test_case1()
{
    Q_ASSERT(pm->m_Hu.size() == 4);
}

QTEST_MAIN(PatternSize)

#include "tst_patternsize.moc"
