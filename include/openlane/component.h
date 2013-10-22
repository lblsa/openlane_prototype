#ifndef COMPONENT_H
#define COMPONENT_H

#include <ptr.hpp>

namespace openlane {

class IComponent {
  public:
    virtual ~IComponent() = 0;
};

typedef smart::ptr<IComponent> IComponentPtr;

} /* openlane */


#endif /* end of include guard: COMPONENT_H */
