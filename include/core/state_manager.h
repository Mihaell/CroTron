#ifndef CROTRON_CORE_STATE_MANAGER_H_
#define CROTRON_CORE_STATE_MANAGER_H_

#include <memory>
#include <vector>

#include "states/state_interface.h"

class StateManager {
 public:
  static void DrawStack();
  static void UpdateStack();
  static StateInterface* PushStateToStack(std::unique_ptr<StateInterface> state);
  static void PopStateFromStack();
  static void ClearStateStack();
  static void StartState(std::string state_name);
  static void RemoveStateFromStack(std::string state_name);

 private:
  static std::vector<std::unique_ptr<StateInterface>> states_stack_;

};

#endif  // CROTRON_CORE_STATE_MANAGER_H_
