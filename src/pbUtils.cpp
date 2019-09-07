#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;

void bytes_to_vector(py::bytes& b, std::vector<char>& vec){
    // The buffer is the internal storage of the bytes. Do not modify
    char* buffer;
    ssize_t length;
    if (PYBIND11_BYTES_AS_STRING_AND_SIZE(b.ptr(), &buffer, &length))
        py::pybind11_fail("Unable to extract bytes contents!");
    vec.assign(buffer, buffer + (size_t)length * sizeof(char));
}

py::str ascii_to_unicode_safe(const std::string &s){
  // "replace": replaces characters with unicode question mark
  py::str str_out(PyUnicode_DecodeASCII(s.data(), s.length(), "replace"));
  return str_out;
}