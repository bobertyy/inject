#include "inject/exceptions/duplicate_registration.hpp"

namespace inject {

DuplicateRegistration::DuplicateRegistration(std::type_index duplicateType) : duplicateType(duplicateType) {}

const char* DuplicateRegistration::what() const noexcept {
  std::string details = "type: [" + std::string{duplicateType.name()} + "] is already registered";
  return details.c_str();
}

}  // namespace inject