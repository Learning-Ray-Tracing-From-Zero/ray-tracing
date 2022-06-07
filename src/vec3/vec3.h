#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

// ������
class vec3 {

public:
	// ���캯�������ڳ�ʼ�� vec3 ��
	vec3();
	vec3(double e0, double e1, double e2);

	// ���ڽ��� e ��ֵ���ڱ��ʱ����ֱ��ʹ�ã�x��y��z��������������˼
	double x() const;
	double y() const;
	double z() const;

	// ��������������� vec3 �йصĲ���
	vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);

	vec3& operator+=(const vec3& v);
	vec3& operator*=(const double t);
	vec3& operator/=(const double t);

	double length_squared() const;
	double length() const;

public:
	double e[3];

};

// ȡ����
using point3 = vec3;// 3d point
using color = vec3;// RGB color

// �ǳ�Ա����
std::ostream& operator<<(std::ostream& out, const vec3& v);

vec3 operator+(const vec3& u, const vec3& v);

vec3 operator-(const vec3& u, const vec3& v);

vec3 operator*(const vec3& u, const vec3& v);

vec3 operator*(double t, const vec3& v);

vec3 operator*(const vec3& v, double t);

vec3 operator/(vec3 v, double t);

double dot(const vec3& u, const vec3& v);

vec3 cross(const vec3& u, const vec3& v);

vec3 unit_vector(vec3 v);

#endif

/*
* 1�����캯��
* 2�����������
*		�൱��һ���������βθ����������������������
* 3������һ��ֵ������
* 4�����ڲ��ĳ�Ա�������Զ� inline ��
*/