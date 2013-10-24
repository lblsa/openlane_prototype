#include <openlane/openlane.h>
#include <openlane/component_provider.h>
#include <iostream>

#include <gtest/gtest.h>

class ComponentProviderTest : public ::testing::Test
{
  public:
    virtual void SetUp() {}
    virtual void TearDown() {};
};

TEST_F(ComponentProviderTest, Valid)
{
    openlane::ComponentProvider provider;
    openlane::ErrorCode result = provider.LoadConfig("component_a.xml");
    EXPECT_EQ(openlane::Ok, result);
}
