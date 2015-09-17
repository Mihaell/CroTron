#ifndef CROTRON_GUI_WIDGET_H_
#define CROTRON_GUI_WIDGET_H_

#include <SFML/Graphics.hpp>

class Widget {
 public:
  Widget(const sf::Vector2f& pos, const sf::Vector2f& size);

  virtual ~Widget();

  virtual void MouseMoved(const sf::Vector2f& pos);

  virtual void Draw() const;

  virtual void Update();

 protected:
  sf::Vector2f GetAbsPosition() const;

  sf::Vector2f pos_;
  sf::Vector2f size_;

  bool hovered_;
  bool pressed_;
  bool focused_;

  Widget* parent_;
};


#endif  // CROTRON_GUI_WIDGET_H_
