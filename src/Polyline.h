#ifndef POLYLINE_H
#define POLYLINE_H

#include "BaseShape.h"
#include "ArrayList.h"
#include "Point.h"

class Polyline final : public BaseShape {
public:
  ArrayList<Point> point_list;

  Polyline(Attribute *attrs, int attrs_count, BaseShape *parent);
  void draw() const override;
};

#endif
