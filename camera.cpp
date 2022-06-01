#include "camera.h"

camera::camera(
    point3 lookfrom,// �������λ�ã������ lookfrom λ�ÿ��� lookat ��
    point3 lookat,// �������ָ���λ�õ�
    vec3 vup,
    double vfov,// top to bottom, in degrees
    double aspect_ratio,// ��Ļ��߱�
    double aperture,// ��Ȧ
    double focus_dist
) {// vertical field-of-view in degrees

    auto theta = degrees_to_radians(vfov);
    auto h = tan(theta / 2);// �۾�����Ļ���ĵľ���Ϊ -1
    auto viewport_height = 2.0 * h;// �ӿڸ߶�
    auto viewport_width = aspect_ratio * viewport_height;// �ӿڿ��

    // ȷ����ά�����������ϵ (u, v, w)
    // ���ƽ���ǹ� lookfrom ��ֱ�����ߣ�from->at����һ��ƽ��

    w = unit_vector(lookfrom - lookat);// w ��һ�����������ƽ��Ļ��������������෴�Ļ�������
    u = unit_vector(cross(vup, w));// u �������ƽ���ˮƽ������u һ��ƽ������������ϵ�� x ��
    v = cross(w, u);// ��˶��� v����ֱ�����ƽ��ķ���

    origin = lookfrom;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

    lens_radius = aperture / 2;
}

/*
* ray camera::get_ray(double s, double t) const {
*     return ray(origin, lower_left_corner + s * horizontal + t * vertical - origin);
* }
*/

ray camera::get_ray(double s, double t) const {
    vec3 rd = lens_radius * random_in_unit_disk();
    vec3 offset = u * rd.x() + v * rd.y();

    return ray(
        origin + offset,
        lower_left_corner + s * horizontal + t * vertical - origin - offset
    );
}
