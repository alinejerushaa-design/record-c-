
#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    // Default constructor
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];

        return result;
    }

    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }

        return result;
    }

    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";

            out << endl;
        }

        return out;
    }
};

int main()
{
    int a, b, c, d;

    cout << "Enter elements of Matrix A (4 values): ";
    cin >> a >> b >> c >> d;

    Matrix A(a, b, c, d);

    cout << "Enter elements of Matrix B (4 values): ";
    cin >> a >> b >> c >> d;

    Matrix B(a, b, c, d);

    Matrix sum = A + B;
    Matrix product = A * B;

    // Display matrices
    cout << "\nMatrix A:\n" << A;
    cout << "\nMatrix B:\n" << B;

    cout << "\nAddition of Matrices:\n" << sum;
    cout << "\nMultiplication of Matrices:\n" << product;

    // Unit Tests
    assert(sum[0][0] == A[0][0] + B[0][0]);
    assert(sum[1][1] == A[1][1] + B[1][1]);

    cout << "\nAll unit tests passed successfully!" << endl;

    return 0;
}
