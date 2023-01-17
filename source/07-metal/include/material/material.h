#ifndef MATERIAL_H
#define MATERIAL_H

/*
 * 1������ɢ���Ĺ���(����˵���������������)
 * 2���������ɢ��, �������߻�䰵���٣�attenuate��
 */
#include "hittable\hittable.h"
#include "rtweekend\rtweekend.h"
#include "ray\ray.h"


/*
* �ں�����ʹ�� hit_record ��Ϊ����������Ϳ��Բ��ô���һ��ѱ���
* ��Ȼ������봫һ�ѱ�����ȥ�Ļ�Ҳ�У���Ҳ�Ǹ���ϲ��
*/
struct hit_record;

class material {
public:
    virtual bool scatter(
        const ray& r_in,
        const hit_record& rec,
        color& attenuation,
        ray& scattered
    ) const = 0;
};


class lambertian : public material {
public:
    lambertian(const color& a);

    virtual bool scatter(
        const ray& r_in,
        const hit_record& rec,
        color& attenuation,// ˥��
        ray& scattered// ɢ��
    ) const override;

public:
    color albedo;// ������
};


class metal : public material {
public:
    metal(const color& a, double f);

    virtual bool scatter(
        const ray& r_in,
        const hit_record& rec,
        color& attenuation,
        ray& scattered
    ) const override;

public:
    color albedo;
    double fuzz;// ģ����
};

#endif
