#include <cstdio>
#include "range.hpp"

using namespace NRange;

template <class TRange>
void print(TRange range)
{
    for(int i = 0; !range.IsEmpty() && i < 77; range.Pop(), ++i)
    {
        putchar(48 + range.Front());
    }
    puts("");
}

int main()
{
    print(SingleValue(1) * 5);
    print(ComposeRange(SingleValue(1), SingleValue(2), SingleValue(3)) * 4);
    print(ComposeRange(SingleValuesList(1, 3, 5) * 2, SingleValue(-16)) * TInfiniteCounter());
}
