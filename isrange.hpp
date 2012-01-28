/*
 * isrange.hpp              -- range detecting trait
 *
 * Copyright (C) 2012 Dmitry Potapov <potapov.d@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __ISRANGE_HPP_2012_01_28__
#define __ISRANGE_HPP_2012_01_28__

namespace NRange
{
    template <class TRange>
    class TIsRange
    {
        typedef char TTwoChars[2];

        template <class T>
        static char Test(typename T::TType_*, typename T::TAssert_*,
            typename T::TRangeTag_*);

        template <class>
        static TTwoChars& Test(...);

    public:
        static const bool Value_ = sizeof(Test<TRange>(0, 0, 0)) == 1;
    };
}

#endif

