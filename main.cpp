#include "vec3.h"
#include "color.h"

#include <iostream>

int main() {
    // image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    // ������������ض���д�뵽�ļ�
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";// 255 �涨���ص����ֵ

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i) / (double)(image_width - 1), double(j) / (double)(image_height - 1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }
    // ���������������޻��壬ֻ��д����Ļ�ϣ������ض���д�뵽�ļ�
    std::cerr << "\nDone.\n";
    std::cin.get();

    return 0;
}