// Copyright 2018 Kulikova Svetlana

#include "include/line_plane_intersection.h"

line_plane_intersection::line_plane_intersection() :
    NotIntersectPlaneLine(true) {}

xyz line_plane_intersection::CreateVector(xyz A, xyz B) {
    xyz CreateVector;

    CreateVector.x = B.x - A.x;
    CreateVector.y = B.y - A.y;
    CreateVector.z = B.z - A.z;

    return CreateVector;
}

xyz line_plane_intersection::VectorProduct(xyz A, xyz B) {
    xyz VP;

    VP.x = A.y * B.z - B.y * A.z;
    VP.y = A.z * B.x - B.z * A.x;
    VP.z = A.x * B.y - B.x * A.y;

    return VP;
}

double line_plane_intersection::DotProduct(xyz A, xyz B) {
    double SP;

    SP = A.x * B.x + A.y * B.y + A.z * B.z;

    return SP;
}

void line_plane_intersection::Normalize(xyz A) {
    double mlr;

    mlr = sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    A.x = A.x / mlr;
    A.y = A.y / mlr;
    A.z = A.z / mlr;
}

bool line_plane_intersection::IncorrectLine(xyz A, xyz B) {
    if (A == B)
        return true;
    return false;
}

bool line_plane_intersection::IncorrectPlane(xyz A, xyz B, xyz C) {
    if (A == B)
        return true;
    if (A == C)
        return true;
    if (B == C)
        return true;
    return false;
}

xyz line_plane_intersection::PlaneIntersectLine(xyz A,
    xyz B, xyz C, xyz X, xyz Y) {
    xyz N, V, W, PlaneIntersectLine;
    double e, d;

    NotIntersectPlaneLine = true;

    if (IncorrectLine(X, Y))
        return PlaneIntersectLine;

    if (IncorrectPlane(A, B, C))
        return PlaneIntersectLine;

    N = VectorProduct(CreateVector(A, B), CreateVector(A, C));
    Normalize(N);
    V = CreateVector(X, A);
    d = DotProduct(N, V);
    W = CreateVector(X, Y);
    e = DotProduct(N, W);

    if (e != 0) {
        PlaneIntersectLine.x = X.x + W.x * d / e;
        PlaneIntersectLine.y = X.y + W.y * d / e;
        PlaneIntersectLine.z = X.z + W.z * d / e;
        NotIntersectPlaneLine = false;
    }

    return PlaneIntersectLine;
}

bool line_plane_intersection::GetNotIntersectPlaneLine() {
    return NotIntersectPlaneLine;
}
