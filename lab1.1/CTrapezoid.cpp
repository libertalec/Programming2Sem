
#include "CTrapezoid.h"


void CTrapezoid::checking_parallelism() {
    double x_a, y_a, x_b, y_b;
    k = std::vector<double>(number_vertices_);
    for (int i = 0; i < number_vertices_; i++) {
        if (i + 1 == number_vertices_) {
            x_a = vertexes[0].getX();
            y_a = vertexes[0].getY();
            x_b = vertexes[i].getX();
            y_b = vertexes[i].getY();
            if (x_a - x_b == 0) {
                basis = false;
                edge = false;
                break;
            }

            coefficient = (y_b - y_a) / (x_b - x_a);

            k[i] = coefficient;
        } else {
            x_a = vertexes[i].getX();
            y_a = vertexes[i].getY();
            x_b = vertexes[i + 1].getX();
            y_b = vertexes[i + 1].getY();
            if (x_a - x_b == 0) {
                basis = false;
                edge = false;
                break;
            }

            coefficient = (y_b - y_a) / (x_b - x_a);

            k[i] = coefficient;
        }


    }
}


CTrapezoid::CTrapezoid(int number_vertices) : CPolygon(number_vertices) {
    number_vertices_ = number_vertices;
    if (number_vertices_ != 4) {
        std::cout << "There should be 4 vertices in the trapezoid" << std::endl;
        throw -1;
    }

    checking_parallelism();
    if ((k[0] == k[2] && k[1] != k[3]) || (k[0] != k[2] && k[1] == k[3])) {

    } else {
        std::cout << "There should be two parallel edges in the trapezoid" << std::endl;
        throw -1;
    }

}


CTrapezoid::CTrapezoid(const CPolygon &other) : CPolygon(other) {
    if (number_vertices_ != 4) {
        std::cout << "There should be 4 vertices in the trapezoid" << std::endl;
        throw -1;
    }
}

CTrapezoid &CTrapezoid::operator=(const CPolygon &other) {
    CPolygon::operator=(other);

}

void CTrapezoid::height() {
    square_ClosedPolyline();
    polyline_length();

    double h;
    if (k[0] == k[2] && k[1] != k[3]) {
        h = square_CPolyline / ((edges[0] + edges[2]) / 2);
    } else if (k[0] != k[2] && k[1] == k[3]) {
        h = square_CPolyline / ((edges[1] + edges[3]) / 2);
    }

    std::cout << h << std::endl;
}

void CTrapezoid::square_() {
    std::cout << "Trapezoid area: " << square_CPolyline << std::endl;
}

void CTrapezoid::perimeter() {
    std::cout << "Trapezoid perimeter: " << length_edge << std::endl;
}

CTrapezoid::~CTrapezoid() {};
