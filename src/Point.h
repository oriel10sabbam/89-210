/*
* names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Point.h
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#ifndef POINT_H_
#define POINT_H_

/*
 * this class represent a point (x,y)
 */
class Point {
public:

  /*
   * default constructor of Point
   */
  Point();
  /*
   *  Operator Overloading to <
   *  @ param p- the other point
   */
  bool operator <(const Point& p) const;

  /*
   *  Operator Overloading to >
   *  @ param p- the other point
   */
  bool operator >(const Point& p) const;

  /*
   * constructor of Point
   * @ param x1- the x value
   * @ param y1- the y value
   */
  Point(int x1, int y1);

  /*
   * Destructor of Point
   */
  ~Point();

  /*
   * getX - return the x value
   * @ return- the x value
   */
  int getX() const;

  /*
   * getY - return the y value
   * @ return- the y value
   */
  int getY() const;

  /*
   * setPoint- set new values to the Point
   * @ param x1- the x value
   * @ param y1- the y value
   */
  void setPoint(int x1, int y1);

  /*
   * setX - set a new X value
   * @ param- x1- the x value
   */
  void setX(int x1);

  /*
   * setY - set a new Y value
   * @ param- y1- the y value
   */
  void setY(int y1);

private:
  int x;
  int y;
};

#endif /* POINT_H_ */
