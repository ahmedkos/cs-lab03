#include "lab3.h"
void find_minmax(const vector<double>&data, double &Min, double &Max){
    if(data.size()==0) return;
    Min = Max = data[0];
    for (double x : data) {
        if (x < Min) Min = x;
        if (x > Max) Max = x;
    }
}
