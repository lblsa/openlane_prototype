#ifndef IFACE_ALGORITHM_C_H
#define IFACE_ALGORITHM_C_H

#include <openlane/openlane.h>

class IAlgorithmC {
  public:
    enum { ID = 0x00000021 };

    virtual ~IAlgorithmC() {};

    virtual void DoAlgo() = 0;
}; 

typedef smart::ptr<IAlgorithmC> AlgorithmCPtr;

#endif /* end of include guard: IFACE_ALGORITHM_C_H */
