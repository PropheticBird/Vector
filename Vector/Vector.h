#ifndef VECTOR_H_
#define VECTOR_H_

#include <iosfwd>

class Vector
{
    friend std::ostream& operator<< (std::ostream&, const Vector&);
    friend std::istream& operator>> (std::istream&, Vector&);

    friend Vector operator+ (int, const Vector&);
    friend Vector operator* (int, const Vector&);

public:
    Vector(int = 0, int = DEFAULT_VALUE);
    Vector(const Vector&);
    ~Vector();

    int size() const;
    int capacity() const;
    void reverse();
    void add(int);

    Vector& operator= (const Vector&);
    Vector operator+ (const Vector&);
    Vector operator* (const Vector&); 
    int& operator[] (int);
    const int& operator[] (int) const;
     
private:
    static const int DEFAULT_SIZE = 10;
    static const int DEFAULT_VALUE = 0;
    static int m_arrayCounter;

    int m_capacity;
    int m_size;
    int* m_arrayPtr;
};

#endif/* VECTOR_H_ */