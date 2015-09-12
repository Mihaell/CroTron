#include "core/app.h"

#include <memory>

int main(int argc, const char* argv[]) {

  std::unique_ptr<App> app(new App);

  app->Run();

  return 0;
}
