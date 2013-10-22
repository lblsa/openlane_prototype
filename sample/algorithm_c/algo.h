#ifndef ALGORITHM_C_H
#define ALGORITHM_C_H

#include <openlane/component.h>
#include <algorithm/algo.h>
#include <openlane/component_provider.h>

class AlgorithmC : public IAlgorithm {
  public:
    AlgorithmC(openlane::ComponentProvider* _cp);
    virtual ~AlgorithmC();

    virtual void DoAlgo();

    static void* Create(void* ctx, void** obj);
  private:
    openlane::ComponentProvider* cp;
}; 

#endif /* end of include guard: ALGORITHM_C_H */
