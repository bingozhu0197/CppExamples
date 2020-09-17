#include <iostream>

/* Technicals used here:
   1. We can access different class/struct with same named function or member with template
   2. lambda can play as template
   3.  lambda can used as template parameter
   */ 
auto accessMemberBar = [](auto& p_obj) -> auto&& {
  std::cout << p_obj.bar << std::endl;
  return p_obj.bar;
};

struct Foo{
  int bar;
};

template <typename Object, typename BarOutFunction>
void outputBar(Object& p_obj, BarOutFunction p_outFunc){
  p_outFunc(p_obj);
}

int main(int argc, char * argv[])
{
  Foo f = {111};
  // accessMemberBar(f);
  outputBar(f, accessMemberBar);
  return 0;
}
