#include<iostream>
#include"rectangleType.h"
using namespace std;
//overloading post and pre increment or decrement operators
rectangleType& rectangleType::operator++()
{
    this->length++;
    this->height++;
    return *this;
}
rectangleType& rectangleType::operator++(int)
{
    const rectangleType old(*this);
    ++(*this);
    return *this;
}
rectangleType& rectangleType::operator--()
{
    this->length--;
    this->height--;
    return *this;
}
rectangleType& rectangleType::operator--(int)
{
    const rectangleType old(*this);
    --(*this);
    return *this;
}
//overloadting binary operator -
rectangleType rectangleType::operator-(const rectangleType& rt)
{
    int lenght = this->length - rt.length;
    int height = this->height - rt.height;
    if (lenght < 0 || height < 0) {
        cout << "operation not posssible";
        rectangleType ob(0, 0);
        return ob;
    }
    rectangleType ob(lenght, height);
    return ob;
}
//overloading the relational operators
bool rectangleType::operator>(rectangleType& rt)
{
    if (area() > rt.area())
    {
        return true;
    }
    else
        return false;
}
bool rectangleType::operator<(rectangleType& rt)
{
    if (area() < rt.area())
    {
        return true;
    }
    else
        return false;
}
bool rectangleType::operator>=(rectangleType& rt)
{
    if (area() >= rt.area())
    {
        return true;
    }
    else
        return false;
}
bool rectangleType::operator<=(rectangleType& rt)
{
    if (area() <= rt.area())
    {
        return true;
    }
    else
        return false;
}
bool rectangleType::operator==(const rectangleType& rt)
{
    if (length == rt.length && height == rt.height)
        return true;
    else
        return false;
}
bool rectangleType::operator!=(const rectangleType& rt)
{
    if (length != rt.length && height != rt.height)
        return true;
    else
        return false;
}
void rectangleType::show()
{
    cout << length << "," << height << endl;
}
