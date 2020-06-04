#include <IModule.hpp>

class APIModule : public IModule {
public:
    void OnRegister(IOCContainerPtr) override;

    void OnLoad(IOCContainerPtr) override;

    void OnUnload() override;
};