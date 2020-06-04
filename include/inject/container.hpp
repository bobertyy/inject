#pragma once

#include <exception>
#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "inject/component.hpp"
#include "inject/exceptions/duplicate_registration.hpp"
#include "inject/exceptions/no_registered_component.hpp"

namespace inject {

class Container {
  using ProviderFunc = std::function<const Component&(const Container&)>;
  using ProviderMap = std::unordered_map<std::type_index, ProviderFunc>;

 public:
  template <class T, class TImpl = T>
  void RegisterComponent() {
    if (providers.find(typeid(T)) != providers.end()) {
      throw DuplicateRegistration{typeid(T)};
    }

    auto provider = [& components = components](const Container& container) -> const TImpl& {
      if (components.find(typeid(T)) == components.end()) {
        components.insert({typeid(T), std::make_shared<TImpl>(container)});
      }

      return static_cast<TImpl&>(*components.at(typeid(T)));
    };

    providers.insert({typeid(T), provider});
  }

  template <class T>
  const T& Resolve() const {
    auto search = providers.find(typeid(T));

    if (search == providers.end()) {
      throw NoRegisteredComponent(typeid(T));
    }

    auto provider = providers.at(typeid(T));
    return static_cast<const T&>(provider(*this));
  }

 private:
  ProviderMap providers;
  std::unordered_map<std::type_index, Component::SharedPtr> components;
};

}  // namespace inject
