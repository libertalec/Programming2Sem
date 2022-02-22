
#include "CPolygon.h"


CPolygon::CPolygon(int number_vertices) : CClosed_polyline(number_vertices) {
    number_vertices_ = number_vertices;
    if (number_vertices_ <= 2) {
        std::cout << "There must be at least 3 points in a closed polyline" << std::endl;
        throw -1;
    }

    if (check) {
        std::cout << "The figure should not be self-intersected" << std::endl;
        throw -1;
    }

}

CPolygon::CPolygon(const CPolyline &other) : CClosed_polyline(other) {
    if (number_vertices_ <= 2) {
        std::cout << "There must be at least 3 points in a closed polyline" << std::endl;
        throw -1;
    }
}

CPolygon &CPolygon::operator=(const CClosed_polyline &other) {
    CClosed_polyline::operator=(other);

}

void CPolygon::perimeter() {
    std::cout << "Polygon perimeter: " << length_edge << std::endl;
}

void CPolygon::square_() {
    std::cout << "Polygon area: " << square_CPolyline << std::endl;
}

CPolygon::~CPolygon() {}