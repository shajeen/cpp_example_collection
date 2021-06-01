// failed_testcase.cpp : Defines the entry point for the application.
//

#define CATCH_CONFIG_MAIN

#include "failed_testcase.h"

#include "..\catch.hpp"

TEST_CASE("unvalid function test", "failed")
{
	TestCase::FailedClass obj;
	REQUIRE(obj.failedRet() == 40);
}
