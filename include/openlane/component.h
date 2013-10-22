#ifndef COMPONENT_H
#define COMPONENT_H

#include <ptr.hpp>
#include <cassert>

namespace openlane {

class IComponentProvider;

class IComponent {
  public:
    IComponent(IComponentProvider* cp):icp(cp) {
        assert(icp);
    }
    virtual ~IComponent() {};
  protected:
    IComponentProvider* icp; 
};

typedef smart::ptr<IComponent> IComponentPtr;

} /* openlane */


#endif /* end of include guard: COMPONENT_H */
