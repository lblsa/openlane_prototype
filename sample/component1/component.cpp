#include <openlane/component_provider.h>
#include "component.h"
#include "../algorithm_a/algo.h"

#include <stdio.h>

ComponentOne::ComponentOne(openlane::ComponentProvider* cp) : openlane::IComponent(cp)
{
    std::cout << "ComponentOne::ComponentOne" << std::endl;
}

ComponentOne::~ComponentOne()
{
    std::cout << "ComponentOne::~ComponentOne" << std::endl;
}

void ComponentOne::Run()
{
    std::cout << "ComponentOne::Run" << std::endl;

    AlgorithmAPtr algo_a;
    if (icp->CreateObject(algo_a)) {
        algo_a->DoAlgoA();
    }
}

void* ComponentOne::Create(void* ctx, void** obj)
{
    std::cout << "ComponentOne::Create" << std::endl;

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    *obj = new ComponentOne(cp);
    return *obj;
}
