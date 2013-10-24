#include <openlane/component_provider.h>
#include <algorithm/algo_c.h>
#include "algo.h"

AlgorithmB::AlgorithmB(openlane::ComponentProvider* _cp) : cp(_cp)
{
    std::cout << "AlgorithmB::AlgorithmB" << std::endl;
}

AlgorithmB::~AlgorithmB()
{
    std::cout << "AlgorithmB::~AlgorithmB" << std::endl;
}

void AlgorithmB::DoAlgo()
{
    std::cout << "AlgorithmB::DoAlgo" << std::endl;

    AlgorithmCPtr algo_c;
    if (cp->CreateObject(algo_c)) {
        algo_c->DoAlgo();
    } else {
        std::cerr << "Failed to create AlgorithmC, no interface" << std::endl;
    }
}

void* AlgorithmB::Create(void* ctx, void** obj)
{
    std::cout << "AlgorithmB::Create" << std::endl;

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    *obj = new AlgorithmB(cp);
    return *obj;
}
