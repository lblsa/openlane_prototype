#include <openlane/openlane.h>
#include <openlane/xml_parser_interface.h>

namespace openlane {

IXmlParser::IXmlParser() {
    parser = XML_ParserCreate(NULL);
    if (parser) {
        XML_SetUserData(parser, this);
        XML_SetElementHandler(parser, IXmlParser::StartElementCb, IXmlParser::EndElementCb);
    }
}
    
IXmlParser::~IXmlParser() {
    if (parser) {
        XML_ParserFree(parser);
    }
}

void IXmlParser::StartElementCb(void *user_data, const XML_Char *name, const XML_Char **atts) {
    IXmlParser* This = static_cast<IXmlParser*>(user_data);
    if (This) This->StartElement(name, atts);
}

void IXmlParser::EndElementCb(void *user_data, const XML_Char *name) {
    IXmlParser* This = static_cast<IXmlParser*>(user_data);
    if (This) This->EndElement(name);
}

ErrorCode IXmlParser::DoParse(const char *s, int len, int isFinal) {
    ErrorCode error = Fail;
    if (parser) {
        error = XML_Parse(parser, s, len, isFinal) == XML_STATUS_ERROR ? Fail : Ok;
        std::cout << "ERROR: " << XML_GetErrorCode(parser) << std::endl;
    }

    return error;
}

void IXmlParser::ResetParser() {
    XML_ParserReset(parser, 0);
}

} /* openlane */
