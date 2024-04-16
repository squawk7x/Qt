#ifndef PATTERNMAKER_H
#define PATTERNMAKER_H

#include <vector>

class PatternMaker
{
private:
    int m_base;

public:
    std::vector<bool> m_Hu; // pattern of upper hour indicator
    std::vector<bool> m_Hl; // pattern of lower hour indicator
    std::vector<bool> m_Mu; // pattern of upper minutes indicator
    std::vector<bool> m_Ml; // pattern of lower minutes indicator
    std::vector<bool> m_Su; // pattern of upper seconds indicator
    std::vector<bool> m_Sl; // pattern of lower seconds indicator

public:
    PatternMaker(int base);

    void makePatterns();
};

#endif // PATTERNMAKER_H
