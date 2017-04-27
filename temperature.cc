//
// Created by u211-12 on 27.04.2017.
//

#include "temperature.h"

using namespace std;

istream & operator >> (istream &in, Temperature &T){
    in >> T.temperature;
    if(!in){
        in.setstate(ios_base::failbit);
    }
    char symbol;
    in >> symbol;
    switch (symbol){
    case 'K':
        T.scale = Kelvin;
        break;
    case 'C':
        T.scale = Celsius;
        break;
    case 'F':
        T.scale = Farenheit;
        break;
    }
    if ( (symbol != 'K') && (symbol != 'C') && (symbol != 'F') ){
        in.setstate(ios_base::failbit);
    }
    Temperature prov = temp_convert(T, Kelvin);
    if ( prov.temperature < 0 ){
        in.setstate(ios_base::failbit);
    }
    return in;
}

Temperature temp_convert(const Temperature& T, Scale scale){
    Temperature Tout = T;
    //In kelvins
    switch (T.scale){
    case Celsius:
        Tout.temperature -= 273;
        break;
    case Farenheit:
        Tout.temperature = ((9.0/5)*(Tout.temperature - 273)+32);
        break;
    }
    switch (scale){
    case Celsius:
        Tout.scale = Celsius;
        Tout.temperature += 273;
        break;
    case Farenheit:
        Tout.scale = Farenheit;
        Tout.temperature = ((5.0/9)*(Tout.temperature-32)+273);
        break;
    }
    return Tout;
}

bool operator < (const Temperature& t1, const Temperature& t2){
    Temperature Tin1 = t1;
    Temperature Tin2 = t2;
    Tin1 = temp_convert(Tin1, Tin2.scale);
    return (Tin1.temperature < Tin2.temperature);

}