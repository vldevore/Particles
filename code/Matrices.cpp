#include "Matrices.h"
#include <cmath>
#include <stdexcept>

namespace Matrices
{
    Matrix::Matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        a.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            a[i].resize(cols, 0.0);
        }
    }

    Matrix operator+(const Matrix &a, const Matrix &b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            throw std::runtime_error("Error: dimensions must agree");
        }
        Matrix result(a.getRows(), a.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                result(i, j) = a(i, j) + b(i, j);
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &a, const Matrix &b)
    {
        if (a.getCols() != b.getRows())
        {
            throw std::runtime_error("Error: dimensions must agree");
        }
        Matrix result(a.getRows(), b.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < b.getCols(); j++)
            {
                result(i, j) = 0;
                for (int k = 0; k < a.getCols(); k++)
                {
                    result(i, j) += a(i, k) * b(k, j);
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix &a, const Matrix &b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            return false;
        }
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                if (std::abs(a(i, j) - b(i, j)) > 0.001)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix &a, const Matrix &b)
    {
        return !(a == b);
    }

    ostream &operator<<(ostream &os, const Matrix &a)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << std::setw(10) << a(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }
}
