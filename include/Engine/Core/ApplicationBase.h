#include "Window.h"

/**
 * This is the Main Application Class that should be
 * inherited by every Application using this Engine.
 * The Window is initialized and handled by this Class.
 * For the MainLoop only the Methods of this class should
 * be used.
 * Initialisations should be done in OnInitialize instead of
 * the constructor.
 */
class ApplicationBase {
public:
  ApplicationBase();
  virtual ~ApplicationBase() = default;

  /**
   * \brief Called to start the Application
   */
  void Run();

protected:
  /**
   * \brief Will be called On Game Initialisation
   */
  virtual void OnInitialize() = 0;

  /**
   * \brief Called every frame once before Render()
   * \param delta Time between last frames
   */
  virtual void OnUpdate(f64 delta) = 0;

  /**
   * \brief Called every frame once after Update()
   */
  virtual void OnRender() = 0;

  /**
   * \brief Called om shutdown of Game
   */
  virtual void OnShutdown() = 0;
};
