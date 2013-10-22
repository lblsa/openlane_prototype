#ifndef IFACE_ALGORITHM_H
#define IFACE_ALGORITHM_H

#include <openlane/openlane.h>

class IAlgorithm {
  public:
    enum { ID = 0x00000011 };

    virtual ~IAlgorithm() {};

    virtual void DoAlgo() = 0;
}; 

typedef smart::ptr<IAlgorithm> AlgorithmPtr;

#endif /* end of include guard: IFACE_ALGORITHM_H */
