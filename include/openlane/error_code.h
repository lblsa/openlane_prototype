#ifndef ERROR_CODE_H
#define ERROR_CODE_H

namespace openlane {

enum ErrorCode {
    Ok = 0,
    Fail,
    InvalidArgument,
    Unexpected,
    NoMemory,
    NotInitialized
};

} /* openlane */

#endif /* end of include guard: ERROR_CODE_H */
