/*
 * name :   oriel sabban
 * id   :   201052602
 * Point.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#include "Point.h"

Point::Point() {
  x = -1;
  y = -1;
}
Point::Point(int x1, int y1) {
  x = x1;
  y = y1;
}

Point::~Point() {
}

bool Point::operator <(const Point& p) const {
  if (getX() < p.getX()) {
    return true;
  } else {
    return false;
  }
}

bool Point::operator >(const Point& p) const {
  if (getX() > p.getX()) {
    return true;
  } else {
    return false;
  }
}

int Point::getX() const {
  return x;
}

int Point::getY() const {
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
