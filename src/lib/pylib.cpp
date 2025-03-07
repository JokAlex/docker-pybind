#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>


#include "answer.hpp"
#include "printmap.hpp"
#include "base.hpp"
#include "derived.hpp"
#include "doublelistoperator.hpp"


PYBIND11_MODULE(bindlib, m) 
{
    m.doc() = "pybind11 plugin";

    m.def("answer", &answer, "Answer to the Ultimate Question of Life, the Universe, and Everything");

    m.def("printMap", &printMap, "Prints dict to stdout");
    
    auto&& base = pybind11::class_<Base>(m, "Base")
        .def(pybind11::init<>())
        .def("greet", &Base::greet, "Just a greeting")
        .def("virtualMethod", &Base::virtualMethod)
        .def_static("staticMethod", &Base::staticMethod);
    
    pybind11::class_<Derived>(m, "Derived", base)
        .def(pybind11::init<>());
    
    pybind11::class_<DoubleListOperator>(m, "DoubleListOperator")
        .def(pybind11::init<>())
        .def(pybind11::init<const std::vector<double>&>())
        .def("map", &DoubleListOperator::map)
        .def("reduce", &DoubleListOperator::reduce)
        .def("__iter__", 
            [](DoubleListOperator& cont)
            {
                return pybind11::make_iterator(cont.begin(), cont.end());
            },
            pybind11::keep_alive<0, 1>());
}