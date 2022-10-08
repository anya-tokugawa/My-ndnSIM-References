#include "ns3/core-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include <random>
#include <stdio.h>
#include <time.h>

namespace ns3 {
int
main(int argc, char* argv[])
{

  Ptr<ns3::UniformRandomVariable> contentRng = CreateObject<UniformRandomVariable>(); // RNG
  contentRng->SetStream(time(NULL));
  for (int i = 0; i < 10; i++)
    std::cout << i << " : " << contentRng->GetValue() << std::endl;

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
