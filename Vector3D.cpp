#include "Vector3D.h"

/** implementation of headers */
Vector3D::Vector3D(double d0, double d1, double d2)
{
    x = d0;
    y = d1;
    z = d2;
}

Vector3D::Vector3D() : Vector3D(0, 0, 0)
{
}

Vector3D::Vector3D(double arr[3])
{
    x = arr[0];
    y = arr[1];
    z = arr[2];
}

Vector3D::Vector3D(const Vector3D &v) : Vector3D(v.x, v.y, v.z)
{
}

double Vector3D::norm() const
{
    return sqrt(x * x + y * y + z * z);
}

double Vector3D::dist(const Vector3D &v) const
{
    double a = x - v.x;
    double b = y - v.y;
    double c = z - v.z;
    return sqrt(a * a + b * b + c * c);
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return Vector3D(v.x + x, v.y + y, v.z + z);
}


Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return Vector3D(x - v.x, y - v.y, z - v.z);
}


Vector3D Vector3D::operator+=(const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D Vector3D::operator-=(const Vector3D &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}


Vector3D Vector3D::operator-()
{
    Vector3D u;
    if (x != 0)
    {
        u.x = -x;
    }
    if (y != 0)
    {
        u.y = -y;
    }
    if (z != 0)
    {
        u.z = -z;
    }
    return u;
}

Vector3D Vector3D::operator*(double c) const
{
    return Vector3D(x * c, y * c, z * c);
}

Vector3D operator*(double c, const Vector3D &v)
{
    return v * c;
}

Vector3D Vector3D::operator/(double c) const
{
    if (c == 0)
    {
        std::cerr << "Division by 0!";
        exit(EXIT_FAILURE);
    }
    return Vector3D(x / c, y / c, z / c);
}

Vector3D Vector3D::operator*=(double c)
{
    x *= c;
    y *= c;
    z *= c;
    return *this;
}

Vector3D Vector3D::operator/=(double c)
{
    x /= c;
    y /= c;
    z /= c;
    return *this;
}

double Vector3D::operator*(const Vector3D &v) const
{
    return (v.x) * (x) + (v.y) * (y) + (v.z) * (z);
}

double Vector3D::operator^(const Vector3D &v) const
{
    double cosTheta = ((v) * (*this)) / (v.norm() * this->norm());
    if (cosTheta >= 1)
    {
        return 0;
    }
    else if (cosTheta <= -1)
    {
        return acos(-1);
    }
    double theta = acos(cosTheta);
    return theta;
}

Vector3D Vector3D::operator+=(double c)
{
    x += c;
    y += c;
    z += c;
    return *this;
}

Vector3D Vector3D::operator-=(double c)
{
    x -= c;
    y -= c;
    z -= c;
    return *this;
}

double Vector3D::operator|(const Vector3D &v) const
{
    return this->dist(v);
}

std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    out << v.x << ' ' << v.y << ' ' << v.z << std::endl;
    if (out.fail())
    {
        std::cerr << "output error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return out;
}

std::istream &operator>>(std::istream &in, Vector3D &v)
{
    in >> v.x >> v.y >> v.z;
    if (in.fail())
    {
        std::cerr << "input error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return in;
}


Vector3D &Vector3D::operator=(const Vector3D &v)
{
    if (this == &v)
    {
        return *this;
    }
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

bool Vector3D::operator==(Vector3D &v) const
{
    return (v.x == x && v.y == y && v.z == z);
}

double &Vector3D::operator[](std::size_t idx)
{

    switch (idx)
    {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            std::cerr << "index error" << std::endl;
            exit(EXIT_FAILURE);
    }

}

const double &Vector3D::operator[](std::size_t idx) const
{
    switch (idx)
    {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            std::cerr << "index error" << std::endl;
            exit(EXIT_FAILURE);
    }
}