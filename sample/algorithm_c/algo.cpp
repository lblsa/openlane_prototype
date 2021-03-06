#include <openlane/component_provider.h>
#include "algo.h"

AlgorithmC::AlgorithmC(openlane::ComponentProvider* _cp) : cp(_cp)
{
    std::cout << "AlgorithmC::AlgorithmC" << std::endl;
}

AlgorithmC::~AlgorithmC()
{
    std::cout << "AlgorithmC::~AlgorithmC" << std::endl;
}

void AlgorithmC::DoAlgo()
{
    std::cout << "AlgorithmC::DoAlgo" << std::endl;
}

void* AlgorithmC::Create(void* ctx, void** obj)
{
    std::cout << "AlgorithmC::Create" << std::endl;
    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    *obj = new AlgorithmC(cp);
    return *obj;
}
