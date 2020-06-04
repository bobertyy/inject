#include <gtest/gtest.h>

#include "fixtures/trivial_component.hpp"
#include "inject/container.hpp"
#include "inject/exceptions/duplicate_registration.hpp"
#include "inject/exceptions/no_registered_component.hpp"

namespace inject::testing {
using namespace ::inject::fixtures;

TEST(Container, RegisterComponent_can_be_resolver) {
  Container container;
  container.RegisterComponent<TrivialComponent, TrivialComponentImpl>();

  auto& component = container.Resolve<TrivialComponent>();

  EXPECT_EQ(component.MyFunctionality(), "Implementation here!");
}

TEST(Container, RegisterComponent_can_resolve_tree) {
  Container container;
  container.RegisterComponent<TrivialComposedComponent>();
  container.RegisterComponent<TrivialComponent, TrivialComponentImpl>();

  auto& component = container.Resolve<TrivialComposedComponent>();

  EXPECT_EQ(component.ComposedFunctionality(), "Composed Functionality!");
  EXPECT_EQ(component.component.MyFunctionality(), "Implementation here!");
}

TEST(Container, RegisterComponent_throws_when_attempting_reregister) {
  Container container;
  container.RegisterComponent<TrivialComponentImpl>();

  ASSERT_THROW(container.RegisterComponent<TrivialComponentImpl>(), DuplicateRegistration);
}

TEST(Container, Resolve_throws_when_component_hasnt_been_registered) {
  Container container;

  ASSERT_THROW(container.Resolve<TrivialComponent>(), NoRegisteredComponent);
}

TEST(Container, Resolve_throws_when_dependency_hasnt_been_registered) {
  Container container;
  container.RegisterComponent<TrivialComposedComponent>();

  ASSERT_THROW(container.Resolve<TrivialComposedComponent>(), NoRegisteredComponent);
}

}  // namespace inject::testing