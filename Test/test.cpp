#include "../Vector/vector.h"

#define BOOST_TEST_MODULE testVector

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

using namespace boost::unit_test;
using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_SUITE(serviceMethods)

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

    BOOST_CHECK_THROW(Vector vect3(-3,5), std::exception);
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

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(userMethods)
BOOST_AUTO_TEST_CASE(push_backInt)
{
    Vector v(1,1);
    for(int i = 0; i < 15; ++i)
        v.push_back(1);
    BOOST_CHECK_EQUAL(v[v.size() - 1], 1);
}

BOOST_AUTO_TEST_CASE(reverseTest)
{
    Vector v(1,1);
    v.push_back(2);
    v.push_back(3);
    v.reverse();


    for(int i = v.size() - 1, j = 1; i > 0, j <= v.size() - 1; --i, ++j)
        BOOST_CHECK_EQUAL(v[i], j);
}

BOOST_AUTO_TEST_CASE(capacityTest)
{
    Vector v1(4,3);
    BOOST_CHECK_EQUAL(v1.capacity(), 14);
    
    Vector v2;
    BOOST_CHECK_EQUAL(v2.capacity(), 10);
}

BOOST_AUTO_TEST_CASE(sizeTest)
{
    Vector v3;
    BOOST_CHECK_EQUAL(v3.size(), 0);

    v3.push_back(2);
    BOOST_CHECK_EQUAL(v3.size(), 1);
}

BOOST_AUTO_TEST_CASE(beginEndTest)
{
    Vector vv;
    vv.push_back(2);
    vv.push_back(3);
    vv.push_back(1);
    std::reverse(vv.begin(), vv.end());
    BOOST_CHECK_EQUAL(vv[0], 1);
    BOOST_CHECK_EQUAL(vv[2], 2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(overloadedOperatorsTest)
BOOST_AUTO_TEST_CASE(operatorEqualTest)
{
    Vector v4(3, 3);
    Vector v5(3, 1);
    
    v5 = v4;
    for(int i = 0; i < v5.size(); ++i)
        BOOST_CHECK_EQUAL(v5[i], v4[i]);

    v4[1] = 80;
    BOOST_CHECK(v5[1] != 80);

    Vector v6(6,6);
    v4 = v6;
    for(int i = 0; i < v4.size(); ++i)
        BOOST_CHECK_EQUAL(v6[i], v4[i]);
}

BOOST_AUTO_TEST_CASE(operatorPlusTest)
{
    Vector v7(3, 4);
    Vector v8(3, 11);
    Vector v9(0, 0);
    
    v9 = v8 + v7;
    for(int i = 0; i < v8.size(); ++i)
        BOOST_CHECK_EQUAL(v9[i], 15);

    Vector v10(2,2);
    BOOST_CHECK_THROW(v9 = v8 + v10;, std::exception);

    Vector v11(3,0);
    v7 = v11 + v8;
     for(int i = 0; i < v7.size(); ++i)
        BOOST_CHECK_EQUAL(v7[i], 11);
}


BOOST_AUTO_TEST_CASE(operatorMultiplyTest)
{
    Vector v12(3, 4);
    Vector v13(3, 11);
    Vector v14(0, 0);
    
    v14 = v12 * v13;
    for(int i = 0; i < v12.size(); ++i)
        BOOST_CHECK_EQUAL(v14[i], 44);

    Vector v15, v17;
    BOOST_CHECK_THROW(v15 = v12 * v17;, std::exception);

    Vector v16(3,0);
    v14 = v16 * v13;
    for(int i = 0; i < v14.size(); ++i)
        BOOST_CHECK_EQUAL(v14[i], 0);
}

BOOST_AUTO_TEST_CASE(operatorPlusIntTest)
{
    Vector test, res;
    int integer = 10;
    test.push_back(3);
    test.push_back(5);

    res = integer + test;
    BOOST_CHECK_EQUAL(test[0], 3);
    BOOST_CHECK_EQUAL(res[0], 13);
    BOOST_CHECK(res[1] == 15);

    integer = -4;
    Vector res2;
    res2 = integer + test;
    BOOST_CHECK_EQUAL(res2[0], -1);
    BOOST_CHECK(res2[1] == 1);

    integer = 0;
    Vector res3;
    res3 = integer + test;
    BOOST_CHECK_EQUAL(res3[0], 3);
    BOOST_CHECK(res3[1] == 5);

    Vector test2, res4;
    integer = 5;
    BOOST_CHECK_THROW(res4 = integer + test2, std::exception);

}

BOOST_AUTO_TEST_CASE(operatorMultiplyIntTest)
{
    Vector test, res;
    int integer = 5;
    test.push_back(2);
    test.push_back(3);

    res = integer * test;
    BOOST_CHECK_EQUAL(test[0], 2);
    BOOST_CHECK_EQUAL(res[0], 10);
    BOOST_CHECK(res[1] == 15);

    integer = -4;
    Vector res2;
    res2 = integer * test;
    BOOST_CHECK_EQUAL(res2[0], -8);
    BOOST_CHECK(res2[1] == -12);

    integer = 0;
    Vector res3;
    res3 = integer * test;
    BOOST_CHECK_EQUAL(res3[0], 0);
    BOOST_CHECK(res3[1] == 0);

    Vector test2, res4;
    integer = 5;
    BOOST_CHECK_THROW(res4 = integer * test2, std::exception);
}


BOOST_AUTO_TEST_CASE(operatorIndexTest)
{
    Vector test;
    BOOST_CHECK_THROW(test[0], std::exception);

    test.push_back(3);
    test.push_back(4);
    BOOST_CHECK_EQUAL(test[0], 3);
    BOOST_CHECK_EQUAL(test[1], 4);

    BOOST_CHECK_THROW(test[-1], std::exception);
    BOOST_CHECK_THROW(test[100], std::exception);

    /* index double ??? */
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(outputTest)

BOOST_AUTO_TEST_CASE(operatorOutTest)
{
    output_test_stream output;
    Vector test(3,4);
    output << "Vector: " << test;
    BOOST_CHECK( !output.is_empty(false) );
    BOOST_CHECK( output.is_equal("Vector: 4 4 4 ") );
}

BOOST_AUTO_TEST_SUITE_END()



