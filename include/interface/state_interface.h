#ifndef CROTRON_INTERFACE_STATE_INTERFACE_H
#define CROTRON_INTERFACE_STATE_INTERFACE_H

class StateInterface {
 public:

  virtual StateInterface() = 0;
  virtual ~StateInterface() = 0;

  virtual void Draw() = 0;
  virtual void Update() = 0;

};

#endif  // CROTRON_INTERFACE_STATE_INTERFACE_H
