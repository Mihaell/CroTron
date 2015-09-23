#include "core/state_manager.h"

std::vector<std::unique_ptr<StateInterface>> StateManager::states_stack_;

void StateManager::DrawStack() {
  for (auto &it: states_stack_) {
    it.get()->Draw();
  }
}

void StateManager::UpdateStack() {
  for (auto &it: states_stack_) {
    it.get()->Update();
  }
}

StateInterface* StateManager::PushStateToStack(std::unique_ptr<StateInterface> state) {
  states_stack_.push_back(move(state));
  return states_stack_.back().get();
}

void StateManager::PopStateFromStack() {
  states_stack_.pop_back();
}

void StateManager::ClearStateStack() {
  states_stack_.clear();
}

void StateManager::StartState(std::string state_name) {
  for (auto &it: states_stack_) {
    if (it.get()->state_name_ == state_name) {
      it.swap(states_stack_.back());
      break;
    }
  }
}

void StateManager::RemoveStateFromStack(std::string state_name) {
  for (int i = 0; i < (int)states_stack_.size(); i++) {
    if (states_stack_[i].get()->state_name_ == state_name) {
      states_stack_.erase(states_stack_.begin() + i);
      break;
    }
  }
}
