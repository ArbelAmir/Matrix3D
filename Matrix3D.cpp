
#include "Matrix3D.h"
#include "Vector3D.h"


/** implementation of header declarations */
Matrix3D::Matrix3D()
= default;

Matrix3D::Matrix3D(double c)
{
    rows[0][0] = c;
    rows[1][1] = c;
    rows[2][2] = c;
}

Matrix3D::Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
    rows[0][0] = a0;
    rows[0][1] = a1;
    rows[0][2] = a2;
    rows[1][0] = a3;
    rows[1][1] = a4;
    rows[1][2] = a5;
    rows[2][0] = a6;
    rows[2][1] = a7;
    rows[2][2] = a8;
}

Matrix3D::Matrix3D(double
                   a[9])
{
    int k = 0;
    for (Vector3D &row : rows)
    {
        for (int j = 0; j < 3; j++, k++)
        {
            row[j] = a[k];
        }
    }
}

Matrix3D::Matrix3D(double
                   a[3][3])
{
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            rows[i][j] = a[i][j];
        }
    }
}

Matrix3D::Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3)
{
    rows[0] = v1;
    rows[1] = v2;
    rows[2] = v3;
}

Matrix3D::Matrix3D(Matrix3D &m)
{
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            rows[i][j] = m[i][j];
        }
    }
}

Vector3D Matrix3D::row(short i) const
{
    Vector3D v(rows[i][0], rows[i][1], rows[i][2]);
    return v;
}


Vector3D Matrix3D::column(short j) const
{
    Vector3D v(rows[0][j], rows[1][j], rows[2][j]);
    return v;
}

double Matrix3D::trace() const
{
    return rows[0][0] + rows[1][1] + rows[2][2];
}

double Matrix3D::determinant() const
{
    return rows[0][0] * (rows[1][1] * rows[2][2] - rows[1][2] * rows[2][1]) -
           rows[0][1] * (rows[1][0] * rows[2][2] - rows[2][0] * rows[1][2]) +
           rows[0][2] * (rows[1][0] * rows[2][1] - rows[2][0] * rows[1][1]);
}

Matrix3D Matrix3D::operator+(const Matrix3D &b) const
{
    Matrix3D m(rows[0] + b[0],
            rows[1] + b[1],
                    rows[2] + b[2]);
    return m;
}

Matrix3D Matrix3D::operator-(const Matrix3D &b) const
{
    Matrix3D m(rows[0] - b[0],
                    rows[1] - b[1],
                    rows[2] - b[2]);
    return m;
}

Matrix3D Matrix3D::operator+=(const Matrix3D &a)
{

    rows[0] += a[0];
    rows[1] += a[1];
    rows[2] += a[2];
    return *this;
}


Matrix3D Matrix3D::operator-=(const Matrix3D &a)
{

    rows[0] -= a[0];
    rows[1] -= a[1];
    rows[2] -= a[2];
    return *this;
}

Vector3D Matrix3D::operator*(const Vector3D &v) const
{
    Vector3D u(rows[0][0] * v[0] + rows[0][1] * v[1] + rows[0][2] * v[2],
               rows[1][0] * v[0] + rows[1][1] * v[1] + rows[1][2] * v[2],
               rows[2][0] * v[0] + rows[2][1] * v[1] + rows[2][2] * v[2]);
    return u;
}


Matrix3D Matrix3D::operator*(const Matrix3D &a) const
{
    Matrix3D m;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            m.rows[i][j] = a.row(i) * (this->column(j));
        }
    }
    return m;
}

Matrix3D Matrix3D::operator*=(double c)
{
    rows[0] *= c;
    rows[1] *= c;
    rows[2] *= c;
    return *this;
}

Matrix3D Matrix3D::operator*=(const Matrix3D& a)
{
    Matrix3D b;
    b = *this * a;
    rows[0] = b.rows[0];
    rows[1] = b.rows[1];
    rows[2] = b.rows[2];
    return *this;
}


Matrix3D Matrix3D::operator/=(double c)
{
    rows[0] /= c;
    rows[1] /= c;
    rows[2] /= c;
    return *this;
}


Vector3D &Matrix3D::operator[](std::size_t idx)
{
    return rows[idx];
}

const Vector3D &Matrix3D::operator[](std::size_t idx) const
{
    return rows[idx];
}

Matrix3D &Matrix3D::operator=(const Matrix3D &a)
{
    if (this == &a)
    {
        return *this;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->rows[i][j] = a.rows[i][j];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Matrix3D &m)
{
    out << m.rows[0];
    out << m.rows[1];
    out << m.rows[2];
    if (out.fail())
    {
        std::cerr << "output error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return out;
}

std::istream &operator>>(std::istream &in, Matrix3D &m)
{
    in >> m.rows[0];
    in >> m.rows[1];
    in >> m.rows[2];
    if (in.fail())
    {
        std::cerr << "input error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return in;
}


