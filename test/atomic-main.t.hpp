//
// Copyright (c) 2020-2020 Martin Moene
//
// https://github.com/martinmoene/atomic-lite
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef TEST_ATOMIC_LITE_H_INCLUDED
#define TEST_ATOMIC_LITE_H_INCLUDED

#include "nonstd/atomic.hpp"

// Compiler warning suppression for usage of lest:

#ifdef __clang__
# pragma clang diagnostic ignored "-Wstring-conversion"
# pragma clang diagnostic ignored "-Wunused-parameter"
# pragma clang diagnostic ignored "-Wunused-template"
# pragma clang diagnostic ignored "-Wunused-function"
# pragma clang diagnostic ignored "-Wunused-member-function"
#elif defined __GNUC__
# pragma GCC   diagnostic ignored "-Wunused-parameter"
# pragma GCC   diagnostic ignored "-Wunused-function"
#endif

#include "lest_cpp03.hpp"

#define CASE( name ) lest_CASE( specification(), name )

// Attribute externally visible for -fwhole-program:

#if defined(__GNUC__) && !defined(__clang__)
# define any_ATTRIBUTE_EXT_VIS  __attribute__((externally_visible))
#else
# define any_ATTRIBUTE_EXT_VIS
#endif

extern lest::tests & specification() any_ATTRIBUTE_EXT_VIS;

namespace nonstd {

// use oparator<< instead of to_string() overload;
// see  http://stackoverflow.com/a/10651752/437272

template< typename T >
inline std::ostream & operator<<( std::ostream & os, nonstd::atomic<T> const & /*v*/ )
{
    return os << "[atomic:]";
}

}

namespace lest {

using ::nonstd::operator<<;

} // namespace lest

#endif // TEST_ATOMIC_LITE_H_INCLUDED

// end of file
