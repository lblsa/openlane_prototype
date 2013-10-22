#ifndef COMPONENT_H
#define COMPONENT_H

#include <ptr.hpp>
#include <cassert>

namespace openlane {

class ComponentProvider;

class IComponent {
  public:
    enum { ID = -1 };

    IComponent(ComponentProvider* cp):icp(cp) {
        assert(icp);
    }
    virtual ~IComponent() {};
  protected:
    // FIXME: to derived class
    ComponentProvider* icp; 
};

typedef smart::ptr<IComponent> IComponentPtr; // FIXME
typedef void* (*CreateComponentFn)(void* ctx, void** obj);

} /* openlane */


#endif /* end of include guard: COMPONENT_H */
