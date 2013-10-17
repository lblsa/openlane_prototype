#include <openlane/openlane.h>
#include <openlane/component_provider.h>
#include <iostream>

#include <gtest/gtest.h>

class ComponentProviderTest : public ::testing::Test
{
  public:
    virtual void SetUp() {}
    virtual void TearDown() {};

    typedef double (*fp_sin_t)(double x);
    fp_sin_t fp_sin;
};

TEST_F(ComponentProviderTest, ModuleDoesNotExist)
{
    openlane::ComponentProvider provider;
    openlane::ErrorCode result = provider.LoadComponent("component1.xml");
    EXPECT_EQ(openlane::Ok, result);
}
