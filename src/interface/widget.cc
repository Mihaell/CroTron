#include <SFML/Graphics.hpp>

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
  // HMM... a trebi mi window da crtam nesto
  // bilo bi zgodno da imam neki static window kojem
  // mogu lagano pristupit
}

void Widget::Update() {
}

sf::Vector2f Widget::GetAbsPosition() const {
  if (parent_) return pos_ + parent_->GetAbsPosition();
  return pos_;
}
