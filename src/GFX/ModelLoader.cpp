#include "Engine/GFX/ModelLoader.h"
#include <ZipArchive.h>
#include <ZipFile.h>
#include <ZipArchiveEntry.h>
#include <Engine/GFX/VertexBufferBuilder.h>

template<typename T>
static std::vector<T> istreamToVector(std::istream &stream, size_t size) {
  std::vector<T> result;
  result.resize(size / sizeof(T));

  stream.read((char *) result.data(), size / sizeof(T));

  return result;
}

Model *ModelLoader::LoadShapes(const ZipArchive::Ptr &zip) {
  ZipArchiveEntry::Ptr indicesFile;
  Model *model = new Model;

  i32 i = 0;
  while ((indicesFile = zip->GetEntry("indices_" + std::to_string(i) + ".bin")) != nullptr) {
    LOG_INFO(indicesFile->GetName());
    auto verticesFile = zip->GetEntry("vertices_" + std::to_string(i) + ".bin");
    if (!verticesFile) LOG_ERROR("Error while trying to load file.", "vertices_", i, ".bin",
                                 "not found but indices was found");

    std::vector vertices = istreamToVector<f32>(*verticesFile->GetDecompressionStream(), verticesFile->GetSize());
    std::vector indices = istreamToVector<u32>(*indicesFile->GetDecompressionStream(), indicesFile->GetSize());

    VertexBufferBuilder builder;
    model->buffers.push_back(
            builder
            .AddVertexDataDirect(vertices)
            .AddIndexDataDirect(indices)
            .AddVertexAttribute(3)
            .Build().release()
            );
    i++;
  }
  return model;
}

Model ModelLoader::LoadFromZip(const string &filepath) {
  ZipArchive::Ptr zip = ZipFile::Open(filepath);

  auto model = LoadShapes(zip);

  return *model;
}