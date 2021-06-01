// failed_testcase.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

namespace TestCase {
class FailedClass {
public:
  int failedRet() const { return 42; }
};
} // namespace TestCase
