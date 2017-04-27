//
// Created by u211-12 on 27.04.2017.
//

#include "temperature.h"
#include <sstream>
#include <cassert>

using namespace std;

int main(){
    istringstream in_0 ("50K");
    Temperature T;
    in_0 >> T;
    assert(T.scale == Kelvin);
    assert(T.temperature == 50);

    istringstream in_1 ("-23K");
    in_1 >> T;
    assert(T.scale == Kelvin);
    assert(T.temperature == -23);

    istringstream in_2 ("15F");
    in_2 >> T;
    assert(T.scale == Farenheit);
    assert(T.temperature == 15);

    istringstream in_3 ("-33F");
    in_3 >> T;
    assert(T.scale == Farenheit);
    assert(T.temperature == -33);

    istringstream in_4 ("8C");
    in_4 >> T;
    assert(T.scale == Celsius);
    assert(T.temperature == 8);

    istringstream in_5 ("-63C");
    in_5 >> T;
    assert(T.scale == Celsius);
    assert(T.temperature == -63);

    istringstream in_6 ("-300C");
    in_6 >> T;
    assert(!in_6);

    istringstream in_7 ("oh");
    in_7 >> T;
    assert(!in_7);

    return 0;
}