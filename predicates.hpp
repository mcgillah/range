#ifndef __PREDICATES_HPP_2012_01_28__
#define __PREDICATES_HPP_2012_01_28__

namespace NRange
{
    class TSame
    {
        const bool Value_;

    public:
        inline TSame(bool value)
            : Value_(value)
        {
        }

        inline bool operator ()() const
        {
            return Value_;
        }
    };

    template <class TPred>
    class TNot
    {
        const TPred Pred_;

    public:
        inline TNot(const TPred& pred)
            : Pred_(pred)
        {
        }

        inline bool operator ()() const
        {
            return !Pred_();
        }
    };

    template <class TPred>
    static inline TNot<TPred> Not(const TPred& pred)
    {
        return TNot<TPred>(pred);
    }

    template <class TClass, class TPred>
    class TBindMember
    {
        const TClass* const This_;
        const TPred Pred_;

    public:
        inline TBindMember(const TClass* pthis, const TPred& pred)
            : This_(pthis)
            , Pred_(pred)
        {
        }

        inline bool operator ()() const
        {
            return (This_->*Pred_)();
        }
    };

    template <class TClass, class TPred>
    static inline TBindMember<TClass, TPred> BindMember(const TClass* pthis,
        const TPred& pred)
    {
        return TBindMember<TClass, TPred>(pthis, pred);
    }
}

#endif

