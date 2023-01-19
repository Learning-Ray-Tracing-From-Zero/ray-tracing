#include <vec3/vec3.h>
#include <color/color.h>
#include <ray/ray.h>

#include <iostream>

color ray_color(const ray& r);

int main() {
    // image
    const int image_width = 200;
    const int image_height = 100;

    // Camera
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (double)(image_width - 1);
            auto v = double(j) / (double)(image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}

/*
 * ��Ļ����ϵ��4 * 2���Զ���ģ�
 * ��Ҫ�����ߣ����ߣ����������е�λ�����Ա�֤ÿ����������ĳ��ȿ����� [-1, 1]
 * ��Ϊ����ʹ�� y ��������, ��������Կ���������׽���Ҳ����ֱ��
*/

// ray_color(ray) �������� y ֵ�����������Բ�ֵ�Ļ��
color ray_color(const ray& r) {
    /*
    * ԭ�ӿڸ߶ȱ����Ϊ [-1, 1]
    * ��˵�λ����һ���Ǵ�ģ��õ��Ľ�����������İ������䣬����ֱ����ôд��
    * auto t = 0.5 * (r.direction().y() + 1.0);
    */
    vec3 unit_direction = unit_vector(r.direction());// ��λ������ʱȡֵ��Χ�� [-1, 1]
    auto t = 0.5 * (unit_direction.y() + 1.0);// �� y ����ӳ�䵽 [0, 1]

    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
