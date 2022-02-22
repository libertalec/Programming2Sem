
#ifndef PROGA_CPOLYGON_H
#define PROGA_CPOLYGON_H
#include "CPoint.h"
#include "CPolyline.h"
#include "CClosed_polyline.h"

class CPolygon : public CClosed_polyline {
public:
    CPolygon(int number_vertices = 0);

    CPolygon(const CPolyline &other);

    CPolygon &operator=(const CClosed_polyline &other);

     void perimeter() override;

     void square_() override;

    ~CPolygon();
};


#endif //PROGA_CPOLYGON_H
