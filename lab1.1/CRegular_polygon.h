

#ifndef PROGA_CREGULAR_POLYGON_H
#define PROGA_CREGULAR_POLYGON_H
#include "CPoint.h"
#include "CPolyline.h"
#include "CClosed_polyline.h"
#include "CPolygon.h"

class CRegular_polygon : public CPolygon {
private:
    double pi = 3.1415926535;
    std::vector<double> angle;

    void cosine(CPoint f_vec1, CPoint general, CPoint f_vec2, int pos);

public:
    CRegular_polygon(int number_vertices = 0);

    CRegular_polygon(const CPolyline &other);

    CRegular_polygon &operator=(const CPolygon &other);


    void radius_described();

    void radius_inscribed();

    void perimeter() override;

    void square_() override;

    ~CRegular_polygon();
};


#endif //PROGA_CREGULAR_POLYGON_H
