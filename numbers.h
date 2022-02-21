#include <iostream>
#include <string>
#pragma once
#ifndef numbers_h
#define numbers_h

class Numbers
{
private:
    int _number{0};

public:

    Numbers() = default;

    ~Numbers() = default;

    Numbers (int number);

    Numbers (const Numbers& rhs);

    Numbers(std::string number, int power);

    Numbers operator-();

    Numbers& operator=(const Numbers& rhs);
    Numbers& operator+=(const Numbers& rhs);
    Numbers& operator+=(const int rhs);
    Numbers& operator-=(const Numbers& rhs);
    Numbers& operator-=(const int rhs);
    Numbers& operator/=(const Numbers& rhs);
    Numbers& operator/=(const int rhs);
    Numbers& operator*=(const Numbers& rhs);
    Numbers& operator*=(const int rhs);

    bool operator==(const Numbers& rhs) const;
    bool operator==(const int rhs) const;
    bool operator!=(const Numbers& rhs) const;
    bool operator!=(const int rhs) const;
    bool operator>(const Numbers& rhs) const;
    bool operator>(const int rhs) const;
    bool operator<(const Numbers& rhs) const;
    bool operator<(const int rhs) const;
    bool operator>=(const Numbers& rhs) const;
    bool operator>=(const int rhs) const;
    bool operator<=(const Numbers& rhs) const;
    bool operator<=(const int rhs) const;

    std::string GetNumber(int power);


};

Numbers operator+(const Numbers& lhs, const Numbers& rhs);
Numbers operator+(const Numbers& lhs, const int rhs);
Numbers operator+(const int lhs, const Numbers& rhs);

Numbers operator-(const Numbers& lhs, const Numbers& rhs);
Numbers operator-(const Numbers& lhs, const int rhs);
Numbers operator-(const int lhs, const Numbers& rhs);

Numbers operator*(const Numbers& lhs, const Numbers& rhs);
Numbers operator*(const Numbers& lhs, const int rhs);
Numbers operator*(const int lhs, const Numbers& rhs);

Numbers operator/(const Numbers& lhs, const Numbers& rhs);
Numbers operator/(const Numbers& lhs, const int rhs);
Numbers operator/(const int lhs, const Numbers& rhs);





#endif /* numbers_h */