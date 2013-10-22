#include <openlane/component_provider.h>
#include "algo.h"

AlgorithmB::AlgorithmB(openlane::ComponentProvider* cp) : openlane::IComponent(cp)
{
    std::cout << "AlgorithmB::AlgorithmB" << std::endl;
}

AlgorithmB::~AlgorithmB()
{
    std::cout << "AlgorithmB::~AlgorithmB" << std::endl;
}

void* AlgorithmB::Create(void* ctx, void** obj)
{
    std::cout << "AlgorithmB::Create" << std::endl;

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    *obj = new AlgorithmB(cp);
    return *obj;
}
