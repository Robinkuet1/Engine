#pragma once

#include "Engine/Core/Defines.h"
#include "Engine/GFX/Camera.h"

// forward declarations
class GLFWwindow;

/**
 * This is the Main Window Singleton. This means only one of This
 * Class can exist. It can be accessed globally with the Window::Get()
 * Method. The window will be automatically created when first accessed.
 */
class Window {
  friend class Input;

public:
  //delete copy constructor
  Window(Window const&) = delete;

  void operator=(Window const&) = delete;

  /**
   * \brief BeginFrame should be called at begin of frame
   * Prepears everything for render.
   */
  void BeginFrame();

  /**
   * \brief Shows rendered scean to screen
   */
  void EndFrame();

  /**
   * \brief Get Window singleton. Globally accessable
   * \return Window Singleton
   */
  static Window& Get();

  /**
   * \brief Should the window close
   * \return True if Close button clicked
   */
  bool ShouldClose();

  /**
   * \brief Clear the screen
   */
  void Clear();

  /**
   * \brief Close the screen
   */
  void Close() const;

  /**
   * \brief Gets the openGL Version as std::pair
   */
  std::pair<i32, i32> GetGLVersion();

  /**
   * \brief Get the time between frames
   * \return Time between frames
   */
  [[nodiscard]] f64 GetDeltaTime() const;

  /**
   * \brief Set another camera
   * \param camera Subclass of Camera superclass
   */
  void SetCamera(Camera* camera);

  [[nodiscard]] Camera* GetCamera() const;

private:
  Window(); // private constructor to not allow instantiations outside of this
  // singleton
  ~Window();

  std::pair<i32, i32> m_glVersion = std::make_pair(4, 6);

  f64 m_lastTime = 0, m_deltaTime = 0;
  i32 m_width = 0, m_height = 0;

  GLFWwindow* m_pWindow = nullptr;

  Camera* m_pCamera = nullptr;
};
