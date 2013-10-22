#ifndef ALGORITHM_C_H
#define ALGORITHM_C_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class AlgorithmC : public openlane::IComponent {
  public:
    enum { ID = 0x00000031 };

    AlgorithmC(openlane::ComponentProvider* cp);
    virtual ~AlgorithmC();

    static void* Create(void* ctx, void** obj);
}; 

typedef smart::ptr<AlgorithmC> AlgorithmCPtr;

#endif /* end of include guard: ALGORITHM_C_H */
