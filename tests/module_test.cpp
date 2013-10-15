#include <openlane/openlane.h>
#include <openlane/module.h>
#include <iostream>

#include <math.h>

#include <gtest/gtest.h>

class ModuleTest : public ::testing::Test
{
  public:
    virtual void SetUp() {}
    virtual void TearDown() {};

    typedef double (*fp_sin_t)(double x);
    fp_sin_t fp_sin;
};

TEST_F(ModuleTest, ModuleDoesNotExist)
{
    openlane::DynamicLibrary module;
    std::string module_name("libmXXX.so");

    openlane::ErrorCode result = module.Load(module_name);
    EXPECT_EQ(openlane::Fail, result);
}

TEST_F(ModuleTest, ModuleExistSymbolDoesNotExist)
{
    openlane::DynamicLibrary module;
    std::string module_name("libm.so");

    openlane::ErrorCode result = module.Load(module_name);
    ASSERT_EQ(openlane::Ok, result);

    result = module.GetSymbol("sinXXX", ModuleTest::fp_sin);
    EXPECT_EQ(openlane::Fail, result);

    module.Unload();
}

TEST_F(ModuleTest, ValidCase)
{
    openlane::DynamicLibrary module;
    std::string module_name("libm.so");

    openlane::ErrorCode result = module.Load(module_name);
    ASSERT_EQ(openlane::Ok, result);

    result = module.GetSymbol("sin", ModuleTest::fp_sin);
    ASSERT_EQ(openlane::Ok, result);

    EXPECT_EQ(1, fp_sin(M_PI_2));

    module.Unload();
}
