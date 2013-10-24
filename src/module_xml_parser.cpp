#include <openlane/openlane.h>
#include <openlane/module_xml_parser.h>

#include <fstream>
#include <iostream>
#include <cstring>
#include <cassert>

namespace openlane {

#define BUF_SIZE 1024
    
ModuleXmlParser::ModuleXmlParser(IXmlParserEventListener* _listener) :
    parsed_element(ROOT),
    listener(_listener)
{
    assert(listener);
}

ModuleXmlParser::~ModuleXmlParser() {
}

ErrorCode ModuleXmlParser::Parse(const char* file_name) {
    if (!file_name)
        return InvalidArgument;

    if (Create() != Ok) {
        std::cerr << "xml_parser\tFailed to create parser" << std::endl;
        return Fail;
    }

    std::fstream file;
    file.open(file_name, std::fstream::in);
    if (file.fail()) {
        std::cerr << "xml_parser\tFailed to open file " << file_name << std::endl;
        Free();
        return Fail;
    }

    ErrorCode error = Ok;
    while(!file.eof()) {
        char buf[BUF_SIZE] = {0};
        file.read(buf, BUF_SIZE);

        int len = file.gcount() < BUF_SIZE ? file.gcount() : BUF_SIZE;
        error = DoParse(&buf[0], len, len<BUF_SIZE ?1 : 0);
        if (Ok != error)
            break;
    }

    file.close();
    Free();
    parsed_element = ROOT;
    return error;
}

void ModuleXmlParser::StartElement(const XML_Char *name, const XML_Char **atts) {
    // TODO

    switch(parsed_element) {
        case ROOT:
            ParseRoot(name, atts);
            break;

        case COMPONENT:
            ParseComponent(name, atts);
            break;

        case SETTINGS:
            ParseInterface(name, atts);
            break;
    }
}

void ModuleXmlParser::EndElement(const XML_Char *name) {
    // TODO
    
    switch(parsed_element) {
        case ROOT:
            break;
        case COMPONENT:
            if (!strncmp("component", name, strlen("component"))) parsed_element = ROOT;
            break;
        case SETTINGS:
            if (!strncmp("settings", name, strlen("settings"))) parsed_element = COMPONENT;
            break;
    }

}

void ModuleXmlParser::ParseRoot(const XML_Char *name, const XML_Char **atts) {
    // component name
    // TODO
    if (!atts || !atts[0] || !atts[1]) {
        std::cerr << "xml_parser\t" << "Failed to parse 'component' element" << std::endl;
        return;
    }

    if (!strncmp("name", atts[0], strlen("name"))) {
        listener->OnLoadComponent(atts[1]);
        parsed_element = COMPONENT;
    }
}

void ModuleXmlParser::ParseComponent(const XML_Char *name, const XML_Char **atts) {
    if (!strncmp("settings", name, strlen("settings")))
        ParseSettings(name, atts);
    else if (!strncmp("depend", name, strlen("depend")))
        ParseDepend(name, atts);
}

void ModuleXmlParser::ParseSettings(const XML_Char *name, const XML_Char **atts) {
    // TODO

    parsed_element = SETTINGS;
}

void ModuleXmlParser::ParseInterface(const XML_Char *name, const XML_Char **atts) {
    // TODO

    if (!atts || !atts[0] || !atts[1] || !atts[2] || !atts[3]) {
        std::cerr << "xml_parser\t" << "Failed to parse 'interface' element" << std::endl;
        return;
    }

    const char* id = NULL;
    const char* service = NULL;
    if (!strncmp("id", atts[0], strlen("id"))) {
        id = atts[1];
        service = atts[3];
    } else {
        id = atts[3];
        service = atts[1];
    }
}

void ModuleXmlParser::ParseDepend(const XML_Char *name, const XML_Char **atts) {
    // TODO

    if (!atts || !atts[0] || !atts[1]) {
        std::cerr << "xml_parser\t" << "Failed to parse 'depend' element" << std::endl;
        return;
    }

    const char* component = NULL;
    if (!strncmp("component", atts[0], strlen("component"))) {
        component = atts[1];

        listener->OnLoadConfig(component);
    }
}

} /* openlane */
