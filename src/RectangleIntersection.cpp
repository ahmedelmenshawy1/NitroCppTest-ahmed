#include "RectangleIntersection.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include "json.hpp"

using json = nlohmann::json;

static constexpr int max_rectangles{10};

RectangleIntersection::RectangleIntersection(std::istream &inputStream)
{
    rectangles = parseRectangles(inputStream);
}

std::vector<Rectangle> RectangleIntersection::parseRectangles(std::istream &inputStream)
{
    std::vector<Rectangle> rects{};
    try
    {
        json jsonData{};
        inputStream >> jsonData;

        int count{};
        for (const auto &rectData : jsonData["rects"])
        {
            if (++count > max_rectangles)
            {
                std::cout << "Taking only the first " << max_rectangles << " rectangles.\n";
                break;
            }
            rects.emplace_back(rectData["x"], rectData["y"], rectData["w"], rectData["h"]);
        }
    }
    catch (const nlohmann::json::parse_error &e)
    {
        std::cerr << "JSON parsing error: " << e.what() << "\n";
        error_flag = true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        error_flag = true;
    }
    return rects;
}

bool RectangleIntersection::printRectangles() const
{
    if (error_flag)
        return false;
    std::cout << "Input:\n";
    for (size_t i{}; i < rectangles.size(); ++i)
    {
        std::cout << i + 1 << ": Rectangle at (" << rectangles[i].x << "," << rectangles[i].y
                  << "), w=" << rectangles[i].w << ", h=" << rectangles[i].h << ".\n";
    }
    std::cout << "\n";
    return true;
}

std::vector<std::pair<std::set<int>, Rectangle>> RectangleIntersection::computeIntersections() const
{
    std::vector<std::pair<std::set<int>, Rectangle>> intersections{};

    auto addIntersection = [&](const std::set<int> &contributors, const Rectangle &intersect)
    {
        if (intersect.isValid())
        {
            // Check if this intersection is already in the list
            bool isDuplicate = false;
            for (const auto &[existingContributors, existingIntersect] : intersections)
            {
                if (existingContributors == contributors && existingIntersect == intersect)
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate)
            {
                intersections.emplace_back(contributors, intersect);
            }
        }
    };

    for (size_t i{}; i < rectangles.size(); ++i)
    {
        for (size_t j{i + 1}; j < rectangles.size(); ++j)
        {
            Rectangle intersect = rectangles[i].intersection(rectangles[j]);
            addIntersection({static_cast<int>(i + 1), static_cast<int>(j + 1)}, intersect);
        }
    }

    // Compute higher-order intersections (3 or more rectangles)
    for (size_t i{}; i < intersections.size(); ++i)
    {
        const auto &[contributors, intersect] = intersections[i];
        for (size_t k{}; k < rectangles.size(); ++k)
        {
            if (contributors.find(static_cast<int>(k + 1)) == contributors.end())
            {
                Rectangle newIntersect = intersect.intersection(rectangles[k]);
                if (newIntersect.isValid())
                {
                    std::set<int> newContributors = contributors;
                    newContributors.insert(static_cast<int>(k + 1));
                    addIntersection(newContributors, newIntersect);
                }
            }
        }
    }

    std::sort(intersections.begin(), intersections.end(),
              [](const auto &a, const auto &b)
              {
                  return a.first.size() < b.first.size();
              });

    return intersections;
}

void RectangleIntersection::printIntersections(const std::vector<std::pair<std::set<int>, Rectangle>> &intersections) const
{
    for (const auto &[contributors, intersect] : intersections)
    {
        std::cout << "Intersection between rectangles ";
        for (auto it = contributors.begin(); it != contributors.end(); ++it)
        {
            if (it != contributors.begin())
                std::cout << (contributors.size() > 2 ? ", " : " and ");
            std::cout << *it;
        }
        std::cout << " at (" << intersect.x << "," << intersect.y
                  << "), w=" << intersect.w << ", h=" << intersect.h << ".\n";
    }
}

bool RectangleIntersection::findIntersections() const
{
    if (error_flag)
        return false;

    auto intersections = computeIntersections();
    printIntersections(intersections);
    return true;
}