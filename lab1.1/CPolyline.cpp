
#include "CPolyline.h"

CPolyline::CPolyline(int number_vertices) : number_vertices_(number_vertices) {

    vertexes = std::vector<CPoint>(number_vertices_, CPoint());
    double x, y;

    for (int i = 0; i < number_vertices_; i++) {
        std::cin >> x >> y;
        vertexes[i].setX(x);
        vertexes[i].setY(y);
    }
    edges = std::vector<double>(number_vertices_ - 1);
}


CPolyline::CPolyline(const CPolyline &other) : number_vertices_(other.number_vertices_) {
    vertexes = std::vector<CPoint>(number_vertices_, CPoint());

    for (int i = 0; i < other.number_vertices_; i++) {
        vertexes[i] = other.vertexes[i];
    }
    edges = std::vector<double>(other.edges.size());

    for (int i = 0; i < edges.size(); i++) {
        edges[i] = other.edges[i];
    }
    length_edge = other.length_edge;

}

CPolyline &CPolyline::operator=(const CPolyline &other) {

    number_vertices_ = other.number_vertices_;

    vertexes.resize(number_vertices_);

    for (int i = 0; i < number_vertices_; i++) {
        vertexes[i] = other.vertexes[i];
    }

    edges.resize(number_vertices_);

    for (int i = 0; i < edges.size(); i++) {
        edges[i] = other.edges[i];
    }

    length_edge = other.length_edge;

    return *this;

}

void CPolyline::polyline_length() {

    for (int i = 0; i < number_vertices_ - 1; i++) {

        double x_a, y_a, x_b, y_b;
        x_a = vertexes[i].getX();
        y_a = vertexes[i].getY();
        x_b = vertexes[i + 1].getX();
        y_b = vertexes[i + 1].getY();

        length_edge = std::sqrt((x_b - x_a) * (x_b - x_a) + (y_b - y_a) * (y_b - y_a));

        edges[i] = length_edge;
    }
    length_edge = 0;
    for (int i = 0; i < edges.size(); i++) {
        length_edge += edges[i];
    }
    std::cout << length_edge << std::endl;


}

CPolyline::~CPolyline() {};