#include "Rectangle.h"
#include <algorithm>

Rectangle::Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

Rectangle Rectangle::intersection(const Rectangle &other) const
{
    int x1 = std::max(x, other.x);
    int y1 = std::max(y, other.y);
    int x2 = std::min(x + w, other.x + other.w);
    int y2 = std::min(y + h, other.y + other.h);

    if (x2 > x1 && y2 > y1)
    {
        return {x1, y1, x2 - x1, y2 - y1};
    }
    else
    {
        return {0, 0, 0, 0};
    }
}

bool Rectangle::isValid() const
{
    return w > 0 && h > 0;
}