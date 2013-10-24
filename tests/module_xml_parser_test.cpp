#include <openlane/openlane.h>
#include <openlane/module_xml_parser.h>
#include <iostream>

#include <gtest/gtest.h>

class XmlListenerStub : public openlane::IXmlParserEventListener {
    virtual void OnLoadComponent(const char* name){};
    virtual void OnLoadConfig(const char* name){};
};

class ModuleXmlParserTest : public ::testing::Test
{
  public:
    virtual void SetUp() {
        listener = new XmlListenerStub();
    }
    virtual void TearDown() {
        delete listener;
    };
  protected:
    openlane::IXmlParserEventListener* listener;
};

TEST_F(ModuleXmlParserTest, XmlDoesNotExist)
{
    openlane::ModuleXmlParser parser(listener);

    openlane::ErrorCode result = parser.Parse("does_not_exist.xml");
    EXPECT_EQ(openlane::Fail, result);
}

TEST_F(ModuleXmlParserTest, ValidXml)
{
    openlane::ModuleXmlParser parser(listener);

    openlane::ErrorCode result = parser.Parse("component_a.xml");
    EXPECT_EQ(openlane::Ok, result);
}
