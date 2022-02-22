

#ifndef PROGA_CTRAPEZOID_H
#define PROGA_CTRAPEZOID_H

#include "CPoint.h"
#include "CPolyline.h"
#include "CClosed_polyline.h"
#include "CPolygon.h"

class CTrapezoid : public CPolygon {
private:
    std::vector<double> k;
    bool basis = false;
    bool edge = false;
    double coefficient;

    void checking_parallelism();

public:
    CTrapezoid(int number_vertices = 0);


    CTrapezoid(const CPolygon &other);

    CTrapezoid &operator=(const CPolygon &other);

    void height();

    void perimeter() override;

    void square_() override;

    ~CTrapezoid();
};


#endif //PROGA_CTRAPEZOID_H
