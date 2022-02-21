#include "numbers.h"
#include <string>
#include <cmath>
#include <stack>


void Check(std::string request, int power)
{
    if (power == 2)
    {
        for (char c : request)
        {
            if (c != '0' && c != '1')
            {
                throw std::logic_error("Invalid number");
            }
        }
    }
    else if (power == 8)
    {
        for (char c : request)
        {
            if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7')
            {
                throw std::logic_error("Invalid number");
            }
        }
    }
    else if (power == 16)
    {
        for (char c : request)
        {
            if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != 'A' && c != 'B' && c != 'C' && c != 'D' && c != 'E' && c != 'F')
            {
                throw std::logic_error("Invalid number");
            }
        }
    }
    else
    {
        throw std::logic_error("Wrong power of number");
    }
}

int charToDec(char c)
{
    if (c == '0')
    {
        return 0;
    }

    else if (c == '1')
    {
        return 1;
    }
    else if (c == '2')
    {
        return 2;
    }
    else if (c == '3')
    {
        return 3;
    }
    else if (c == '4')
    {
        return 4;
    }
    else if (c == '5')
    {
        return 5;
    }
    else if (c == '6')
    {
        return 6;
    }
    else if (c == '7')
    {
        return 7;
    }
    else if (c == '8')
    {
        return 8;
    }
    else if (c == '9')
    {
        return 9;
    }
    else if (c == 'A')
    {
        return 10;
    }
    else if (c == 'B')
    {
        return 11;
    }
    else if (c == 'C')
    {
        return 12;
    }
    else if (c == 'D')
    {
        return 13;
    }
    else if (c == 'E')
    {
        return 14;
    }
    else if (c == 'F')
    {
        return 15;
    }
    else
    {
        return 0;
        throw std::logic_error("???");
    }
}
char decToChar(int d)
{
    if (d == 0)
    {
        return '0';
    }
    else if (d == 1)
    {
        return '1';
    }
    else if (d == 2)
    {
        return '2';
    }
    else if (d == 3)
    {
        return '3';
    }
    else if (d == 4)
    {
        return '4';
    }
    else if (d == 5)
    {
        return '5';
    }
    else if (d == 6)
    {
        return '6';
    }
    else if (d == 7)
    {
        return '7';
    }
    else if (d == 8)
    {
        return '8';
    }
    else if (d == 9)
    {
        return '9';
    }
    else if (d == 10)
    {
        return 'A';
    }
    else if (d == 11)
    {
        return 'B';
    }
    else if (d == 12)
    {
        return 'C';
    }
    else if (d == 13)
    {
        return 'D';
    }
    else if (d == 14)
    {
        return 'E';
    }
    else if (d == 15)
    {
        return 'F';
    }
    else
    {
        throw std::logic_error("how???");
        return '0';
    }


}
int toDec(std::string request, int power)
{
    int len = request.length() - 1;
    int sum = 0;
    int temp;
    for (int i = 0; i < request.length(); i++)
    {
        sum += charToDec(request[i]) * pow(power, len);
        len--;
    }
    return sum;
}


Numbers::Numbers(int number)
{
    _number = number;
}

Numbers::Numbers(const Numbers& rhs)
{
    operator=(rhs);
}

Numbers::Numbers(std::string number, int power)
{
    Check(number, power);
    _number = toDec(number, power);
}

Numbers Numbers::operator-()
{
    return Numbers(_number);
}

Numbers& Numbers::operator=(const Numbers& rhs)
{
    _number = rhs._number;
    return *this;
}

Numbers& Numbers::operator+=(const Numbers& rhs)
{
    _number += rhs._number;
    return *this;
}

Numbers& Numbers::operator+=(const int rhs)
{
    _number += rhs;
    return *this;
}

Numbers& Numbers::operator-=(const Numbers& rhs)
{
    _number -= rhs._number;
    return *this;
}

Numbers& Numbers::operator-=(const int rhs)
{
    _number -= rhs;
    return *this;
}

Numbers& Numbers::operator*=(const Numbers& rhs)
{
    _number *= rhs._number;
    return *this;
}

Numbers& Numbers::operator*=(const int rhs)
{
    _number *= rhs;
    return *this;
}

Numbers& Numbers::operator/=(const Numbers& rhs)
{
    _number /= rhs._number;
    return *this;
}

Numbers& Numbers::operator/=(const int rhs)
{
    _number /= rhs;
    return *this;
}

bool Numbers::operator==(const Numbers& rhs) const
{
    return _number == rhs._number;
}

bool Numbers::operator==(const int rhs) const 
{
    return _number == rhs;
}

bool Numbers::operator!=(const Numbers& rhs) const
{
    return !operator==(rhs);
}

bool Numbers::operator!=(const int rhs) const 
{
    return !operator==(rhs);
}

bool Numbers::operator>(const Numbers& rhs) const 
{
    return _number > rhs._number;
}

bool Numbers::operator>(const int rhs) const 
{
    return _number > rhs;
}

bool Numbers::operator<(const Numbers& rhs) const 
{
    return _number < rhs._number;
}

bool Numbers::operator<(const int rhs) const 
{
    return _number < rhs;
}

bool Numbers::operator<=(const Numbers& rhs) const 
{
    return !operator>(rhs);
}

bool Numbers::operator<=(const int rhs) const
{
    return !operator>(rhs);
}

bool Numbers::operator>=(const Numbers& rhs) const
{
    return !operator<(rhs);
}

bool Numbers::operator>=(const int rhs) const 
{
    return !operator<(rhs);
}

Numbers operator+(const Numbers& lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp += rhs;
    return temp;
}

Numbers operator+(const Numbers& lhs, const int rhs)
{
    Numbers temp = Numbers(lhs);
    temp += rhs;
    return temp;
}

Numbers operator+(const int lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp += rhs;
    return temp;
}

Numbers operator-(const Numbers& lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp -= rhs;
    return temp;
}

Numbers operator-(const Numbers& lhs, const int rhs)
{
    Numbers temp = Numbers(lhs);
    temp -= rhs;
    return temp;
}

Numbers operator-(const int lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp -= rhs;
    return temp;
}

Numbers operator*(const Numbers& lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp *= rhs;
    return temp;
}

Numbers operator*(const Numbers& lhs, const int rhs)
{
    Numbers temp = Numbers(lhs);
    temp *= rhs;
    return temp;
}

Numbers operator*(const int lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp *= rhs;
    return temp;
}

Numbers operator/(const Numbers& lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp /= rhs;
    return temp;
}

Numbers operator/(const Numbers& lhs, const int rhs)
{
    Numbers temp = Numbers(lhs);
    temp /= rhs;
    return temp;
}

Numbers operator/(const int lhs, const Numbers& rhs)
{
    Numbers temp = Numbers(lhs);
    temp /= rhs;
    return temp;
}

std::string Numbers::GetNumber(int power)
{
    std::stack <char> elements;
    int tempNumber = _number;
    while (tempNumber > 0)
    {
        elements.push(decToChar(tempNumber%power));
        tempNumber/= power;

    }
    std::string stringNumber = "";
    while (!elements.empty())
    {
        stringNumber += elements.top();
        elements.pop();
    }
    return stringNumber;

}


