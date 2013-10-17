#include <openlane/openlane.h>
#include <openlane/module.h>

namespace openlane {

template<typename F>
ErrorCode DynamicLibrary::GetSymbol(const char* symbol_name, F& out) {
    void* pointer = ::dlsym(hdl, symbol_name);
    if (pointer)
        out = reinterpret_cast<F>(pointer);

    return pointer ? Ok : Fail;
}
} /* openlane */
