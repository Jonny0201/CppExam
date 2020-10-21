long long fac(int n, int r = 1) {
    if(n == 1) {
        return r;
    }
    return fac(n - 1, r * n);
}
long double cal(int n) {
    bool symbol = false;
    long double r = 1.0l;
    long double t = 1.0l;
    for(int d = 2; d <= n; ++d) {
        t *= (2 * d - 2) * (2 * d - 1);
        r += [=]() mutable -> long double {
            if(symbol) {
                return 1 / t;
            }
            return -(1 / t);
        }();
        symbol = !symbol;
    }
}
