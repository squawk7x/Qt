
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "./../patternMaker.h"

using namespace testing;

TEST(PatternTest, PatternSize)
{
    PatternMaker* pm = new PatternMaker(5);

    ASSERT_EQ(pm->m_Hu.size(), 4);

    delete pm;
}
