
#include "CPoint.h"

CPoint::CPoint(double x, double y) : x_(x), y_(y) {

}

CPoint::CPoint(const CPoint &other) : x_(other.x_), y_(other.y_) {

}

CPoint &CPoint::operator=(const CPoint &other) {
    x_ = other.x_;
    y_ = other.y_;
    return *this;
}

CPoint CPoint::operator+(CPoint const &other) const { return CPoint(x_ + other.x_, y_ + other.y_); }

CPoint CPoint:: operator*(double c) const { return CPoint(x_ * c, y_ * c); }

void CPoint::setX(double x) {
    x_ = x;
}

void CPoint::setY(double y) {
    y_ = y;
}

double CPoint::getX() {
    return x_;
}

double CPoint::getY() {
    return y_;
}

CPoint::~CPoint() {}

