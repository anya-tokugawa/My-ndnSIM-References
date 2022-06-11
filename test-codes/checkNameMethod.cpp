  Name name = interest.getName(); // or data.getName();
  std::cout 
    << "TEST: name.getPrefix(n)"
    << "\n-2:" << name.getPrefix(-2) 
    << "\n-1:" << name.getPrefix(-1) 
    << "\n0:" << name.getPrefix(0) 
    << "\n1:" << name.getPrefix(1)
    << "\n2:" << name.getPrefix(2)
    << "\nTEST: name.at(n)"
    << "\n-2:" << name.at(-2) 
    << "\n-1:" << name.at(-1) 
    << "\n0:" << name.at(0) 
    << "\n1:" << name.at(1)
    << "\n2:" << name.at(2)
    << "\nTEST: name.getSubName(n)"
    << "\n-2:" << name.getSubName(-2)
    << "\n-1:" << name.getSubName(-1)
    << "\n0:" << name.getSubName(0)
    << "\n1:" << name.getSubName(1)
    << "\n2:" << name.getSubName(2) << std::endl;
