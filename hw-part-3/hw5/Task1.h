#pragma once

template<typename Iter>
void printUniqueWords(const Iter& begin,const Iter& end)
{
    for (Iter p1 = begin; p1 != end; ++p1)
    {
        Iter p2;
        for (p2 = begin; p2 != p1; ++p2)
            if (*p1 == *p2)
                break;
        if (p1 == p2)
            std::cout << *p1 << ' ';
    }
    std::cout << std::endl;
}