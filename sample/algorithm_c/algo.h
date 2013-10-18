#ifndef ALGORITHM_C_H
#define ALGORITHM_C_H

#include <openlane/component.h>
#include <openlane/component_provider.h>

class AlgorithmC : public openlane::IComponent {
  public:
    enum { ID = 0x00000021 };

    AlgorithmC(openlane::IComponentProvider* cp);
    virtual ~AlgorithmC();
}; 

#endif /* end of include guard: ALGORITHM_C_H */
