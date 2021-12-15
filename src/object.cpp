//
// Created by TF on 12/15/2021.
//
#include <pybind11/pybind11.h>

struct Pet {
    Pet(const std::string &name) : name(name) {}

    void setName(const std::string &name_) { name = name_; }

    const std::string &getName() const { return name; }

    std::string name;
};


namespace py = pybind11;

PYBIND11_MODULE(object, m
) {
    py::class_<Pet>(m,
    "Pet")
    .def (py::init<const std::string &>())
    .def("setName", &Pet::setName)
    .def("getName", &Pet::getName)
    .def("__repr__",
[](const Pet &a) {
return "<example.Pet named '" + a.name + "'>";
}
);
}