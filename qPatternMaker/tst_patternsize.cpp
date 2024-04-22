#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include "./../patternMaker.h"

class PatternSize : public QObject
{
    Q_OBJECT

public:
    PatternSize();
    ~PatternSize();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

PatternSize::PatternSize() {}

PatternSize::~PatternSize() {}

void PatternSize::initTestCase() {}

void PatternSize::cleanupTestCase() {}

void PatternSize::test_case1()
{
    PatternMaker* pm = new PatternMaker(5);

    Q_ASSERT(pm->m_Hu.size() == 4);

    delete pm;
}

QTEST_MAIN(PatternSize)

#include "tst_patternsize.moc"
