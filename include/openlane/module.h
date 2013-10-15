#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <dlfcn.h>

namespace openlane {

class DynamicLibrary {
  public:
    DynamicLibrary();

    ErrorCode Load(const std::string& filename);
    ErrorCode Unload();

    std::string GetError();
    bool IsValid();

    template<typename F>
    ErrorCode GetSymbol(const char* symbol_name, F& out);
  private:
    void*   hdl;
    std::string error;
};

} /* openlane */

#include "impl/module_impl.h"

#endif /* end of include guard: MODULE_H */
