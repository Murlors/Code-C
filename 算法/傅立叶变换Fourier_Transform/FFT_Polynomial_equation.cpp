#include "bits/stdc++.h"
using namespace std;

class Complex {
public:
    double r, i;
    Complex(double r0 = 0, double i0 = 0) : r(r0), i(i0) {};
};

Complex operator+(Complex c1, Complex c2) { return Complex(c1.r + c2.r, c1.i + c2.i); }
Complex operator-(Complex c1, Complex c2) { return Complex(c1.r - c2.r, c1.i - c2.i); }
Complex operator*(Complex c1, Complex c2) { return Complex(c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c1.i * c2.r); }

Complex A[131100], B[131100], C[131100];
const double PI = acos(-1.0);
int M, N, L, C_in[131100];

void dft(Complex *a, int n, int flag) {
    if (n == 1)return;
    Complex a1[n / 2], a2[n / 2];
    for (int i = 0; i < n / 2; ++i) {
        a1[i] = a[i * 2];
        a2[i] = a[i * 2 + 1];
    }
    dft(a1, n / 2, flag);
    dft(a2, n / 2, flag);
    for (int i = 0; i < n / 2; ++i) {
        Complex w = Complex(cos(PI * 2 * i / n), sin(PI * 2 * i / n) * flag);
        a[i] = a1[i] + a2[i] * w;
        a[i + n / 2] = a1[i] - a2[i] * w;
    }
}

inline void DFT(Complex a[], Complex b[], Complex c[], int n) {
    dft(a, n, 1);
    dft(b, n, 1);
    for (int i = 0; i < n; ++i) c[i] = a[i] * b[i];
    dft(c, n, -1);
    for (int i = 0; i < n; ++i) c[i].r /= n;
}

int main() {
    cin >> M >> N >> L;
    for (int i = M; i >= 0; i--)cin >> A[i].r;
    for (int i = N; i >= 0; i--)cin >> B[i].r;
    for (int i = L; i >= 0; i--)cin >> C_in[i];
    int ans = 1, len = 1;
    if (M + N != L) {
        ans = 0;
    } else {
        while (len < L + 1) {
            len *= 2;
        }
        DFT(A, B, C, len);
        for (int i = 0; i < len; i++) {
            int e = (int) (C[i].r + (C[i].r >= 0 ? 0.5 : -0.5));
            if (e != C_in[i]) {
                ans = 0;
                break;
            }
        }
    }
    if (ans == 1)cout << "YES";
    else cout << "NO";
    return 0;
}