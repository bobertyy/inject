#pragma once

#include <exception>
#include <string>
#include <typeindex>

namespace inject {

class NoRegisteredComponent : public std::exception {
 public:
  NoRegisteredComponent(std::type_index missingType) : missingType(missingType) {}

  const char* what() const noexcept override {
    std::string details = "type: [" + std::string{missingType.name()} + "] is not registered";
    return details.c_str();
  }

 private:
  const std::type_index missingType;
};

}  // namespace inject