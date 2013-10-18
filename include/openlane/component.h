#ifndef COMPONENT_H
#define COMPONENT_H

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

} /* openlane */


#endif /* end of include guard: COMPONENT_H */
