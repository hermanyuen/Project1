# CppUnitLite
Used in UW P&CE Certificate Program in C++.

Contains the CppUnitLite framework, which is a simple, cross-platform unit-testing framework, and an example project that uses it.

Supports C++20.

The header files for CppUnitLite are in the include\CppUnitLite directory.  In your project file or makefile, you will need to tell your compiler to seach this directory for headers

Microsoft Visual Studio: add this include directory to the "AdditionalIncludeDirectories"
makefile: add via the INC=-Iinclude/CppUnitLite flag
