#ifndef RECTANGLE_H
#define RECTANGLE_H

struct Rectangle {
    int x, y; // Top-left corner
    int w, h; // Width and height

    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0);
    Rectangle intersection(const Rectangle& other) const;
    bool isValid() const;

    // Define equality operator
    bool operator==(const Rectangle& other) const {
        return x == other.x && y == other.y && w == other.w && h == other.h;
    }
};

#endif // RECTANGLE_H