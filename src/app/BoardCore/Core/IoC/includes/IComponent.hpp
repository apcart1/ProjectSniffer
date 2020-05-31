#pragma once

#include <memory>

class IComponent {
 public:
  virtual ~IComponent() = default;
};

using ComponentPtr = std::shared_ptr<IComponent>;