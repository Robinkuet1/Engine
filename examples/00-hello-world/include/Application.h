#pragma once

#include <Engine/Core/Defines.h>
#include <Engine/Core/ApplicationBase.h>

class Application : public ApplicationBase {
private:
    void OnInitialize() override;

    void OnUpdate(f64 delta) override;

    void OnRender() override;

    void OnShutdown() override;
};
