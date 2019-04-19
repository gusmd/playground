#include <pybind11/embed.h>

namespace py = pybind11;

int main()
{
    py::scoped_interpreter interpreter{};

    py::print("Hello, World!");
}
