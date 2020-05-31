#include <exception>
#include <stdexcept>
#include <IOCContainer.hpp>
#include <IComponent.hpp>

void IOCContainer::RegisterInstance(std::string typeName,
    ComponentPtr component) {
    registry.emplace(typeName, component);
}

ComponentPtr IOCContainer::GetInstance(std::string typeName) {
    auto it = factories.find(typeName);
    if (it == factories.end()) {
        throw std::runtime_error("Something went wrong!!!");
    }
    return it->second->Build(this);
}