#ifndef LINE_H
#define LINE_H

#include "BaseShape.h"


class Line final : public BaseShape {
public:
  double x1;
  double y1;
  double x2;
  double y2;

  Line(Attribute *attrs, int attrs_count, BaseShape *parent);
  void draw() const override;
};

#endif
