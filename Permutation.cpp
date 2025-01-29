#include <iostream>
using namespace std;
constexpr long long mod_pow(long long x, long long y, long long mod) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

constexpr long long factorial(int n, long long mod) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % mod;
    }
    return result;
}

constexpr long long binomial_coefficient(int n, int r, long long mod) {
    if (r > n) return 0;
    
    long long numerator = factorial(n, mod);
    long long denominator = (factorial(r, mod) * factorial(n - r, mod)) % mod;
    
    long long denominator_inv = mod_pow(denominator, mod - 2, mod);
    
    return (numerator * denominator_inv) % mod;
}

int main() {
    constexpr long long MOD = 1000000007;
    const int n = 100000, r = 4547;

    constexpr long long result = binomial_coefficient(n, r, MOD);
    cout << n << "C" << r << " % " << MOD << " = " << result << endl;
    
    return 0;
}
