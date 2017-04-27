//
// Created by u211-12 on 27.04.2017.
//

#ifndef LAB01_TEMPERATURE_H
#define LAB01_TEMPERATURE_H

enum Scale{
    Kelvin = 'K',
    Celsius = 'C',
    Farenheit = 'F'
};
struct Temperature{
    Scale scale;
    double temperature;
}T;

std::istream & operator >> (std::istream &in, Temperature &T);

Temperature temp_convert(const Temperature& T, Scale scale);

bool operator < (const Temperature& t1, const Temperature& t2);

#endif //LAB01_TEMPERATURE_H
#include <iostream>



