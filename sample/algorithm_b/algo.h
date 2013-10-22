#ifndef ALGORITHM_B_H
#define ALGORITHM_B_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class AlgorithmB : public openlane::IComponent {
  public:
    enum { ID = 0x00000021 };

    AlgorithmB(openlane::ComponentProvider* cp);
    virtual ~AlgorithmB();

    static void* Create(void* ctx, void** obj);
}; 

typedef smart::ptr<AlgorithmB> AlgorithmBPtr;

#endif /* end of include guard: ALGORITHM_B_H */
