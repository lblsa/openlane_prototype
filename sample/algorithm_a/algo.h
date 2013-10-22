#ifndef ALGORITHM_A_H
#define ALGORITHM_A_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class AlgorithmA : public openlane::IComponent {
  public:
    enum { ID = 0x00000011 };

    AlgorithmA(openlane::ComponentProvider* cp);
    virtual ~AlgorithmA();

    virtual void DoAlgoA();

    static void* Create(void* ctx, void** obj);
}; 

typedef smart::ptr<AlgorithmA> AlgorithmAPtr;

#endif /* end of include guard: ALGORITHM_A_H */
