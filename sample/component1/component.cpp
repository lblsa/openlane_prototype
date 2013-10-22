#include <openlane/component_provider.h>
#include <algorithm/algo.h>
#include "component.h"

ComponentOne::ComponentOne(openlane::ComponentProvider* _cp) : cp(_cp)
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

    AlgorithmPtr algo;
    if (cp->CreateObject(algo)) {
        algo->DoAlgo();
    }
}

void* ComponentOne::Create(void* ctx, void** obj)
{
    std::cout << "ComponentOne::Create" << std::endl;

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    *obj = new ComponentOne(cp);
    return *obj;
}
