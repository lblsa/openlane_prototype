#include <openlane/openlane.h>
#include <openlane/module_xml_parser.h>
#include <iostream>

#include <gtest/gtest.h>

class ModuleXmlParserTest : public ::testing::Test
{
  public:
    virtual void SetUp() {}
    virtual void TearDown() {};
};

TEST_F(ModuleXmlParserTest, XmlDoesNotExist)
{
    openlane::ModuleXmlParser parser;

    openlane::ErrorCode result = parser.Parse("does_not_exist.xml");
    EXPECT_EQ(openlane::Fail, result);
}

TEST_F(ModuleXmlParserTest, ValidXml)
{
    openlane::ModuleXmlParser parser;

    openlane::ErrorCode result = parser.Parse("valid.xml");
    EXPECT_EQ(openlane::Ok, result);
}
