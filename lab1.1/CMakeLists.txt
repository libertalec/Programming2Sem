cmake_minimum_required(VERSION 3.21)
project(proga)

set(CMAKE_CXX_STANDARD 20)

add_executable(proga main.cpp CPoint.cpp CPoint.h CPolyline.cpp CPolyline.h CClosed_polyline.cpp CClosed_polyline.h CPolygon.cpp CPolygon.h CTriangle.cpp CTriangle.h CTrapezoid.cpp CTrapezoid.h CRegular_polygon.cpp CRegular_polygon.h)
