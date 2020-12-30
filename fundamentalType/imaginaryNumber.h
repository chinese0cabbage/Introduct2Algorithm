//
// Created by cobot on 20-12-3.
//

#ifndef INTRODUCT2ALGORITHM_IMAGINARYNUMBER_H
#define INTRODUCT2ALGORITHM_IMAGINARYNUMBER_H

typedef struct imaginaryNumber {
    double realPart;
    double imaginaryPart;

    imaginaryNumber(double realPart, double imaginaryPart) : realPart(realPart), imaginaryPart(imaginaryPart) {}

    const imaginaryNumber operator*(double times) const {
        return imaginaryNumber(realPart * times, imaginaryPart * times);
    }

    const imaginaryNumber operator*(double times, const imaginaryNumber &other) {
        return other * times;
    }

    operator int() const {//当前类的转换函数，int a= imaginaryNumber实例将有返回值

    }

    inline const imaginaryNumber operator*(const imaginaryNumber &other) const {
        double part1 = (realPart + imaginaryPart) * other.realPart;
        double part2 = (realPart - imaginaryPart) * other.imaginaryPart;
        double part3 = (other.realPart + other.imaginaryPart) * imaginaryPart;
        return imaginaryNumber(part1 - part3, part2 + part3);
    }

    inline void operator*=(double times) {
        realPart *= times;
        imaginaryPart *= times;
    }

    inline imaginaryNumber operator+(const imaginaryNumber &other) const {
        return imaginaryNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    inline imaginaryNumber operator+=(const imaginaryNumber &other) {
        realPart += other.realPart;
        imaginaryPart += other.imaginaryPart;
    }

    inline imaginaryNumber operator-(const imaginaryNumber &other) const {
        return this->operator+(other * (-1));
    }

    inline void operator-=(const imaginaryNumber &other) {
        realPart -= other.realPart;
        imaginaryPart -= other.imaginaryPart;
    }

    inline imaginaryNumber operator/(double times) const {
        assert(times == 0);
        return this->operator*(1 / times);
    }

    inline imaginaryNumber operator/=(double times) {
        assert(times == 0);
        this->operator*=(1 / times);
    }

    friend std::ostream &operator<<(std::ostream &os, imaginaryNumber &imaginaryNumber1) {
        std::string behandPart = "", frontPart = "";
        if (imaginaryNumber1.imaginaryPart != 0)
            behandPart = 'i';
        if (imaginaryNumber1.imaginaryPart > 0)
            frontPart = '+';
        os << imaginaryNumber1.realPart << frontPart << imaginaryNumber1.imaginaryPart << behandPart << std::endl;
        return os;
    }
};

#endif //INTRODUCT2ALGORITHM_IMAGINARYNUMBER_H
