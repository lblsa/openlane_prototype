#include <openlane/openlane.h>
#include <openlane/xml_parser_interface.h>

namespace openlane {

IXmlParser::IXmlParser() :
    parser(NULL) {
}
    
void IXmlParser::StartElementCb(void *user_data, const XML_Char *name, const XML_Char **atts) {
    IXmlParser* This = static_cast<IXmlParser*>(user_data);
    if (This) This->StartElement(name, atts);
}

void IXmlParser::EndElementCb(void *user_data, const XML_Char *name) {
    IXmlParser* This = static_cast<IXmlParser*>(user_data);
    if (This) This->EndElement(name);
}

ErrorCode IXmlParser::Create() {
    ErrorCode res = Fail;

    parser = XML_ParserCreate(NULL);
    if (parser) {
        XML_SetUserData(parser, this);
        XML_SetElementHandler(parser, IXmlParser::StartElementCb, IXmlParser::EndElementCb);
        res = Ok;
    }

    return res;
}

void IXmlParser::Free() {
    if (parser)
        XML_ParserFree(parser);
}

ErrorCode IXmlParser::DoParse(const char *s, int len, int isFinal) {
    ErrorCode error = NotInitialized;
    if (parser) {
        error = Ok;
        if (XML_Parse(parser, s, len, isFinal) == XML_STATUS_ERROR) {
            error = Fail;
            std::cerr << "xml_parser\tFailed to parse, error=" << XML_ErrorString( XML_GetErrorCode(parser) ) << std::endl;
        }
    }
    return error;
}

} /* openlane */
