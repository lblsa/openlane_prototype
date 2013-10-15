#include <openlane/openlane.h>
#include <openlane/module.h>

namespace openlane {

DynamicLibrary::DynamicLibrary():
    hdl(NULL), 
    error("")
{
}

ErrorCode DynamicLibrary::Load(const std::string& filename) {
    hdl = ::dlopen(filename.c_str(), RTLD_NOW);
    if (hdl == NULL) {
        error.assign(dlerror());
    }
    return hdl ? Ok : Fail;
}

ErrorCode DynamicLibrary::Unload() {
    return ::dlclose(hdl) == 0 ? Ok : Fail;
}

template<typename F>
ErrorCode DynamicLibrary::GetSymbol(const char* symbol_name, F& out) {
    void* pointer = ::dlsym(hdl, symbol_name);
    if (pointer)
        out = reinterpret_cast<F>(pointer);

    return pointer ? Ok : Fail;
}

std::string DynamicLibrary::GetError() {
    return error;
}

bool DynamicLibrary::IsValid() {
    return hdl ? Ok : Fail;
}

} /* openlane */
