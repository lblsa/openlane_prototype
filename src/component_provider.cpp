#include <openlane/component_provider.h>
#include <iostream>

namespace openlane {

ComponentProvider::ComponentProvider() {
}

ComponentProvider::~ComponentProvider() {
    ComponentConstIterator b = components.begin();
    ComponentConstIterator e = components.end();
    for(;b != e; ++b) {
        (*b)->Unload();
    }
}

ErrorCode ComponentProvider::LoadComponent(const char* filename) {
    if (!filename)
        return InvalidArgument;

    std::cout << "ComponentProvider::LoadComponent\tfilename=" << filename << std::endl;
    return Ok;
}

ErrorCode ComponentProvider::RegisterComponent(uint32_t id, IComponent* c) {
    std::cout << "ComponentProvider::RegisterComponent\tfilename=" << id << std::endl;
    return Ok;
}
ErrorCode ComponentProvider::UnregisterComponent(uint32_t id, IComponent* c) {
    std::cout << "ComponentProvider::UnregisterComponent\tid=" << id << std::endl;
    return Ok;
}
    
} /* openlane */
