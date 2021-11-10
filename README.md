# CPPUtil
A simple C++17 library providing some general utility functionality.

Examples for such provided utilities are:
- Random number generator
- C and C++ string manipulation
- Conversion between primitive datatypes

## Building
The repository contains a Visual Studio 2019 solution (located at Build/VS2019/CPPUtil.sln). There, 2 projects are provided:
| Project      | Purpose                                                |
| ------------ | ------------------------------------------------------ |
| CPPUtil      | CPPUtil itself configured to build as a static library |
| CPPUtil_Test | Used for testing CPPUtil                               |

To build the library, simply build the CPPUtil project. All library files are then placed in a root level directory "Install". While the source code should also be compilable on Linux as well, no build setup is provided for that as of now.

## Examples
Examples can be found under [Examples/](https://github.com/marco-stephan/CPPUtil/tree/master/Sources/Examples).

## License
Licensed under the [MIT License](LICENSE).