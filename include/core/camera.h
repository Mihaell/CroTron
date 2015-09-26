#ifndef CROTRON_CORE_CAMERA_H_
#define CROTRON_CORE_CAMERA_H_

#include <vector>

#include <SFML/Graphics.hpp>

class Camera {
 public:
  enum ViewType {
    RELATIVE_VIEW,
    ABSOLUTE_VIEW
  };

  Camera();
  ~Camera();

  void PushView(const sf::View& view, ViewType = RELATIVE_VIEW);

  void PopView();

  void Apply() const;

  sf::View GetView() const;

 private:
  sf::View MergeViews(const sf::View& lhs, const sf::View& rhs);

  std::vector<sf::View> views_;
};

#endif  // CROTRON_CORE_CAMERA_H_

