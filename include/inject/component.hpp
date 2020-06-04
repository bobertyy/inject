#pragma once

#include <memory>

namespace inject {

class Component {
 public:
  using SharedPtr = std::shared_ptr<Component>;
};

}  // namespace inject