#ifndef SAMPLE_COMPONENT_ONE_H
#define SAMPLE_COMPONENT_ONE_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class ComponentOne : public openlane::IComponent {
  public:
    enum { ID = 0x00000001 };

    ComponentOne(openlane::ComponentProvider* cp);
    virtual ~ComponentOne();

    virtual void Run();

    static void* Create(void* ctx, void** obj);
}; 

typedef smart::ptr<ComponentOne> ComponentOnePtr;

#endif /* end of include guard: SAMPLE_COMPONENT_ONE_H */
