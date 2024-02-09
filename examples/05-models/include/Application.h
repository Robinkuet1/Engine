#pragma once

#include <memory>
#include <Engine/Core/Defines.h>
#include <Engine/Core/ApplicationBase.h>

#include "Engine/GFX/Shader.h"
#include "Engine/GFX/VertexBuffer.h"
#include "Engine/GFX/Model.h"

class Application : public ApplicationBase {
    void OnInitialize() override;

    void OnUpdate(f64 delta) override;

    void OnRender() override;

    void OnShutdown() override;

    std::unique_ptr<VertexBuffer> buffer;
    std::unique_ptr<Shader> shader;
    Model model;
};
