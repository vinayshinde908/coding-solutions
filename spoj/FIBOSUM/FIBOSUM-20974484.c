#include<vector>
#include<iostream>
using namespace std;
const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
const int MAX_K = 50;
#define deb(x) cout << #x << "=" << x << endl
struct Matrix
{
    vector< vector<long long> > mat;
    long long n_rows, n_cols;

    Matrix() {}

    Matrix(vector< vector<long long> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(long long n)
    {
        vector< vector<long long> > values(n, vector<long long>(n, 0));
        for(long long i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        long long n = n_rows, m = other.n_cols;
        vector< vector<long long> > result(n_rows, vector<long long>(n_cols, 0));
        for(long long i = 0; i < n; i++)
            for(long long j = 0; j < m; j++) {
                long long tmp = 0;
                for(long long k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while(tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }

        return move(Matrix(move(result)));
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

// M_powers[i] is M, raised to 2^i-th power
Matrix M_powers[55];

void precalc_powers(Matrix M)
{
    M_powers[0] = M;

    for(long long i = 1; i < 55; i++)
        M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
}

Matrix fast_exponentiation_with_precalc(long long power)
{
    Matrix result = Matrix::identity_matrix(M_powers[0].mat.size());
    long long pointer = 0;
    while(power) {
        if(power & 1)
            result = result * M_powers[pointer];
        pointer++;
        power >>= 1;
    }
    return result;
}

inline int get_int()
{
    char c;
    int ret = 0;
    while(isdigit(c = getchar()))
        ret = ret * 10 + c - '0';
    return ret;
}

int main()
{
    int t;
    Matrix M({
            {1, 0, 0},
            {1, 0, 1},
            {1, 1, 1} });
    precalc_powers(M);

    Matrix initial({ {1, 0, 1} });
    t = get_int();
    for(int i = 0; i < t; i++) {
        long long n, m;
        cin>>n>>m;
        long long l = 0, r = 0;
        if(n>1)
        l = (initial * fast_exponentiation_with_precalc(n - 2)).mat[0][0];
        if(m>1)
        r = (initial * fast_exponentiation_with_precalc(m - 1)).mat[0][0];
        cout<<(r-l+MOD)%MOD<<endl;
    }
}