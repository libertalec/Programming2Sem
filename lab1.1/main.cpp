#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include "CPoint.h"
#include "CPolyline.h"
#include "CClosed_polyline.h"
#include "CPolygon.h"
#include "CTriangle.h"
#include "CTrapezoid.h"
#include "CRegular_polygon.h"


int main() {

    std::vector<CPolygon *> information(4);
    CPolygon one(5);
    CTriangle two(3);
    CTrapezoid three(4);
    CRegular_polygon four(5);

    information[0] = &one;
    information[1] = &two;
    information[2] = &three;
    information[3] = &four;

    for (int i = 0; i < 4; i++) {
        information[i]->square_();
        information[i]->perimeter();

        std::cout << std::endl;
    }


    return 0;
}