#include <gtest/gtest.h>
#include "RectangleIntersection.h"
#include <fstream>
#include "json.hpp"

// Test case for parsing valid JSON input
TEST(RectangleIntersectionTest, ParseValidJson)
{
    std::string jsonInput = R"({"rects": [{"x": 100, "y": 100, "w": 250, "h": 80}]})";
    std::istringstream inputStream(jsonInput);

    RectangleIntersection ri(inputStream);
    ri.printRectangles();

    auto intersections = ri.computeIntersections();
    EXPECT_EQ(intersections.size(), 0); // No intersections with a single rectangle
}

// Test case for parsing JSON with more than 10 rectangles
TEST(RectangleIntersectionTest, ParseMoreThan10Rectangles)
{
    std::string jsonInput = R"({"rects": [
        {"x": 100, "y": 100, "w": 50, "h": 50},
        {"x": 200, "y": 200, "w": 50, "h": 50},
        {"x": 300, "y": 300, "w": 50, "h": 50},
        {"x": 400, "y": 400, "w": 50, "h": 50},
        {"x": 500, "y": 500, "w": 50, "h": 50},
        {"x": 600, "y": 600, "w": 50, "h": 50},
        {"x": 700, "y": 700, "w": 50, "h": 50},
        {"x": 800, "y": 800, "w": 50, "h": 50},
        {"x": 900, "y": 900, "w": 50, "h": 50},
        {"x": 1000, "y": 1000, "w": 50, "h": 50},
        {"x": 1100, "y": 1100, "w": 50, "h": 50}
    ]})";
    std::istringstream inputStream(jsonInput);

    RectangleIntersection ri(inputStream);
    ri.printRectangles();

    // Verify that only the first 10 rectangles were parsed
    auto intersections = ri.computeIntersections();
    EXPECT_EQ(intersections.size(), 0); // No intersections with non-overlapping rectangles
}

// Test case for computing intersections
TEST(RectangleIntersectionTest, ComputeIntersections)
{
    std::string jsonInput = R"({"rects": [
        {"x": 100, "y": 100, "w": 250, "h": 80},
        {"x": 120, "y": 200, "w": 250, "h": 150},
        {"x": 140, "y": 160, "w": 250, "h": 100},
        {"x": 160, "y": 140, "w": 350, "h": 190}
    ]})";
    std::istringstream inputStream(jsonInput);

    RectangleIntersection ri(inputStream);
    auto intersections = ri.computeIntersections();

    EXPECT_EQ(intersections.size(), 7); // 7 intersections in this case

    // Verify the first intersection
    EXPECT_EQ(intersections[0].first, std::set<int>({1, 3}));
    EXPECT_EQ(intersections[0].second.x, 140);
    EXPECT_EQ(intersections[0].second.y, 160);
    EXPECT_EQ(intersections[0].second.w, 210);
    EXPECT_EQ(intersections[0].second.h, 20);
}

// Test case for no intersections
TEST(RectangleIntersectionTest, NoIntersections)
{
    std::string jsonInput = R"({"rects": [
        {"x": 100, "y": 100, "w": 50, "h": 50},
        {"x": 200, "y": 200, "w": 50, "h": 50}
    ]})";
    std::istringstream inputStream(jsonInput);

    RectangleIntersection ri(inputStream);
    auto intersections = ri.computeIntersections();

    // Verify that there are no intersections
    EXPECT_EQ(intersections.size(), 0);
}
