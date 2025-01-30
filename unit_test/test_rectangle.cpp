#include <gtest/gtest.h>
#include "Rectangle.h"

// Test case for a valid intersection
TEST(RectangleTest, Intersection) {
    Rectangle r1(0, 0, 4, 4);
    Rectangle r2(2, 2, 4, 4);
    Rectangle intersect = r1.intersection(r2);

    EXPECT_EQ(intersect.x, 2);
    EXPECT_EQ(intersect.y, 2);
    EXPECT_EQ(intersect.w, 2);
    EXPECT_EQ(intersect.h, 2);
}

// Test case for rectangles touching but not overlapping
TEST(RectangleTest, TouchingButNotOverlapping) {
    Rectangle r1(0, 0, 2, 2);
    Rectangle r2(2, 0, 2, 2);
    Rectangle intersect = r1.intersection(r2);

    EXPECT_FALSE(intersect.isValid());
}

// Test case for one rectangle completely inside another
TEST(RectangleTest, OneInsideAnother) {
    Rectangle r1(0, 0, 6, 6);
    Rectangle r2(1, 1, 4, 4);
    Rectangle intersect = r1.intersection(r2);

    EXPECT_EQ(intersect.x, 1);
    EXPECT_EQ(intersect.y, 1);
    EXPECT_EQ(intersect.w, 4);
    EXPECT_EQ(intersect.h, 4);
}

// Test case for rectangles with negative dimensions (invalid rectangles)
TEST(RectangleTest, NegativeDimensions) {
    Rectangle r1(0, 0, -4, 4); // Invalid rectangle
    Rectangle r2(2, 2, 4, 4);
    Rectangle intersect = r1.intersection(r2);

    EXPECT_FALSE(intersect.isValid());
}

// Test case for rectangles with zero dimensions (invalid rectangles)
TEST(RectangleTest, ZeroDimensions) {
    Rectangle r1(0, 0, 0, 0); // Invalid rectangle
    Rectangle r2(2, 2, 4, 4);
    Rectangle intersect = r1.intersection(r2);

    EXPECT_FALSE(intersect.isValid());
}

// Test case for intersection with itself
TEST(RectangleTest, IntersectionWithItself) {
    Rectangle r1(0, 0, 4, 4);
    Rectangle intersect = r1.intersection(r1);

    EXPECT_EQ(intersect.x, 0);
    EXPECT_EQ(intersect.y, 0);
    EXPECT_EQ(intersect.w, 4);
    EXPECT_EQ(intersect.h, 4);
}

// Test case for intersection with a rectangle that has zero area
TEST(RectangleTest, IntersectionWithZeroAreaRectangle) {
    Rectangle r1(0, 0, 4, 4);
    Rectangle r2(2, 2, 0, 0); // Zero area rectangle
    Rectangle intersect = r1.intersection(r2);

    EXPECT_FALSE(intersect.isValid());
}
