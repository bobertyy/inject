#pragma once

#include <string>

#include "inject/component.hpp"
#include "inject/container.hpp"

namespace inject::fixtures {

class TrivialComponent : public inject::Component {
 public:
  virtual std::string MyFunctionality() const = 0;
};

class TrivialComponentImpl : public TrivialComponent {
 public:
  explicit TrivialComponentImpl(const Container& container) {}

  std::string MyFunctionality() const override { return "Implementation here!"; }
};

class TrivialComposedComponent : public inject::Component {
 public:
  const TrivialComponent& component;

  explicit TrivialComposedComponent(const Container& container) : component(container.Resolve<TrivialComponent>()) {}

  std::string ComposedFunctionality() const { return "Composed Functionality!"; }
};

}  // namespace inject::fixtures