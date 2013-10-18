#ifndef ALGORITHM_B_H
#define ALGORITHM_B_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class AlgorithmB : public openlane::IComponent {
  public:
    enum { ID = 0x00000021 };

    AlgorithmB(openlane::IComponentProvider* cp);
    virtual ~AlgorithmB();
}; 

#endif /* end of include guard: ALGORITHM_B_H */
