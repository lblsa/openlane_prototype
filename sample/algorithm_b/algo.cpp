#include <openlane/component_provider.h>
#include "algo.h"

AlgorithmB::AlgorithmB(openlane::IComponentProvider* cp) : openlane::IComponent(cp)
{
    icp->RegisterComponent(ID, this);
}

AlgorithmB::~AlgorithmB()
{
    icp->UnregisterComponent(ID, this);
}
