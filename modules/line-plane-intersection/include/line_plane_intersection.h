// Copyright 2018 Kulikova Svetlana

#include <cmath>

#ifndef MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_
#define MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_

struct xyz {
    double x, y, z;

    xyz() {
        x = y = z = INFINITY;
    }

    xyz(const xyz& A) {
        x = A.x;
        y = A.y;
        z = A.z;
    }

    xyz(double x_, double y_, double z_) {
        x = x_;
        y = y_;
        z = z_;
    }

    xyz& operator = (const xyz& A) {
        x = A.x;
        y = A.y;
        z = A.z;
        return *this;
    }

    bool operator == (const xyz& A) const {
        if (x != A.x)
            return false;
        if (y != A.y)
            return false;
        if (z != A.z)
            return false;
        return true;
    }
};

class line_plane_intersection {
 public:
    line_plane_intersection();

    xyz PlaneIntersectLine(xyz A, xyz B, xyz C, xyz X, xyz Y);
    bool GetNotIntersectPlaneLine();

 private:
    bool NotIntersectPlaneLine;

    xyz CreateVector(xyz A, xyz B);
    xyz VectorProduct(xyz A, xyz B);
    double DotProduct(xyz A, xyz B);
    bool IncorrectLine(xyz A, xyz B);
    bool IncorrectPlane(xyz A, xyz B, xyz C);
    void Normalize(xyz A);
};

#endif  // MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_
