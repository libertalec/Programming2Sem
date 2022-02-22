

#ifndef PROGA_CTRIANGLE_H
#define PROGA_CTRIANGLE_H

#include "CPoint.h"
#include "CPolyline.h"
#include "CClosed_polyline.h"
#include "CPolygon.h"

class CTriangle : public CPolygon {
private:
    double half_meter;
    double area_triangle;

    void square_ClosedPolyline() override;

public:
    CTriangle(int number_vertices = 0);

    CTriangle(const CPolygon &other);

    CTriangle &operator=(const CPolygon &other);


    void radius_described();

    void radius_inscribed();

    void square_() override;
    void perimeter() override;

    ~CTriangle();

};


#endif //PROGA_CTRIANGLE_H
