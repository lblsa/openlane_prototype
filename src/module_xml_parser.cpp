#include <openlane/openlane.h>
#include <openlane/module_xml_parser.h>

#include <fstream>
#include <iostream>

namespace openlane {

#define BUF_SIZE 100
    
ModuleXmlParser::ModuleXmlParser() {
}

ModuleXmlParser::~ModuleXmlParser() {
}

ErrorCode ModuleXmlParser::Parse(const char* file_name) {
    if (!file_name)
        return InvalidArgument;

    std::fstream file;
    file.open(file_name, std::fstream::in);
    if (file.fail()) {
        std::cerr << "xml_parser\tFailed to open file " << file_name << std::endl;
        return Fail;
    }

    ErrorCode error = Ok;
    while(!file.eof()) {
        char buf[BUF_SIZE] = {0};
        file.read(buf, BUF_SIZE);

        int len = file.gcount() < BUF_SIZE ? file.gcount() : BUF_SIZE;
        ErrorCode result = DoParse(&buf[0], len, len<BUF_SIZE ?1 : 0);
        if (Ok != result) {
            std::cerr << "xml_parser\tParsing failed, result=" << result << std::endl;
            error = Fail;
            break;
        }
    }

    file.close();
    return error;
}

void ModuleXmlParser::StartElement(const XML_Char *name, const XML_Char **atts) {
    // TODO
}

void ModuleXmlParser::EndElement(const XML_Char *name) {
    // TODO
}

} /* openlane */
