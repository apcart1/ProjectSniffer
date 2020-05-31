#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>

#include "IFactory.hpp"

class IOCContainer {
public:
    template <typename I, class T>
    void Register() {
        // default constuctable
        const auto lambda = [](IOCContainer* container) -> ComponentPtr {
            return std::make_shared<T>();
        };

        auto factory = std::make_unique<LambdaFactory>(lambda);
        Register<I>(std::move(factory));
    }

    template <typename I>
    void Register(FactoryFn&& fn) {
        auto factory = std::make_unique<LambdaFactory>(std::move(fn));
        Register<I>(std::move(factory));
    }

    template <typename I>
    void Register(FactoryPtr&& factory) {
        auto typeName = typeid(I).name();

        factories.emplace(
            std::make_pair(typeName, std::forward<FactoryPtr>(factory)));
    }

    template <typename I>
    std::shared_ptr<I> GetInstance() {
        auto typeName = typeid(I).name();

        auto it = registry.find(typeName);
        if (it == registry.end()) {
            auto component = GetInstance(typeName);
            RegisterInstance(typeName, component);
            return std::dynamic_pointer_cast<I>(component);
        }
        return std::dynamic_pointer_cast<I>(it->second);
    }

protected:
    std::map<std::string, ComponentPtr> registry;
    std::map<std::string, FactoryPtr> factories;

    void RegisterInstance(std::string, ComponentPtr);

    ComponentPtr GetInstance(std::string);
};
using IOCContainerPtr = std::shared_ptr<IOCContainer>;