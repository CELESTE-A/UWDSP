#include <cassert>
#include "uwasim/uwasim_core.hpp"

int main() {
  assert(!uwasim::banner().empty());
  return 0;
}
