// Copyright 2023 Kandrin Alexey

#include <cstdlib>
#include <cerrno>
#include <regex>

#include "include/TriangleApp.h"
#include "include/triangle.h"

static const std::string triangleToken{ "triangle" };
static const std::string pointToken{ "point" };

static bool IsFloatNumber(const std::string& str) {
    static std::regex floatNumberRegex{ R"(^(?:\d+(?:\.\d*)?|\.\d+)$)" }; // "123" "123.123" "123." ".123"
    return std::regex_match(str, floatNumberRegex);
}

std::string TriangleApp::help() {
    return std::string{ "With this application you can determine if a point falls within a triangle.\n\n" } +
        "Parameters:\n" +
        triangleToken + " <x1 y1 x2 y2 x3 y3>\t\t Input coords of triangle.\n" +
        pointToken + " <x0 y0> \t\t Input coords of point.\n";
}

std::string TriangleApp::operator()(int argc, const char** argv) {
    if (argc == 1)
        return help();

    std::unique_ptr<Triangle> triangle;
    std::unique_ptr<Point> point;

    auto readPoints = [argc, argv](int& argvIndex, double* coords, int coordsCount)
    {
        for (int coordIndex = 0; argvIndex < argc && coordIndex < coordsCount; ++argvIndex, ++coordIndex)
        {
            if (!IsFloatNumber(argv[argvIndex]))
                return false;
            coords[coordIndex] = atof(argv[argvIndex]);
        }
        --argvIndex;
        return true;
    };

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == triangleToken) {
            ++i;

            const int coordsCount = 6;
            double coords[coordsCount] = {};
            if (!readPoints(i, coords, coordsCount))
                return "Error: incorrect param in " + triangleToken;

            triangle = std::make_unique<Triangle>(
                Point{ coords[0], coords[1] },
                Point{ coords[2], coords[3] },
                Point{ coords[4], coords[5] });
        }
        else if (argv[i] == pointToken) {
            ++i;

            const int coordsCount = 2;
            double coords[coordsCount] = {};
            if (!readPoints(i, coords, coordsCount))
                return "Error: incorrect param in " + pointToken;

            point = std::unique_ptr<Point>(new Point{ coords[0], coords[1] });
        }
        else {
            return std::string("Error: unknown key ") + argv[i];
        }
    }

    if (triangle && point)
        return triangle->Consist(*point) ? "Triangle contains point" : "Triangle does not contain point";
    else
    {
        return "Error: missing " + (!triangle ? triangleToken : pointToken) + " parameter";
    }
}
