#include <iostream>
#include "vector.h"

int main()
{
    Vector vec(2,3);
    vec.null();
    std::cout << vec << std::endl;
    if(vec.empty())
        std::cout << "Vector is not empty!\n";

    for(int i = 0; i < 10; ++i)
        vec.push_back(3);

    std::cout << vec.capacity() << std::endl;
    int mas[] = {2,3,4,5,6,7,8,9,10,11};
    
    try 
    {
        //vec.insert(1, 2);
        //std::cout << vec << std::endl;
        //std::cout << vec.capacity() << std::endl;
        //vec.insert(mas, mas + 10, 1);
        //std::cout << vec << std::endl;
        //std::cout << vec.capacity() << std::endl;
        //vec.erase(mas, mas + 10, 1);
        //std::cout << vec << std::endl;
        //std::cout << vec.capacity() << std::endl;
        //vec.clear();
        //std::cout << vec.capacity() << std::endl;
        //

        //Vector vector(3,3);
        //vector[100];  

        //Vector vector2(-3,2);
        //
        //Vector vector3;
        //vector3[0];

    }
    catch(Vector::ArrayNotEqual)
    {
        std::cerr << "Exception: " << "Size of arrays has to be equal.\n";
    }
    catch(Vector::ElementNotExists)
    {
        std::cerr << "Exception: " << "Cannot access element, that doesn't exist.\n";
    }
    catch(Vector::UninitializedVector)
    {
        std::cerr << "Exception: " << "Vector is uninitialized.\n";
    }
    catch(Vector::WrongIndex)
    {
        std::cerr << "Exception: " << "Index is out of range.\n";
    }
    catch(...)
    {
        std::cerr << "An exception of undefined type has been raised.\n";
    }

    return 0;
} 

