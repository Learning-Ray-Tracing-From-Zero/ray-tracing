#ifndef RTWEEKEND_H
#define RTWEEKEND_H

/*
* 给出一些未来常用的常数和函数
* 对于 pi 来说并没有什么跨平台的标准定义（译注：这就是为什么不使用之前版本中 M_PI 宏定义的原因）
* 所以这里自己来定义一下
*/



#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>// 随机数

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
