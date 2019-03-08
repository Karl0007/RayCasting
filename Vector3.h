#pragma once
#include<iostream>
namespace My
{

template<class Type>
class Vector3
{
private:

public:
	Type x, y, z;
	Vector3& operator= (const Vector3 &) = default;
	Vector3& operator= (Vector3&&) = default;
	Vector3(const Vector3&) = default;
	Vector3(Vector3&&) = default;

	Vector3(const Type&_sx,const Type&_sy,const Type&_sz,const Type&_ex,const Type&_ey,const Type&_ez) :x(_ex - _sx), y(_ey - _sy), z(_ez - _sz) {};
	Vector3(const Vector3&_st,const Vector3&_ed) {*this = _ed - _st;}
	Vector3(const Type&_x = 0,const Type&_y = 0,const Type&_z = 0) : x(_x), y(_y), z(_z) {};
	~Vector3() {};

	Vector3<Type> operator+ (const Vector3&) const;
	Vector3<Type> operator- (const Vector3&) const;
	/*
	Define '%' to Cross product
	*/
	Vector3<Type> operator% (const Vector3&) const;
	Vector3<Type> & operator+= (const Vector3&);
	Vector3<Type> & operator-= (const Vector3&);
	/*
	Define '%' to Cross product
	*/
	Vector3<Type> & operator%= (const Vector3&) const;
	/*
	Define '*' to Dot product
	*/
	Type operator*(const Vector3 &);

	Type Length() const;
	Vector3<Type> Normalize();
	Vector3<Type> Normal() const;
	Vector3<Type> Cross(const Vector3&) const;
	Type Dot(const Vector3&) const;
	Type AbsDot(const Vector3&) const;

	template<class T>
	friend std::ostream & operator<< (std::ostream & _os,const Vector3<T>& _m);

};



template<class T>
std::ostream & operator<<(std::ostream & _os,const Vector3<T> & _m)
{
	_os << '(' << _m.x << ',' << _m.y << ',' << _m.z << ')' << std::endl;
	return _os;

}


template<class Type>
inline Vector3<Type> Vector3<Type>::operator+(const Vector3<Type> & _oth) const
{
	return Vector3(x + _oth.x, y + _oth.y, z + _oth.z);
}

template<class Type>
inline Vector3<Type> Vector3<Type>::operator-(const Vector3<Type> & _oth) const
{
	return Vector3(_oth.x - x, _oth.y - y, _oth.z - z);
}


template<class Type>
inline Vector3<Type> Vector3<Type>::operator%(const Vector3 & _oth) const
{
	return this->Cross(_oth);
}

template<class Type>
inline Vector3<Type> & Vector3<Type>::operator+=(const Vector3<Type> & _oth)
{
	return *this = *this + _oth;
}

template<class Type>
inline Vector3<Type> & Vector3<Type>::operator-=(const Vector3<Type> & _oth)
{
	return *this = _oth - *this;
}

template<class Type>
inline Vector3<Type> & Vector3<Type>::operator%=(const Vector3 &_oth) const
{
	return *this = this->Cross(_oth);
}

template<class Type>
inline Type Vector3<Type>::operator*(const Vector3 & _oth)
{
	return this->Dot(_oth);
}

template<class Type>
inline Type Vector3<Type>::Length() const
{
	return sqrt(x*x + y * y + z * z);
}

template<class Type>
inline Vector3<Type> Vector3<Type>::Normal() const
{
	Type tmp = Length();
	return Vector3<Type>(x / tmp, y / tmp, z / tmp);
}

template<class Type>
inline Vector3<Type> Vector3<Type>::Normalize()
{
	return *this=this->Normal();
}

template<class Type>
inline Vector3<Type> Vector3<Type>::Cross(const Vector3 & _oth) const
{
	return Vector3<Type>(y*_oth.z - z * _oth.y, z*_oth.x - x * _oth.z, x*_oth.y - y * _oth.x);
}

template<class Type>
inline Type Vector3<Type>::Dot(const Vector3 & _oth) const
{
	return x * _oth.x + y * _oth.y + z * _oth.z;
}

template<class Type>
inline Type Vector3<Type>::AbsDot(const Vector3 &_oth) const
{
	return abs(this->Dot(_oth));
}

typedef My::Vector3<float> vector3f;
typedef My::Vector3<int> vector3i;

} // namespace My
