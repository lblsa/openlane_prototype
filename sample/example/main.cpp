#include <openlane/openlane.h>
#include <openlane/component_provider.h>

#include "../component1/component.h"

int main(int argc, const char *argv[])
{
    openlane::ComponentProvider provider;
    int a = atoi(argv[1]);

    openlane::ErrorCode res;
    if (a == 1) {
        res = provider.LoadComponent("./libalgorithm_a.so");
        if (openlane::Ok != res ) {
            std::cerr << "LoadComponent libalgorithm_a.so failed, err=" << res << std::endl;
            return 1;
        }
    } else if (a == 2) {
        res = provider.LoadComponent("./libalgorithm_b.so");
        if (openlane::Ok != res ) {
            std::cerr << "LoadComponent libalgorithm_b.so failed, err=" << res << std::endl;
            return 1;
        }
    } else {
        res = provider.LoadComponent("./libalgorithm_c.so");
        if (openlane::Ok != res ) {
            std::cerr << "LoadComponent libalgorithm_c.so failed, err=" << res << std::endl;
            return 1;
        }
    }

    res = provider.LoadComponent("./libcomponent1.so");
    if (openlane::Ok != res ) {
        std::cerr << "LoadComponent libcomponent1.so failed, err=" << res << std::endl;
        return 1;
    }


    ComponentOnePtr c;

    try
    {
        std::cout << "Create Component1" << std::endl;
        if (provider.CreateObject(c)) {
            c->Run();
        }
    }
    catch(const std::bad_alloc&)
    {
        std::cerr << "Failed to create Component1, no memory" << std::endl;
    }

    
    return 0;
}
