#include <openlane/component_provider.h>
#include "algo.h"

AlgorithmA::AlgorithmA(openlane::IComponentProvider* cp) : openlane::IComponent(cp)
{
    icp->RegisterComponent(ID, this);
}

AlgorithmA::~AlgorithmA()
{
    icp->UnregisterComponent(ID, this);
}
