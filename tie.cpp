#include <iostream>
#include <string>
#include <tuple>

struct People{
  auto tie() const
  {
    return std::tie(firtName, lastName);
  }
  bool operator == (const People& p_other) const
  {
    return tie() == p_other.tie();
  }
  std::string firtName;
  std::string lastName;
};

int main(){
  People zs{"hello", "world"};
  People ls{"hello", "world"};

  std::cout << (zs == ls) << std::endl;
}