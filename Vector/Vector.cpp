#include <iostream>
#include <exception>

#include "vector.h"

int Vector::m_arrayCounter = 0;

Vector::Vector(int size, int value)
    : m_size(size)
    , m_capacity(size + DEFAULT_SIZE)
{

    if(size < 0)
        throw std::exception("Wrong size!");

    m_arrayPtr = new int[ m_size + DEFAULT_SIZE ];

    std::fill_n(m_arrayPtr, m_size, value);

    m_arrayCounter++;
}

Vector::Vector(const Vector& vcp)
    : m_size(vcp.m_size)
    , m_capacity(vcp.m_capacity)
{
    m_arrayPtr = new int[ m_size + DEFAULT_SIZE ];
    ++m_arrayCounter;

    std::copy(vcp.m_arrayPtr, vcp.m_arrayPtr + vcp.m_size, m_arrayPtr);
}

Vector::~Vector()
{
    delete [] m_arrayPtr;
    --m_arrayCounter; 
}

Vector& Vector::operator= (const Vector& rhs)
{
    Vector temp(rhs);
    std::swap(m_size, temp.m_size);
    std::swap(m_arrayPtr, temp.m_arrayPtr);
    std::swap(m_capacity, temp.m_capacity);
 
    return *this; 
}

int& Vector::operator[] (int index)
{
    if(m_size == 0)
        throw std::exception("cannot access element, that doesn't exist!\n");

    if(index < 0 || index >= m_size)
        throw std::exception("index is out of range!\n"); 

    return m_arrayPtr[index];
}

const int& Vector::operator[] (int index) const
{
    if(m_size == 0)
        throw std::exception("cannot access element, that doesn't exist!\n");

    if(index < 0 || index >= m_size)
        throw std::exception("index is out of range!\n"); 

    return m_arrayPtr[index];
}

Vector Vector::operator+ (const Vector &rhs)
{
    if(m_size != rhs.m_size)
    throw std::exception("Size of arrays have to be equal\n");
    else
        {
            Vector temp(m_size,0);
            for(int i = 0; i < m_size; ++i)
                temp.m_arrayPtr[ i ] = m_arrayPtr[ i ] + rhs.m_arrayPtr[ i ];
            return temp;
        }
}

Vector Vector::operator* (const Vector &rhs)
{
    if(m_size == rhs.m_size)
    {
        Vector temp(m_size, 0);
        for(int i = 0; i < m_size; ++i)
           temp.m_arrayPtr[ i ] = m_arrayPtr[ i ] * rhs.m_arrayPtr[ i ];
        return temp;
    }
    else
        throw std::exception("Size of arrays have to be equal\n");
}

Vector operator+ (int value,const Vector& rhs)
{
    Vector temp(rhs.m_size, 0);
    for(int i = 0; i < rhs.m_size; ++i)
        temp.m_arrayPtr[i] = rhs.m_arrayPtr[ i ] + value;
    return temp;
}

Vector operator* (int value,const Vector& rhs)
{
   Vector temp(rhs.m_size, 0);
    for(int i = 0; i < rhs.m_size; ++i)
        temp.m_arrayPtr[i] = rhs.m_arrayPtr[ i ] * value;
    return temp; 
}

std::ostream& operator<< (std::ostream& os, const Vector& rhs)
{
    for(int i = 0; i < rhs.m_size; ++i)
        os << rhs.m_arrayPtr[ i ] << " ";
    return os;
}

std::istream& operator>> (std::istream& is, Vector& rhs)
{
    for(int i = 0; i < rhs.m_size; ++i)
        is >> rhs.m_arrayPtr[i];
    return is;
}


//returns quantity of elements of a vector
int Vector::size() const
{
    return m_size;
}

//returns vector size
int Vector::capacity() const
{
    return m_capacity;
}

void Vector::reverse()
{
    //int temp;
    for(int i = 0; i < m_size / 2; ++i)
    std::swap(m_arrayPtr[ i ], m_arrayPtr[ m_size - i - 1]);
}

void Vector::add(int value)
{
    if(m_size <= m_capacity)
    {
        m_arrayPtr[ m_size ] = value;
        m_size++;
    }
    else
    {
        int* arrayPtrTemp;
        arrayPtrTemp = new int[ m_size + DEFAULT_SIZE ];
        std::copy(m_arrayPtr, m_arrayPtr + m_size, arrayPtrTemp);
        arrayPtrTemp[ m_size + 1 ] = value;
        m_size++;
        delete[] m_arrayPtr;
        m_arrayPtr = arrayPtrTemp;
    }
}
