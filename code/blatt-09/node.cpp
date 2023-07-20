#include "node.hpp"

std::ostream &operator<<(std::ostream &stream, const Node &node) {
  stream << node.configuration;
  return stream;
}
