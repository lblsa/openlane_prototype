#include <openlane/openlane.h>
#include <openlane/module.h>

namespace openlane {
    
DynamicLibrary::DynamicLibrary():
    hdl(NULL), 
    error("")
{
}

DynamicLibrary::~DynamicLibrary()
{
    if (IsValid())
        Unload();
}

ErrorCode DynamicLibrary::Load(const std::string& filename) {
    hdl = ::dlopen(filename.c_str(), RTLD_NOW);
    if (hdl == NULL) {
        error.assign(dlerror());
    }
    return hdl ? Ok : Fail;
}

ErrorCode DynamicLibrary::Unload() {
    ::dlclose(hdl);
    hdl = NULL;
    return Ok;
}


std::string DynamicLibrary::GetError() {
    return error;
}

bool DynamicLibrary::IsValid() {
    return !!hdl;
}


} /* openlane */
