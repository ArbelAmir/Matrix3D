//
// Created by arbel_amir on 12/10/18.
//
#include <iostream>
#include <cmath>

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

/** 3 dimensional vector class */
class Vector3D
{
public:
    Vector3D();
    /** a 3 numbers constructor */
    Vector3D(double d0, double d1, double d2);

    /** a copy constructor */
    Vector3D(const Vector3D &v);

    /** an array argument constructor */
    explicit Vector3D(double arr[3]);

    // methods

    /** computes the norm of the vector*/
    double norm() const;

    /** computes the distance from a given vector*/
    double dist(const Vector3D &) const;

    // operators support:

    /** addition of a vector to this */
    Vector3D operator+=(const Vector3D &v);

    /** substruction of a vector to this */
    Vector3D operator-=(const Vector3D &v);

    /** addition of a number to this */
    Vector3D operator+=(double c);

    /** substruction of a number to this */
    Vector3D operator-=(double c);

    /** minus of this vector */
    Vector3D operator-();

    /** multiplication of this vector and a number */
    Vector3D operator*=(double c);

    /** division of this vector and a number */
    Vector3D operator/=(double c);

    /** assign a vector to this */
    Vector3D &operator=(const Vector3D &v);

    /** subscribe to this vector in the given index */
    double &operator[](std::size_t idx);

    /** get this vector coordinate in the given index */
    const double &operator[](std::size_t idx) const;

    /** addition of two vectors */
    Vector3D operator+(const Vector3D &v) const;

    /** substruction of two vectors */
    Vector3D operator-(const Vector3D &v) const;

    /** multiplication of vector and a number */
    Vector3D operator*(double c) const;

    /** division of a vector and a number */
    Vector3D operator/(double c) const;

    /** calculate the distance between two given vectors */
    double operator|(const Vector3D &u) const;

    /** calculate the standart inner product between two given vectors */
    double operator*(const Vector3D &v) const;

    /** return the angle of two given vectors */
    double operator^(const Vector3D &v) const;

    /** checks if two given vecctors are equal */
    bool operator==(Vector3D &) const;

    /** multiplication of a number and a vector */
    friend Vector3D operator*(double c, const Vector3D &v);

    /** print a vector to output stream */
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);

    /** get a vector from input stream */
    friend std::istream &operator>>(std::istream &in, Vector3D &v);

private:
    double x;
    double z;
    double y;
};


#endif //EX1_VECTOR3D_H
