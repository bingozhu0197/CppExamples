#include "Type.hpp"

int main(int argc, char* argv[])
{
  int int_value = 8;
  auto assign_value = int_value;

  printTypeName(assign_value);

  return 0;
}