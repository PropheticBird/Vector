#include "../Vector/vector.h"

#define BOOST_TEST_MODULE testVector

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(initializationVector)
{
    Vector vect(0,0);
    BOOST_CHECK_EQUAL(vect.size(), 0);
    Vector vect1(5);
    for(int i = 0; i < vect1.size(); ++i)
        BOOST_CHECK_EQUAL(vect1[i], 0);
    Vector vect2(14,7);
    for(int i = 0; i < vect2.size(); ++i)
        BOOST_CHECK_EQUAL(vect2[i], 7);
}

BOOST_AUTO_TEST_CASE(copyConstructor)
{
    Vector src(18,8);
    Vector dest(src);
    for(int i = 0; i < dest.size(); ++i)
        BOOST_CHECK_EQUAL(dest[i], src[i]);
    src[3] = 80;
    BOOST_CHECK_EQUAL(dest[3], 8);
}


BOOST_AUTO_TEST_CASE(addInt)
{
    Vector vector(1,1);
    for(int i = 0; i < 15; ++i)
        vector.add(1);
    //for(int i = 0; i < vector.size(); ++i)
    BOOST_CHECK_EQUAL(vector[vector.size() - 1], 1);
}





