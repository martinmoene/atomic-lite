//
// Copyright (c) 2020-2020 Martin Moene
//
// https://github.com/martinmoene/atomic-lite
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "atomic-main.t.hpp"

// Suppress:
// - unused parameter, for cases without assertions such as [.std...]
#if defined(__clang__)
# pragma clang diagnostic ignored "-Wunneeded-member-function"
#elif defined __GNUC__
//# pragma GCC   diagnostic ignored ""
#endif

// Note: use any_cast( ptr-to-any ) to preserve move-state.

using namespace nonstd;

namespace {

} // anonymous namespace

//
// atomic...:
//

CASE( "atomic: ..." )
{
}

#if atomic_CPP11_110
#include <thread>
#endif

#include <vector>
#include <iostream>
//#include <atomic>

nonstd::atomic_flag lock = ATOMIC_FLAG_INIT;

void f( int n )
{
	for (int cnt = 0; cnt < 4; ++cnt)
	{
		// acquire lock:
		while ( lock.test_and_set(nonstd::memory_order_acquire) )
		{
			// spin read: only until a cmpxchg might succeed:
//			while( *p )
				_mm_pause();
		}

		std::cout << "Output from thread " << n << '\n';

		// release lock:
		lock.clear(nonstd::memory_order_release);
	}
}

CASE( "atomic: app " "[app]" )
{
#if atomic_CPP11_110
	std::vector<std::thread> v;

	for (int n = 0; n < 3; ++n)
	{
		v.emplace_back(f, n);
	}

	for (auto& t : v)
	{
		t.join();
	}
#else
#endif
}

// end of file
