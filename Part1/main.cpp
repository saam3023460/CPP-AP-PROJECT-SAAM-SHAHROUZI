#include <iostream>
#include <ctime>
#include "vector.h"
#include "vector2ptr.h"
#include "shape_pt1.h"

double VECTOR_INSERT_AVG = 0;
double VECTOR_REMOVE_AVG = 0;
double VECTOR_POINTER_INSERT_AVG = 0;
double VECTOR_POINTER_REMOVE_AVG = 0;

void TestVector()
{
    Vector<Shape> vector(100);

    double VECTOR_INSERT_SUM = 0;
    double VECTOR_REMOVE_SUM = 0;

    std::clock_t begin;
    std::clock_t end;

    for (int i = 0; i < 10; i++)
    {
        begin = std::clock();
        vector.insert(Shape(2), 0);
        end = std::clock();

        VECTOR_INSERT_SUM += 1000.0 * (end - begin) / CLOCKS_PER_SEC;
    }

    VECTOR_INSERT_AVG = VECTOR_INSERT_SUM / 10;

    for (int i = 0; i < 10; i++)
    {
        begin = std::clock();
        vector.remove(0);
        end = std::clock();

        VECTOR_REMOVE_SUM += 1000.0 * (end - begin) / CLOCKS_PER_SEC;
    }

    VECTOR_REMOVE_AVG = VECTOR_REMOVE_SUM / 10;
}

void TestVectorPtr()
{
    VectorPtr<Shape> vector2(100);

    double VECTOR_POINTER_INSERT_SUM = 0;
    double VECTOR_POINTER_REMOVE_SUM = 0;

    std::clock_t begin;
    std::clock_t end;

    for (int i = 0; i < 10; i++)
    {
        begin = std::clock();
        vector2.insert(Shape(2), 0);
        end = std::clock();

        VECTOR_POINTER_INSERT_SUM += 1000.0 * (end - begin) / CLOCKS_PER_SEC;
    }

    VECTOR_POINTER_INSERT_AVG = VECTOR_POINTER_INSERT_SUM / 10;

    for (int i = 0; i < 10; i++)
    {
        begin = std::clock();
        vector2.remove(0);
        end = std::clock();

        VECTOR_POINTER_REMOVE_SUM += 1000.0 * (end - begin) / CLOCKS_PER_SEC;
    }

    VECTOR_POINTER_REMOVE_AVG = VECTOR_POINTER_REMOVE_SUM / 10;
}

int main()
{
    TestVector();
    TestVectorPtr();

    std::cout << "average insertion time for Vector in milliseconds: " << VECTOR_INSERT_AVG << std::endl;
    std::cout << "average remove time for Vector in milliseconds: " << VECTOR_REMOVE_AVG << std::endl;
    std::cout << "average insertion time for VectorPtr in milliseconds: " << VECTOR_POINTER_INSERT_AVG << std::endl;
    std::cout << "average remove time for VectorPtr in milliseconds: " << VECTOR_POINTER_REMOVE_AVG << std::endl;
    
    std::cin.get();

    return 0;
}
