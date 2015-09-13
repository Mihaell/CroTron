#ifndef CROTRON_CORE_STATE_MANAGER_H_
#define CROTRON_CORE_STATE_MANAGER_H_

#include "interface/state_interface.h"

class StateManager {
 public:

  static void PushStateToStack(StateInterface *state);
  static void PopStateFromStack();
  static void ClearStateStack();
  static void StartState(std::string state_name);
  static void PauseState(std::string state_name);
  static void StopState(std::string state_name);
  static void RemoveStateFromStack(std::string state_name);

};

#endif  // CROTRON_CORE_STATE_MANAGER_H_
