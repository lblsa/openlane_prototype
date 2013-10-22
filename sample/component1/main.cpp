#include <openlane/openlane.h>
#include <openlane/component_provider.h>
#include <ptr.hpp>

#include "main.h"
#include "component.h"
#include <cassert>

uint32_t DLL_PUBLIC LoadComponent(void *ctx) {
    assert(ctx);

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    return cp->RegisterComponent(ComponentOne::ID, &ComponentOne::Create);
}

uint32_t DLL_PUBLIC UnloadComponent(void *ctx) {
    assert(ctx);

    openlane::ComponentProvider* cp = static_cast<openlane::ComponentProvider*>(ctx);
    return cp->UnregisterComponent(ComponentOne::ID);
}
