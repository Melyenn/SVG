#ifndef GROUP_H
#define GROUP_H

#include "BaseShape.h"

namespace SVGShapes {

class Group final : public BaseShape {
public:
  Group(Attribute *attrs, int attrs_count, BaseShape *parent);
};

};

#endif
