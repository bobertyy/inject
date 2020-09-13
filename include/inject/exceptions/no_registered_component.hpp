#pragma once

#include <exception>
#include <string>
#include <typeindex>

namespace inject {

class NoRegisteredComponent : public std::exception {
 public:
  NoRegisteredComponent(std::type_index missingType);

  const char* what() const noexcept override;

 private:
  const std::type_index missingType;
};

}  // namespace inject