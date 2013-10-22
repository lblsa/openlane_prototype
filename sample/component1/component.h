#ifndef COMPONENT_ONE_H
#define COMPONENT_ONE_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class ComponentOne : public openlane::IComponent {
  public:
    enum { ID = 0x00000001 };

    ComponentOne(openlane::IComponentProvider* cp);
    virtual ~ComponentOne();
}; 

#endif /* end of include guard: COMPONENT_ONE_H */
