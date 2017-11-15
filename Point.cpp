/*
 * name :   oriel sabban
 * id   :   201052602
 * Point.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#include "Point.h"

Point::Point(int x1, int y1) {
  x = x1;
  y = y1;
}

Point::~Point() {
}

int Point::getX() {
  return x;
}

int Point::getY() {
  return y;
}

void Point::setPoint(int x1, int y1) {
  x = x1;
  y = y1;
}

void Point::setX(int x1) {
  x = x1;
}

void Point::setY(int y1) {
  y = y1;
}
