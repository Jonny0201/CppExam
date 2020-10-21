#include <cmath>

using namespace std;

void derivative(double &a, double &n) {
    a = n-- * a;
}
double derivative(double &a, double &n, double x) {
    derivative(a, n);
    return a * pow(x, n);
}
