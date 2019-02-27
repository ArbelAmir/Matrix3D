#include "Vector3D.h"

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H

/** a 3 dimentional matrix */
class Matrix3D
{
public:

    /** a default constructor, returns 0 matrix */
    Matrix3D();

    /** unit matrix, returns a diagonal matrix with the given number in the diagonal */
    explicit Matrix3D(double c);

    /** a constructor for 9 numbers */
    Matrix3D(double a0,
             double a1,
             double a2,
             double a3,
             double a4,
             double a5,
             double a6,
             double a7,
             double a8);

    /** a constructor for an array of 9 numbers */
    explicit Matrix3D(double[9]);

    /** a constructor for an array of 3X3 numbers */
    explicit Matrix3D(double[3][3]);

    /** a constructor for three given voctors */
    Matrix3D(Vector3D, Vector3D, Vector3D);

    /** a copy constructor */
    Matrix3D(Matrix3D &m);

    //methods:
    /** getter for the i'th row of this matrix */
    Vector3D row(short i) const;

    /** getter for the j'th column of this matrix */
    Vector3D column(short j) const;

    /** calculate the trace of this matrix */
    double trace() const;

    /** calculate the determinant of this matrix */
    double determinant() const;

    /** add the given matrix to this matrix */
    Matrix3D operator+=(const Matrix3D &a);

    /** substruct the given matrix to this matrix */
    Matrix3D operator-=(const Matrix3D &a);

    /** multiply the given matrix to this matrix */
    Matrix3D operator*=(const Matrix3D &a);

    /** multiply the given matrix with a given number */
    Matrix3D operator*=(double c);

    /** divide the given matrix with a given number */
    Matrix3D operator/=(double c);

    // operators support:
    /** return the result of an addition of two given matrix */
    Matrix3D operator+(const Matrix3D &a) const;

    /** return the result of an substruction of two given matrix */
    Matrix3D operator-(const Matrix3D &a) const;

    /** return the result of a multiplication of matrix and a vector */
    Vector3D operator*(const Vector3D &v) const;

    /** return the result of an multiplication of two given matrix */
    Matrix3D operator*(const Matrix3D &) const ;

    /** stream the given matrix to the given output stream */
    friend std::ostream &operator<<(std::ostream &out, const Matrix3D &v) ;

    /** get a matrix from input stream */
    friend std::istream &operator>>(std::istream &in, Matrix3D &v);

    /** assign a matrix to this */
    Matrix3D &operator=(const Matrix3D &a);

    /** subscribe to this matrix in the given index */
    Vector3D &operator[](std::size_t idx);

    /** get this matrix row in the given index */
    const Vector3D &operator[](std::size_t idx) const;

private:
    Vector3D rows[3];
};


#endif //EX1_MATRIX3D_H
