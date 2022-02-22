

#include "CTriangle.h"


void CTriangle::square_ClosedPolyline() {

    half_meter = 0.5 * length_edge;

    double a = half_meter - edges[0];
    double b = half_meter - edges[1];
    double c = half_meter - edges[2];

    area_triangle = sqrt(half_meter * (a) * (b) * (c));
}


CTriangle::CTriangle(int number_vertices) : CPolygon(number_vertices) {
    number_vertices_ = number_vertices;
    if (number_vertices_ != 3) {
        std::cout << "There should be exactly 3 vertices in the triangle" << std::endl;
        throw -1;
    }
    square_ClosedPolyline();

}

CTriangle::CTriangle(const CPolygon &other) : CPolygon(other) {
    if (number_vertices_ != 3) {
        std::cout << "There should be exactly 3 vertices in the triangle" << std::endl;
        throw -1;
    }
}

CTriangle &CTriangle::operator=(const CPolygon &other) {
    CPolygon::operator=(other);

}


void CTriangle::radius_described() {
    half_meter = 0.5 * length_edge;

    double a = half_meter - edges[0];
    double b = half_meter - edges[1];
    double c = half_meter - edges[2];

    area_triangle = sqrt(half_meter * (a) * (b) * (c));

    double radius;
    radius = (edges[0] * edges[1] * edges[2]) / (4 * area_triangle);
    std::cout << radius << std::endl;
}

void CTriangle::radius_inscribed() {
    half_meter = 0.5 * length_edge;

    double a = half_meter - edges[0];
    double b = half_meter - edges[1];
    double c = half_meter - edges[2];

    area_triangle = sqrt(half_meter * (a) * (b) * (c));

    double radius;
    radius = area_triangle / half_meter;
    std::cout << radius << std::endl;
}

void CTriangle::square_() {
    std::cout << "Triangle area: " << area_triangle << std::endl;
}

void CTriangle::perimeter() {
    std::cout << "Triangle perimeter: " << length_edge << std::endl;
}

CTriangle::~CTriangle() {};

