#ifndef CROTRON_INTERFACE_STATE_INTERFACE_H
#define CROTRON_INTERFACE_STATE_INTERFACE_H

#include <string>

class StateInterface {
 public:

  virtual ~StateInterface() {}

  virtual void Draw() = 0;
  virtual void Update() = 0;

  std::string state_name_;

};

#endif  // CROTRON_INTERFACE_STATE_INTERFACE_H
