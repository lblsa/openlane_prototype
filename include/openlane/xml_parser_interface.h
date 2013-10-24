#ifndef XML_PARSER_INTERFACE_H
#define XML_PARSER_INTERFACE_H

#include <expat.h>

namespace openlane {

class IXmlParser {
  public:
    IXmlParser();
    virtual ~IXmlParser() {};

    static void StartElementCb(void *userData, const XML_Char *name, const XML_Char **atts);
    static void EndElementCb(void *userData, const XML_Char *name); 

    ErrorCode Create();
    void Free();
    ErrorCode DoParse(const char *s, int len, int isFinal);

    virtual void StartElement(const XML_Char *name, const XML_Char **atts) = 0;
    virtual void EndElement(const XML_Char *name) = 0;

  private:
    XML_Parser parser;
};
    
} /* openlane */

#endif /* end of include guard: XML_PARSER_INTERFACE_H */
