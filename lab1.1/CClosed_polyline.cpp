
#include "CClosed_polyline.h"


 void CClosed_polyline::square_ClosedPolyline() {
        double x, y;
        double expression1 = 0;
        double expression2 = 0;

        for (int i = 0; i < number_vertices_ - 1; i++) {
            x = vertexes[i].getX();
            y = vertexes[i + 1].getY();
            expression1 += x * y;
        }
        x = vertexes[number_vertices_ - 1].getX();
        y = vertexes[0].getY();
        expression1 += x * y;

        for (int i = 0; i < number_vertices_ - 1; i++) {
            x = vertexes[i + 1].getX();
            y = vertexes[i].getY();
            expression2 -= x * y;
        }
        x = vertexes[0].getX();
        y = vertexes[number_vertices_ - 1].getY();
        expression2 -= x * y;
        square_CPolyline = 0.5 * (std::abs(expression1 - std::abs(expression2)));
    }

    bool CClosed_polyline:: comp(CPoint a, CPoint b) {
        return a.getX() < b.getX();
    }




    void CClosed_polyline::intersection(double x1, double y1, double x2, double y2, double x3, double y3,
                      double x4, double y4) {
        std::vector<CPoint> p(4);
        p[0] = CPoint(x1, y1);
        p[1] = CPoint(x2, y2);
        p[2] = CPoint(x3, y3);
        p[3] = CPoint(x4, y4);
        sort(p.begin(), p.end(), comp);


        double X, Y, Z;

        X = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4));
        Y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4));
        Z = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (Z == 0) {
            if (X == 0 && Y == 0) {
// cout << -1;//здесь нужно проверить пересекаются ли отрезки
                if ((std::min(x1, x2) <= x3 && x3 <= std::max(x1, x2) ||
                     std::min(x1, x2) <= x4 && x4 <= std::max(x1, x2) ||
                     std::min(x3, x4) <= x1 && x1 <= std::max(x3, x4) ||
                     std::min(x3, x4) <= x2 && x2 <= std::max(x3, x4))) {
                    if (p[1].getX() == p[2].getX() && p[1].getY() == p[2].getY()) {
                        a_x1 = p[1].getX();
                        a_y1 = p[1].getY();
                        score = 2;

                    } else {
                        a_x1 = p[1].getX();
                        a_y1 = p[1].getY();
                        a_x2 = p[2].getX();
                        a_y2 = p[2].getY();
                        score = 4;
                    }
                } else {
                    answer = "Empty";
                }
            } else {
                answer = "Empty";
            }
        } else {
            if ((x1 * Z <= X && X <= x2 * Z || x2 * Z <= X && X <= x1 * Z)
                && (y1 * Z <= Y && Y <= y2 * Z ||
                    y2 * Z <= Y && Y <= y1 * Z)) {
                a_x1 = (double) X / Z;
                a_y1 = (double) Y / Z;
                score = 2;
            } else {
                answer = "Empty";
            }

        }

    }

    void CClosed_polyline:: polyline_length()  {
        double x_a, y_a, x_b, y_b;
        edges = std::vector<double>(number_vertices_);
        for (int i = 0; i < number_vertices_; i++) {
            if (i + 1 == number_vertices_) {
                x_a = vertexes[0].getX();
                y_a = vertexes[0].getY();
                x_b = vertexes[i].getX();
                y_b = vertexes[i].getY();

                length_edge = std::sqrt((x_b - x_a) * (x_b - x_a) + (y_b - y_a) * (y_b - y_a));

                edges[i] = length_edge;
            } else {
                x_a = vertexes[i].getX();
                y_a = vertexes[i].getY();
                x_b = vertexes[i + 1].getX();
                y_b = vertexes[i + 1].getY();

                length_edge = std::sqrt((x_b - x_a) * (x_b - x_a) + (y_b - y_a) * (y_b - y_a));

                edges[i] = length_edge;
            }


        }
        length_edge = 0;
        for (int i = 0; i < edges.size(); i++) {
            length_edge += edges[i];
        }
    }


CClosed_polyline::CClosed_polyline(int number_vertices) : CPolyline(number_vertices) {

        number_vertices_ = number_vertices;
        edges = std::vector<double>(number_vertices_);

        if (number_vertices_ <= 2) {
            std::cout << "There must be at least 3 points in a closed polyline" << std::endl;
            throw -1;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (check) {
                break;
            }
            for (int z = 0; z < edges.size() - 1; z++) {
                if (z + 1 < number_vertices_ && i + 1 < number_vertices_) {
                    intersection(vertexes[i].getX(), vertexes[i].getY(), vertexes[i + 1].getX(), vertexes[i + 1].getY(),
                                 vertexes[z].getX(), vertexes[z].getY(), vertexes[z + 1].getX(),
                                 vertexes[z + 1].getY());

                    if (answer == "Empty") {
                        check = false;
                        answer = "-";
                        break;

                    } else {
                        if (score == 2) {
                            if ((a_x1 == vertexes[i].getX() && a_y1 == vertexes[i].getY()) ||
                                (a_x1 == vertexes[i + 1].getX() && a_y1 == vertexes[i + 1].getY())) {
                                check = false;
                            } else {
                                check = true;
                                break;
                            }
                        }
                    }
                }

                score = 0;

            }
        }

        polyline_length();
        square_ClosedPolyline();

    }

CClosed_polyline::CClosed_polyline(const CPolyline &other) : CPolyline(other) {
        if (number_vertices_ <= 2) {
            std::cout << "There must be at least 3 points in a closed polyline" << std::endl;
            throw -1;
        }


    }

    CClosed_polyline &CClosed_polyline::operator=(const CPolyline &other) {
        CPolyline::operator=(other);

    }

    void CClosed_polyline::perimeter() {
        std::cout << length_edge << std::endl;
    }

     void CClosed_polyline::square_() {
        std::cout << square_CPolyline << std::endl;
    }

CClosed_polyline:: ~CClosed_polyline() {}
