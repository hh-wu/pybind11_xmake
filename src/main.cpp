#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(solver, m) {
    m.doc() = "pybind11 solver plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
}