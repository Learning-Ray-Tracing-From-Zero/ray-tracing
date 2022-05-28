#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

class material;

/*
* ���߻��������潻�����ɾ���Ĳ�����������
* hit_record ������Ͼ���Ϊ�˰�һ��Ҫ���Ĳ������������һ��
* ����������һ�����棨����һ�����壩, hit_record �еĲ���ָ��ᱻ����Ĳ���ָ������ֵ
* ������Ĳ���ָ������ main() �����й���ʱ�����
* �� color() ������ȡ�� hit_record ʱ, �������ҵ�������ʵ�ָ��, Ȼ���ɲ��ʵĺ��������������Ƿ���ɢ��, ��ôɢ��
*/
struct hit_record {
	hit_record();
	vec3 p;
	vec3 normal;
	shared_ptr<material> mat_ptr;// ����ָ��
	double t;
	bool front_face;

	void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable {
public:

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};
#endif
