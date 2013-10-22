#ifndef SAMPLE_COMPONENT_ONE_H
#define SAMPLE_COMPONENT_ONE_H

#include <component1/component.h>

class ComponentOne : public IComponentOne {
  public:
    ComponentOne(openlane::ComponentProvider* cp);
    virtual ~ComponentOne();

    virtual void Run();

    static void* Create(void* ctx, void** obj);
  private:
    openlane::ComponentProvider* cp;
}; 

#endif /* end of include guard: SAMPLE_COMPONENT_ONE_H */
