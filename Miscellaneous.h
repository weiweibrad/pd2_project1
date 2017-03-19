#ifndef __MISCELLANEOUS_H__
#define __MISCELLANEOUS_H__

/*
point is for representing characters on 2D plane, for computational geometry
*/
class Point
{
public:
    int X;
    int Y;

    // sorting rule
    bool operator<(const Point &b) const;
};

/*
return distance^2 , for better performance than distance^1
*/
int distSqr(const Point &a, const Point &b);

#endif
