#ifndef POLYLINE_H
#define POLYLINE_H

#include "BaseShape.h"
#include "ArrayList.h"
#include "Matrix.h"

namespace SVGShapes {

class Polyline final : public BaseShape {
public:
  Polyline(Attribute *attrs, int attrs_count, BaseShape *parent);

  ArrayList<BezierCurve> get_beziers() const override;
private:
  ArrayList<Point> point_list;
};

};

#endif
