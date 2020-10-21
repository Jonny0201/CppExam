#include <cmath>

using namespace std;

void integral(double &a, double &n) {
    a /= n++;
}
double integral(double &a, double &n, double begin, double end) {
    integral(a, n);
    return a * pow(begin, n) - a * pow(end, n);
}
