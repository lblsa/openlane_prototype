#include <openlane/component_provider.h>
#include "algo.h"

AlgorithmC::AlgorithmC(openlane::IComponentProvider* cp) : openlane::IComponent(cp)
{
    icp->RegisterComponent(ID, this);
}

AlgorithmC::~AlgorithmC()
{
    icp->UnregisterComponent(ID, this);
}
