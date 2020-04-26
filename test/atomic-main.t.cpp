//
// Copyright (c) 2020-2020 Martin Moene
//
// https://github.com/martinmoene/atomic-lite
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "atomic-main.t.hpp"

#define atomic_PRESENT( x ) \
    std::cout << #x << ": " << x << "\n"

#define atomic_ABSENT( x ) \
    std::cout << #x << ": (undefined)\n"

lest::tests & specification()
{
    static lest::tests tests;
    return tests;
}

CASE( "atomic-lite version" "[.atomic][.version]" )
{
}

CASE( "atomic-lite configuration" "[.atomic][.config]" )
{
}

CASE( "__cplusplus" "[.stdc++]" )
{
	atomic_PRESENT( __cplusplus );

#ifdef _MSVC_LANG
	atomic_PRESENT( _MSVC_LANG );
#else
	atomic_ABSENT(  _MSVC_LANG );
#endif
}

CASE( "Compiler version" "[.compiler]" )
{
#if atomic_USES_STD_atomic
    std::cout << "(Compiler version not available: using std::atomic)\n";
#else
	// atomic_PRESENT( atomic_COMPILER_CLANG_VERSION );
	// atomic_PRESENT( atomic_COMPILER_GNUC_VERSION );
	// atomic_PRESENT( atomic_COMPILER_MSVC_VERSION );
#endif
}

CASE( "Presence of C++ language features" "[.stdlanguage]" )
{
#if atomic_USES_STD_atomic
    std::cout << "(Presence of C++ language features not available: using std::atomic)\n";
#else
#endif
}

CASE( "Presence of C++ library features" "[.stdlibrary]" )
{
#if atomic_USES_STD_atomic
    std::cout << "(Presence of C++ library features not available: using std::atomic)\n";
#else
#endif

#if defined _HAS_CPP0X
    atomic_PRESENT( _HAS_CPP0X );
#else
    atomic_ABSENT(  _HAS_CPP0X );
#endif
}

int main( int argc, char * argv[] )
{
    return lest::run( specification(), argc, argv );
}

#if 0
g++            -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass
g++ -std=c++98 -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass
g++ -std=c++03 -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass
g++ -std=c++0x -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass
g++ -std=c++11 -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass
g++ -std=c++14 -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass
g++ -std=c++17 -I../include -o atomic-lite.t.exe atomic-main.t.cpp && atomic-lite.t.exe --pass

cl -EHsc -I../include atomic-main.t.cpp && atomic-lite.t.exe --pass
#endif

// end of file
