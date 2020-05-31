#pragma once

#include <memory>

#include <IComponent.hpp>

class IOCContainer;

class IFactory {
public:
    virtual ~IFactory() = default;
    virtual ComponentPtr Build(IOCContainer*) = 0;
};
using FactoryPtr = std::unique_ptr<IFactory>;
using FactoryFn = std::function<ComponentPtr(IOCContainer*)>;

class LambdaFactory : public IFactory {
public:
    explicit LambdaFactory(FactoryFn&& lambda) : lambda{ lambda } {}

    ComponentPtr Build(IOCContainer* container) override {
        return lambda(container);
    }

private:
    FactoryFn lambda;
};