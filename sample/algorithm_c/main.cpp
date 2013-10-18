#include "main.h"
#include "algo.h"

smart::ptr<AlgorithmC> component(NULL);

uint32_t DLL_PUBLIC LoadComponent(void *ctx) {
    assert(ctx);

    try
    {
        if (component)
            return openlane::Unexpected;

        openlane::IComponentProvider* cp = static_cast<openlane::IComponentProvider*>(ctx);
        component = smart::mkptr(new AlgorithmC(cp));
    }
    catch(const std::bad_alloc&)
    {
        return openlane::NoMemory;
    }

    return openlane::Ok;

}

uint32_t DLL_PUBLIC UnloadComponent(void *ctx) {
    assert(ctx);

    if (!component)
        return openlane::NotInitialized;

    component.reset();

    return openlane::Ok;

}
