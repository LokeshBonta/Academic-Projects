// whattotest.cpp
#include <math.h>
#include<algorithm>
 
double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}

template <typename T>
T min( T in1, T in2)
{
    return std::min(in1, in2);
}

