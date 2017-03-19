#include "Miscellaneous.h"

bool Point::operator<(const Point &b) const
{
    if(X == b.X)
        return Y < b.Y;
    return X < b.X;
}

int distSqr(const Point &a, const Point &b)
{
    int x = a.X - b.X;
    int y = a.Y - b.Y;
    return x*x + y*y;
}
