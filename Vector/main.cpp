#include <iostream>
#include "vector.h"

int main()
{
    Vector v;
    Vector v1(2,4);
    Vector v2(v1);
    v2.add(10);
    std::cout<<v2<<std::endl;
    v1.add(20);
    v = v2 * v1;
    std::cout<<v<<std::endl;
    v = v2 + v1;
    std::cout<<v<<std::endl;
    v.add(20);
    std::cout << v[3] << std::endl;
    v.reverse();
    std::cout<<v<<std::endl;
    std::cout << "Vector capacity is: " << v.capacity() << " \n"
        << v.size() << " elements are in vector now\n";
	return 0;
} 