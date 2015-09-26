#include "core/camera.h"

#include <vector>

#include <SFML/Graphics.hpp>

#include "core/window_manager.h"

Camera::Camera() {
  views_.push_back(WindowManager::GetDefaultView());
}

Camera::~Camera() {
}

void Camera::PushView(const sf::View& view, ViewType type) {
  switch (type) {
    case ABSOLUTE_VIEW: {
      views_.push_back(view);
      break;
    }
    case RELATIVE_VIEW: {
      views_.push_back(MergeViews(views_.back(), view));
      break;
    }
    default:
      break;
  }
}

void Camera::PopView() {
  if (views_.size() > 1)
    views_.pop_back();
}

void Camera::Apply() const {
  WindowManager::SetView(views_.back());
}

sf::View Camera::GetView() const {
  return views_.back();
}

sf::View Camera::MergeViews(const sf::View& lhs, const sf::View& rhs) {
  sf::FloatRect lvport = lhs.getViewport();
  sf::FloatRect rvport = rhs.getViewport();

  printf("%f %f %f %f\n", lvport.left, lvport.top, lvport.width, lvport.height);
  printf("%f %f %f %f\n", rvport.left, rvport.top, rvport.width, rvport.height);
  rvport.width  *= lvport.width;
  rvport.height *= lvport.height;
  rvport.left = lvport.left + rvport.left * lvport.width;
  rvport.top  = lvport.top  + rvport.top  * lvport.height;

  printf("%f %f %f %f\n", rvport.left, rvport.top, rvport.width, rvport.height);
  sf::View ret = rhs;
  ret.setViewport(rvport);
  return ret;
}
