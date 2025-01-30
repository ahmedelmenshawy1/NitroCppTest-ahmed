#include <iostream>
#include <fstream>
#include "RectangleIntersection.h"

int main(int argc, char *argv[])
{
    bool correct_flag{};

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <json_file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    RectangleIntersection ri(file);
    correct_flag = ri.printRectangles();
    if (!correct_flag)
    {
        std::cerr << "Failed in print Rectangles \n";
        return 1;
    }
    correct_flag = ri.findIntersections();
    if (!correct_flag)
    {
        std::cerr << "Failed in find Intersections \n";
        return 1;
    }
    return 0;
}