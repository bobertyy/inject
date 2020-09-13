#include "inject/exceptions/no_registered_component.hpp"

namespace inject {

NoRegisteredComponent::NoRegisteredComponent(std::type_index missingType) : missingType(missingType) {}

const char* NoRegisteredComponent::what() const noexcept {
  std::string details = "type: [" + std::string{missingType.name()} + "] is not registered";
  return details.c_str();
}

}  // namespace inject