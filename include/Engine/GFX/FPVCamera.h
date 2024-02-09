#pragma once
#include "Camera.h"

class FPVCamera : public Camera {
public:
  void OnUpdate() override;
};
