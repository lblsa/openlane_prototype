#ifndef ALGORITHM_B_H
#define ALGORITHM_B_H

#include <openlane/component.h>
#include <algorithm/algo.h>
#include <openlane/component_provider.h>

class AlgorithmB : public IAlgorithm {
  public:
    AlgorithmB(openlane::ComponentProvider* _cp);
    virtual ~AlgorithmB();

    virtual void DoAlgo();

    static void* Create(void* ctx, void** obj);
  private:
    openlane::ComponentProvider* cp;
}; 

#endif /* end of include guard: ALGORITHM_B_H */
