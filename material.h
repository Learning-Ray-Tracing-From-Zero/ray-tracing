#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"
#include "rtweekend.h"
#include "ray.h"

/*
* �ں�����ʹ�� hit_record ��Ϊ����������Ϳ��Բ��ô���һ��ѱ���
* ��Ȼ������봫һ�ѱ�����ȥ�Ļ�Ҳ�У���Ҳ�Ǹ���ϲ��
*/
struct hit_record;


class material {
public:
    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};


class lambertian : public material {
public:
    lambertian(const color& a);

    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const override;

public:
    color albedo;
};


class metal : public material {
public:
    metal(const color& a, double f);

    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const override;

public:
    color albedo;
    double fuzz;// ģ����
};

#endif
