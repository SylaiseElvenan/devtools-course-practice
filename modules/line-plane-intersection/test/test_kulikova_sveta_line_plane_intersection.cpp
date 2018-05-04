// Copyright 2018 Kulikova Svetlana

#include <gtest/gtest.h>

#include "include/line_plane_intersection.h"

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, Intersect1) {
    // Arrange
    xyz Line1 = { 0, 9, -11 };
    xyz Line2 = { 1, 12, -14 };
    xyz Plane1 = { 0, 0, 3 };
    xyz Plane2 = { 0, 1, 1 };
    xyz Plane3 = { -3, 0, 0 };
    xyz EQ = { -2, 3, -5 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_EQ(EQ, res);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, Intersect2) {
    // Arrange
    xyz Line1 = { 0, 3, -4 };
    xyz Line2 = { -3, 0, 3.5 };
    xyz Plane1 = { 0, 1, 7 };
    xyz Plane2 = { -1, 5, 4 };
    xyz Plane3 = { -2, 3, 1 };
    xyz EQ = { -2, 1, 1 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_EQ(EQ, res);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, NotIntersect) {
    // Arrange
    xyz Line1 = { 0, -2, 1 };
    xyz Line2 = { 1, 0, 1 };
    xyz Plane1 = { 0, 1, 0 };
    xyz Plane2 = { -0.5, 0, 0 };
    xyz Plane3 = { 1, 0, 1 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, NotEqualX) {
    // Arrange
    xyz A = { 0, 0, 0 };
    xyz B = { 1, 0, 0 };
    bool res;

    // Act
    res = !(A == B);

    // Assert
    EXPECT_TRUE(res);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, NotEqualY) {
    // Arrange
    xyz A = { 0, 0, 0 };
    xyz B = { 0, 1, 0 };
    bool res;

    // Act
    res = !(A == B);

    // Assert
    EXPECT_TRUE(res);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, NotEqualZ) {
    // Arrange
    xyz A = { 0, 0, 0 };
    xyz B = { 0, 0, 1 };
    bool res;

    // Act
    res = !(A == B);

    // Assert
    EXPECT_TRUE(res);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectLine) {
    // Arrange
    xyz Line1 = { 0, 0, 0 };
    xyz Line2 = { 0, 0, 0 };
    xyz Plane1 = { 0, 1, 0 };
    xyz Plane2 = { -0.5, 0, 0 };
    xyz Plane3 = { 1, 0, 1 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneA) {
    // Arrange
    xyz Line1 = { 0, 0, 0 };
    xyz Line2 = { 0, 1, 0 };
    xyz Plane1 = { 0, 0, 0 };
    xyz Plane2 = { 0, 0, 0 };
    xyz Plane3 = { 0, 1, 0 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneB) {
    // Arrange
    xyz Line1 = { 0, 0, 0 };
    xyz Line2 = { 0, 1, 0 };
    xyz Plane1 = { 0, 0, 0 };
    xyz Plane2 = { 0, 1, 0 };
    xyz Plane3 = { 0, 0, 0 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneC) {
    // Arrange
    xyz Line1 = { 0, 0, 0 };
    xyz Line2 = { 0, 1, 0 };
    xyz Plane1 = { 0, 1, 0 };
    xyz Plane2 = { 0, 0, 0 };
    xyz Plane3 = { 0, 0, 0 };
    xyz res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}
