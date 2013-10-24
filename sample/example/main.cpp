#include <openlane/openlane.h>
#include <openlane/component_provider.h>

#include "../component1/component.h"

int main(int argc, const char *argv[])
{
    openlane::ComponentProvider provider;
    if (argc < 2) {
        std::cerr << "Usage:\n" << argv[0] << " [config.xml]" << std::endl;
        return 1;
    }

    openlane::ErrorCode res;
    res = provider.Initialize(argv[1]);
        if (openlane::Ok != res ) {
            std::cerr << "provider.Initialize failed, err=" << res << std::endl;
            return 1;
        }

    try
    {
        ComponentOnePtr c;
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
