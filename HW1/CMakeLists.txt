cmake_minimum_required(VERSION 3.0)
project(HW1)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW1 main.cpp library1.cpp EmployeeManager.cpp EmployeeManager.h cmake-build-debug/companyData.cpp cmake-build-debug/companyData.h cmake-build-debug/companyData.cpp cmake-build-debug/companyData.h companyData.cpp companyData.h employeeData.cpp employeeData.h salaryKey.h)
