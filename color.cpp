#include "color.h"

/*
* ����ÿ�η������߲���ʱ������һ�� 0-1 ֮�����ɫֵ,
* ����һ���԰����е���ɫ������һ��Ȼ�����ֻ��Ҫ�򵥵ĳ��Բ��������
* ����, ��ͷ�ļ� rtweekend.h ������һ���º��� clamp(x, min, max), ������ x ������ [min,max] ����֮��
*/
void write_color(std::ostream& out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}