//
// Created by stask on 22.02.2022.
//

#ifndef PROGA_CCLOSED_POLYLINE_H
#define PROGA_CCLOSED_POLYLINE_H
#include "CPoint.h"
#include "CPolyline.h"


class CClosed_polyline : public CPolyline {
protected:
    bool check = false;
    double square_CPolyline = 0;

    virtual void square_ClosedPolyline();

    bool static comp(CPoint a, CPoint b);

    double a_x1, a_y1, a_x2, a_y2;
    std::string answer = "-";
    int score;


    void intersection(double x1, double y1, double x2, double y2, double x3, double y3,
                      double x4, double y4);

    void polyline_length() override;

public:
    CClosed_polyline(int number_vertices = 0);

    CClosed_polyline(const CPolyline &other);

    CClosed_polyline &operator=(const CPolyline &other);

    virtual void perimeter();

    virtual void square_();

    ~CClosed_polyline();
};


#endif //PROGA_CCLOSED_POLYLINE_H
