#include "patternMaker.h"
#include <chrono>

PatternMaker::PatternMaker(int base)
{
    m_base = base;                  // base     2   3   4   5  6 10 12
    m_Hu.resize((24 - 1) / m_base); // lights  11   7   5   4  3  2  1
    m_Hl.resize(m_base - 1);        // lights   1   2   3   4  5  9 11
    m_Mu.resize(60 / m_base - 1);   // lights  29  19  14  11  9  5  4
    m_Ml.resize(m_base - 1);        // lights   1   2   3   4  5  9 11
    m_Su.resize(60 / m_base - 1);   // lights  29  19  14  11  9  5  4
    m_Sl.resize(m_base - 1);        // lights   1   2   3   4  5  9 11
}

void PatternMaker::makePatterns()
{
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // e.g. 07:33:12
    std::tm* localTime = std::localtime(&currentTime);
    int Hu = localTime->tm_hour / m_base; // e.g. 1 1x5
    int Hl = localTime->tm_hour % m_base; // e.g. 2 +2
    int Mu = localTime->tm_min / m_base;  // e.g. 6 6x5
    int Ml = localTime->tm_min % m_base;  // e.g. 3 +3
    int Su = localTime->tm_sec / m_base;  // e.g. 2 2x5
    int Sl = localTime->tm_sec % m_base;  // e.g. 2 +2

    // Clear each vector
    m_Hu.clear();
    m_Hl.clear();
    m_Mu.clear();
    m_Ml.clear();
    m_Su.clear();
    m_Sl.clear();

    // Populate vectors based on current time
    for (int k = 0; k < (24 - 1) / m_base; k++) {
        m_Hu.push_back(Hu > k); // e.g. 1 0 0 0
    }

    for (int k = 0; k < m_base - 1; k++) {
        m_Hl.push_back(Hl > k); // e.g. 1 1 0 0
        m_Ml.push_back(Ml > k); // e.g. 1 1 1 0
        m_Sl.push_back(Sl > k); // e.g. 1 1 0 0
    }
    for (int k = 0; k < 60 / m_base - 1; k++) {
        m_Mu.push_back(Mu > k); // e.g. 1 1 1 1 1 1 0 0 0 0 0
        m_Su.push_back(Su > k); // e.g. 1 1 0 0 0 0 0 0 0 0 0
    }
}
