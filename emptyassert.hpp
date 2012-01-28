#ifndef __EMPTYASSERT_HPP_2012_01_28__
#define __EMPTYASSERT_HPP_2012_01_28__

namespace NRange
{
    struct TEmptyAssert
    {
        template <class TPred, class TMessage>
        static inline void Assert(TPred, TMessage)
        {
        }
    };
}

#endif

