#include "ns3/core-module.h"
#include "ns3/ndnSIM/ndn-cxx/name.hpp"
#include <stdio.h>

namespace ns3 {
int
main(int argc, char* argv[])
{

  ndn::Name name("/1/2/3.txt");
  std::cout << "Uri: " << name.toUri() << std::endl;

  std::string p, s;
  s = "):";
  p = "TEST: name.getPrefix(";
  for (int i = -2; i < 3; i++) {
    std::cout << p << i << s << name.getPrefix(i) << std::endl;
  }
  p = "TEST: name.at(";
  for (int i = -2; i < 3; i++) {
    std::cout << p << i << s << name.at(i) << std::endl;
  }
  p = "TEST: name.getSubName(";
  for (int i = -2; i < 3; i++) {
    std::cout << p << i << s << name.getSubName(i) << std::endl;
  }

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
