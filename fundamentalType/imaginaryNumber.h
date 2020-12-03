//
// Created by cobot on 20-12-3.
//

#ifndef INTRODUCT2ALGORITHM_IMAGINARYNUMBER_H
#define INTRODUCT2ALGORITHM_IMAGINARYNUMBER_H
typedef struct imaginaryNumber{
    double realPart;
    double imaginaryPart;

    imaginaryNumber(double realPart, double imaginaryPart):realPart(realPart),imaginaryPart(imaginaryPart){}

    const imaginaryNumber operator*(double times){
        realPart*=times;
        imaginaryPart*=times;
    }

    const imaginaryNumber operator*(imaginaryNumber &other){
        double part1=(realPart+imaginaryPart)*other.realPart;
        double part2=(realPart-imaginaryPart)*other.realPart;
        double part3=(other.realPart+other.imaginaryPart)*imaginaryPart;
        return imaginaryNumber(part1-part3,part2+part2);
    }
};

#endif //INTRODUCT2ALGORITHM_IMAGINARYNUMBER_H
