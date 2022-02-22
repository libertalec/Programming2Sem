
#include "CRegular_polygon.h"


    void CRegular_polygon::cosine(CPoint f_vec1, CPoint general, CPoint f_vec2, int pos) {
        double vector1_x;
        double vector1_y;
        double vector2_x;
        double vector2_y;

        double scalar;
        double cosin;

        double length_vec1;
        double length_vec2;

        vector1_x = f_vec1.getX() - general.getX();
        vector1_y = f_vec1.getY() - general.getY();

        vector2_x = f_vec2.getX() - general.getX();
        vector2_y = f_vec2.getY() - general.getY();

        length_vec1 = sqrt((vector1_x * vector1_x) + (vector1_y * vector1_y));
        length_vec2 = sqrt((vector2_x * vector2_x) + (vector2_y * vector2_y));

        scalar = vector1_x * vector2_x + vector1_y * vector2_y;

        cosin = (scalar) / (length_vec1 * length_vec2);
        angle[pos] = std::abs(cosin);


    }


CRegular_polygon::CRegular_polygon(int number_vertices) : CPolygon(number_vertices) {
        number_vertices_ = number_vertices;
        angle = std::vector<double>(number_vertices_);
        bool ang = false;
        if (number_vertices_ <= 2) {
            std::cout << "There must be at least 3 points in a closed polyline" << std::endl;
            throw -1;
        }
        if (check) {
            std::cout << "The figure should not be self-intersected" << std::endl;
            throw -1;
        }

        for (int i = 0; i < number_vertices_; i++) {
            if (i + 2 < number_vertices_) {
                cosine(vertexes[i], vertexes[i + 1], vertexes[i + 2], i);
            }
        }
        for (int i = number_vertices_ - 1; i > 0; i--) {
            if (i - 2 > 0) {
                cosine(vertexes[i], vertexes[i - 1], vertexes[i - 2], i);
            }
        }
        cosine(vertexes[number_vertices_ - 1], vertexes[0], vertexes[1], number_vertices_ - 1);

        for (int i = 0; i < number_vertices_; i++) {
            if (std::abs(angle[0] - angle[i]) <= 0.001) {
                ang = true;
            } else {
                ang = false;
                break;
            }
        }
        if (!ang) {
            std::cout << "The angles should be the same" << std::endl;
            throw -1;
        }

    }

CRegular_polygon::CRegular_polygon(const CPolyline &other) : CPolygon(other) {
        if (number_vertices_ <= 2) {
            std::cout << "There must be at least 3 points in a closed polyline" << std::endl;
            throw -1;
        }
    }

    CRegular_polygon &CRegular_polygon::operator=(const CPolygon &other) {
        CPolygon::operator=(other);

    }


    void CRegular_polygon::radius_described() {
        double r;
        double denominator;

        denominator = 2 * tan(pi / number_vertices_);
        r = (edges[0]) / (denominator);
        std::cout << r << std::endl;
    }

    void CRegular_polygon::radius_inscribed() {
        double r;
        double denominator;

        denominator = 2 * sin(pi / number_vertices_);
        r = (edges[0]) / (denominator);
        std::cout << r << std::endl;
    }

void CRegular_polygon::square_() {
    std::cout << "Regular polygon area: " << square_CPolyline << std::endl;
}

void CRegular_polygon::perimeter() {
    std::cout << "Regular polygon perimeter: " << length_edge << std::endl;
}

CRegular_polygon::~CRegular_polygon(){};
