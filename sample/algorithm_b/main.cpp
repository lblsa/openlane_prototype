#include "main.h"
#include "algo.h"

uint32_t DLL_PUBLIC LoadComponent(void *ctx) {
    assert(ctx);

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    return cp->RegisterComponent(AlgorithmB::ID, &AlgorithmB::Create);
}

uint32_t DLL_PUBLIC UnloadComponent(void *ctx) {
    assert(ctx);

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    return cp->UnregisterComponent(AlgorithmB::ID);
}
