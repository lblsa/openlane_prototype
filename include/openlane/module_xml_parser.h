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
  private:
    void ParseRoot(const XML_Char *name, const XML_Char **atts);
    void ParseComponent(const XML_Char *name, const XML_Char **atts);
    void ParseSettings(const XML_Char *name, const XML_Char **atts);
    void ParseInterface(const XML_Char *name, const XML_Char **atts);
    void ParseDepend(const XML_Char *name, const XML_Char **atts);

    enum Element { ROOT = 0, COMPONENT, SETTINGS };
    Element parsed_element;
};
    
} /* openlane */


#endif /* end of include guard: MODULE_CML_PARSER_H */
