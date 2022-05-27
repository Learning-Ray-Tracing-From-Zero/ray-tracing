#ifndef RTWEEKEND_H
#define RTWEEKEND_H

/*
* ����һЩδ�����õĳ����ͺ���
* ���� pi ��˵��û��ʲô��ƽ̨�ı�׼���壨��ע�������Ϊʲô��ʹ��֮ǰ�汾�� M_PI �궨���ԭ��
* ���������Լ�������һ��
*/



#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>// �����

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees);

// Common Headers
#include "vec3.h"
#include "ray.h"
#endif
