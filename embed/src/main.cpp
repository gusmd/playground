#include <pybind11/embed.h>

namespace py = pybind11;
using namespace py::literals;

template <typename T> T operator+(const py::detail::item_accessor &lhs, const T &rhs)
{
    return lhs.cast<T>() + rhs;
}

int main()
{
    // RAII guard for Python interpreter
    py::scoped_interpreter interpreter{};

    // Importing modules
    py::module sys = py::module::import("sys");
    // py::print writes to python's sys.stoud; better for python modules (buffer consistency)
    // note: can also capture and redirect ostream to python's stdout -- see pybind docs
    py::print(sys.attr("path"));

    // _a literal sets args for function call (in this case, dict ctor)
    auto kwargs = py::dict("msg"_a = "This is a test", "count"_a = 0);

    for (auto i = 0; i < 10; ++i) {
        // Incrementing the count -- is there a better way?
        kwargs["count"] = kwargs["count"] + 1;
        //  ** unpacking!!!!!!!!11
        py::print("{msg}; count: {count}"_s.format(**kwargs));
    }
}
