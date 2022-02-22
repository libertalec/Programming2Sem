//
// Created by stask on 22.02.2022.
//

#ifndef PROGA_CPOINT_H
#define PROGA_CPOINT_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

class CPoint {
private:
    double x_;
    double y_;
public:
    CPoint(double x = 0, double y = 0);

    CPoint(const CPoint &other);

    CPoint &operator=(const CPoint &other);

    CPoint operator+(CPoint const &other) const;

    CPoint operator*(double c) const;

    void setX(double x);

    void setY(double y);

    double getX();

    double getY();

    ~CPoint();
};

#endif //PROGA_CPOINT_H
