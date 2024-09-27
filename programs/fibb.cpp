#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

typedef vector<vector<long long>> Matrix;

Matrix multiply(Matrix &A, Matrix &B) {
    int size = A.size();
    Matrix result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

Matrix matrixExponentiation(Matrix A, long long exp) {
    int size = A.size();
    Matrix result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;
    }
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        exp /= 2;
    }
    return result;
}

long long F(long long n) {
    if (n < 100) return n;

    Matrix T(100, vector<long long>(100, 0));
    for (int i = 0; i < 99; i++) {
        T[i][i + 1] = 1;
    }
    T[99][0] = 1;
    T[99][1] = 1;

    vector<long long> F_initial(100);
    for (int i = 0; i < 100; i++) {
        F_initial[i] = i;
    }

    Matrix T_exp = matrixExponentiation(T, n - 99);

    long long result = 0;
    for (int i = 0; i < 100; i++) {
        result = (result + T_exp[99][i] * F_initial[i]) % MOD;
    }

    return result;
}

int main() {
    long long n;
    cin >> n;
    cout << F(n) << endl;
    return 0;
}