#include <openlane/component_provider.h>
#include "main.h"
#include "algo.h"

uint32_t DLL_PUBLIC LoadComponent(void *ctx) {
    assert(ctx);

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    return cp->RegisterComponent(AlgorithmC::ID, &AlgorithmC::Create);
}

uint32_t DLL_PUBLIC UnloadComponent(void *ctx) {
    assert(ctx);

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    return cp->UnregisterComponent(AlgorithmC::ID);
}
