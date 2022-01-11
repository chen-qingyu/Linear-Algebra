#ifndef DOUBLE_H
#define DOUBLE_H

#include <cfloat>
#include <cmath>

/*******************
 * inline function
 *******************/

// EQual
inline bool eq(const double& a, const double& b)
{
    return std::abs(a - b) < 4 * DBL_EPSILON;
}

// Not Equal
inline bool ne(const double& a, const double& b)
{
    return !eq(a, b);
}

// Greater Than
inline bool gt(const double& a, const double& b)
{
    return a - b > 4 * DBL_EPSILON;
}

// Less Than
inline bool lt(const double& a, const double& b)
{
    return b - a > 4 * DBL_EPSILON;
}

// Greater than or Equal
inline bool ge(const double& a, const double& b)
{
    return gt(a, b) || eq(a, b);
}

// Less than or Equal
inline bool le(const double& a, const double& b)
{
    return lt(a, b) || eq(a, b);
}

#endif // DOUBLE_H
