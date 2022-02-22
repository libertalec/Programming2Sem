//
// Created by stask on 22.02.2022.
//

#ifndef PROGA_CPOLYLINE_H
#define PROGA_CPOLYLINE_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include "CPoint.h"

class CPolyline {
protected:
    int number_vertices_;
    std::vector<CPoint> vertexes;
    double length_edge = 0;
    std::vector<double> edges;

public:

    CPolyline(int number_vertices = 0);

    CPolyline(const CPolyline &other);

    CPolyline &operator=(const CPolyline &other);

    virtual void polyline_length();

    ~CPolyline();
};


#endif //PROGA_CPOLYLINE_H
