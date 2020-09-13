#pragma once

#include <exception>
#include <string>
#include <typeindex>

namespace inject {

class DuplicateRegistration : public std::exception {
 public:
  DuplicateRegistration(std::type_index duplicateType);

  const char* what() const noexcept override;

 private:
  const std::type_index duplicateType;
};

}  // namespace inject