#pragma once

#include "Engine/Core/Defines.h"

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
  Window(Window const &) = delete;
  void operator=(Window const &) = delete;

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
  static Window &Get();

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
  void Close();

  /**
   * \brief Get the time between frames
   * \return Time between frames
   */
  f64 GetDeltaTime();

private:
  Window(); // private constructor to not allow instantiations outside of this
            // singleton
  ~Window();

  f64 m_lastTime, m_deltaTime = 0;
  i32 m_width, m_height = 0;

  GLFWwindow *m_pWindow = nullptr;
};
