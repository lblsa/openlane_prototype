#ifndef ALGORITHM_A_H
#define ALGORITHM_A_H

#include <openlane/component.h>
#include <algorithm/algo.h>

class AlgorithmA : public IAlgorithm {
  public:
    AlgorithmA();
    virtual ~AlgorithmA();

    virtual void DoAlgo();

    static void* Create(void* ctx, void** obj);
}; 

#endif /* end of include guard: ALGORITHM_A_H */
