#pragma once

#include <exception>
#include <string>
#include <typeindex>

namespace inject {

class DuplicateRegistration : public std::exception {
 public:
  DuplicateRegistration(std::type_index duplicateType) : duplicateType(duplicateType) {}

  const char* what() const noexcept override {
    std::string details = "type: [" + std::string{duplicateType.name()} + "] is already registered";
    return details.c_str();
  }

 private:
  const std::type_index duplicateType;
};

}  // namespace inject