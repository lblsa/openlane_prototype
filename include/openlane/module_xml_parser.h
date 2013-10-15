#ifndef MODULE_CML_PARSER_H
#define MODULE_CML_PARSER_H

#include "xml_parser_interface.h"

namespace openlane {

class ModuleXmlParser : private IXmlParser {
  public:
    ModuleXmlParser();
    virtual ~ModuleXmlParser();

    ErrorCode Parse(const char* file_name);
    virtual void StartElement(const XML_Char *name, const XML_Char **atts);
    virtual void EndElement(const XML_Char *name);
};
    
} /* openlane */


#endif /* end of include guard: MODULE_CML_PARSER_H */
