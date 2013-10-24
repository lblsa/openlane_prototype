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
    ResetParser();
    parsed_element = ROOT;
    return error;
}

#include <stdio.h>

void ModuleXmlParser::StartElement(const XML_Char *name, const XML_Char **atts) {
    // FIXME

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
    // FIXME
    
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
    std::cout << "xml_parser\t" << "Parse 'component': " << name << std::endl;

    listener->OnLoadComponent(atts[1]);
    parsed_element = COMPONENT;
}

void ModuleXmlParser::ParseComponent(const XML_Char *name, const XML_Char **atts) {
    if (!strncmp("settings", name, strlen("settings")))
        ParseSettings(name, atts);
    else if (!strncmp("depend", name, strlen("depend")))
        ParseDepend(name, atts);
}

void ModuleXmlParser::ParseSettings(const XML_Char *name, const XML_Char **atts) {
    std::cout << "xml_parser\t" << "Parse 'settings': " << name << std::endl;

    parsed_element = SETTINGS;
}

void ModuleXmlParser::ParseInterface(const XML_Char *name, const XML_Char **atts) {
    std::cout << "xml_parser\t" << "Parse 'interface': " << name << std::endl;

    if (!atts || !atts[0] || !atts[1] || !atts[2] || !atts[3]) {
        std::cerr << "xml_parser\t" << "Failed to parse 'settings' element" << std::endl;
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

    std::cout << "xml_parser\t" << "\tiface id: " << id << ", service: " << service << std::endl;
}

void ModuleXmlParser::ParseDepend(const XML_Char *name, const XML_Char **atts) {
    std::cout << "xml_parser\t" << "Parse 'depend': " << name << std::endl;

    if (!atts || !atts[0] || !atts[1]) {
        std::cerr << "xml_parser\t" << "Failed to parse 'settings' element" << std::endl;
        return;
    }

    const char* component = NULL;
    if (!strncmp("component", atts[0], strlen("component"))) {
        component = atts[1];

        listener->OnLoadConfig(component);
    }

    std::cout << "xml_parser\t" << "\tcomponent: " << component << std::endl;

}

} /* openlane */
