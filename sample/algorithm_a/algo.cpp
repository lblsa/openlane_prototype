#include <openlane/component_provider.h>
#include <iostream>
#include "algo.h"

AlgorithmA::AlgorithmA()
{
    std::cout << "AlgorithmA::AlgorithmA" << std::endl;
}

AlgorithmA::~AlgorithmA()
{
    std::cout << "AlgorithmA::~AlgorithmA" << std::endl;
}

void AlgorithmA::DoAlgo() {
    std::cout << "AlgorithmA::DoAlgoA" << std::endl;
}

void* AlgorithmA::Create(void* ctx, void** obj)
{
    std::cout << "AlgorithmA::Create" << std::endl;

    *obj = new AlgorithmA();
    return *obj;
}
