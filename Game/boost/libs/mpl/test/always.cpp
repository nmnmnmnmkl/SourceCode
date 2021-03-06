
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source: /CVSROOT/boost/libs/mpl/test/always.cpp,v $
// $Date: 2007/10/29 07:32:56 $
// $Revision: 1.1.1.1 $

#include <boost/mpl/apply.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>

#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef always<true_> always_true;

    MPL_ASSERT(( apply1< always_true,false_ > ));
    MPL_ASSERT(( apply2< always_true,false_,false_ > ));
    MPL_ASSERT(( apply3< always_true,false_,false_,false_ > ));
}


MPL_TEST_CASE()
{
    typedef always< int_<10> > always_10;    

    typedef apply1< always_10,int_<0> >::type res1;
    typedef apply2< always_10,int_<0>,int_<0> >::type res2;
    typedef apply3< always_10,int_<0>,int_<0>,int_<0> >::type res3;

    MPL_ASSERT_RELATION( res1::value, ==, 10 );
    MPL_ASSERT_RELATION( res2::value, ==, 10 );
    MPL_ASSERT_RELATION( res3::value, ==, 10 );
}
