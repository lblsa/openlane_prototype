#include <openlane/component_provider.h>
#include <iostream>
#include "algo.h"

AlgorithmA::AlgorithmA(openlane::ComponentProvider* cp) : openlane::IComponent(cp)
{
    std::cout << "AlgorithmA::AlgorithmA" << std::endl;
}

AlgorithmA::~AlgorithmA()
{
    std::cout << "AlgorithmA::~AlgorithmA" << std::endl;
}

void AlgorithmA::DoAlgoA() {
    std::cout << "AlgorithmA::DoAlgoA" << std::endl;
}

void* AlgorithmA::Create(void* ctx, void** obj)
{
    std::cout << "AlgorithmA::Create" << std::endl;

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    *obj = new AlgorithmA(cp);
    return *obj;
}
