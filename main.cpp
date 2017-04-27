#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include "temperature.h"

using namespace std;

int test_temperature_input(){
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

}



int
main() {
    test_temperature_input();
    size_t temp_count;
    cerr << "Enter temperatures count: ";
    cin >> temp_count;

    cerr << "Enter numbers: ";
    vector<Temperature> temps(temp_count);
    for (size_t i = 0; i < temp_count; i++) {
        cin >> temps[i];
        if(!cin){
            cout << "Error";
            return 1;
        }
    }


    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    Temperature min = temps[0];
    Temperature max = temps[0];
    for (Temperature temp : temps) {
        if (temp < min) {
            min = temp;
        }
        if (max < temp) {
            max = temp;
        }
    }

    vector<size_t> counts(column_count);
    for (Temperature temp : temps) {
        min = temp_convert(temp,temp.scale);
        max = temp_convert(temp,temp.scale);
        size_t column = (size_t)((temp.temperature - min.temperature) / (max
                .temperature - min.temperature) *
                column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}