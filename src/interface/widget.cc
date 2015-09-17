#include <SFML/Graphics.hpp>

#include "core/window_manager.h"
#include "interface/widget.h"

Widget::Widget(const sf::Vector2f& pos, const sf::Vector2f& size)
    : pos_(pos),
      size_(size),
      hovered_(false),
      pressed_(false),
      focused_(false),
      parent_(nullptr) {
}

Widget::~Widget() {
}

void Widget::MouseMoved(const sf::Vector2f& pos) {
  const sf::Vector2f abspos = GetAbsPosition();
  if (pos.x >= abspos.x && pos.y >= abspos.y &&
      pos.x <= abspos.x + size_.x && pos.y < abspos.y + size_.y) {
    hovered_ = true;
  } else {
    hovered_ = false;
  }
}

void Widget::Draw() const {
  const sf::Vector2f abspos = GetAbsPosition();

  sf::VertexArray quad(sf::Quads, 4);
  quad[0].position = abspos;
  quad[1].position = abspos + sf::Vector2f(size_.x, 0);
  quad[2].position = abspos + sf::Vector2f(size_.x, size_.y);
  quad[3].position = abspos + sf::Vector2f(0, size_.y);

  quad[0].color = quad[1].color =
  quad[2].color = quad[3].color = sf::Color(255, 255, 255, 70);

  WindowManager::Draw(quad);
}

void Widget::Update() {
}

sf::Vector2f Widget::GetAbsPosition() const {
  if (parent_) return pos_ + parent_->GetAbsPosition();
  return pos_;
}
