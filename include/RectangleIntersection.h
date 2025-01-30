#ifndef RECTANGLEINTERSECTION_H
#define RECTANGLEINTERSECTION_H

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include "Rectangle.h"

class RectangleIntersection
{
public:
    RectangleIntersection(std::istream &inputStream);
    bool printRectangles() const;
    bool findIntersections() const;
    std::vector<std::pair<std::set<int>, Rectangle>> computeIntersections() const;

private:
    std::vector<Rectangle> rectangles{};
    bool error_flag{};

    std::vector<Rectangle> parseRectangles(std::istream &inputStream);
    void printIntersections(const std::vector<std::pair<std::set<int>, Rectangle>> &intersections) const;
};

#endif // RECTANGLEINTERSECTION_H