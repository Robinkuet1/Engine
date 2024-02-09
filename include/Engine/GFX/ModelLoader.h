#pragma once

#include "Model.h"
#include "Engine/Core/Defines.h"
#include <ZipArchive.h>

class ModelLoader {
public:
  static Model LoadFromZip(const string& filepath);
private:
  static Model *LoadShapes(const ZipArchive::Ptr &zip);
};