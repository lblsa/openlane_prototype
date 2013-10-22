#ifndef IFACE_COMPONENT_ONE_H
#define IFACE_COMPONENT_ONE_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class IComponentOne : public openlane::IComponent {
  public:
    enum { ID = 0x00000001 };

    virtual ~IComponentOne() {};

    virtual void Run() = 0;
}; 

typedef smart::ptr<IComponentOne> ComponentOnePtr;

#endif /* end of include guard: IFACE_COMPONENT_ONE_H */
