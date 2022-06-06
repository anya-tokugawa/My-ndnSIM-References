   std::cout 
    << "TEST: name.getPrefix(n)"
    << "\n-2:" << interest.getName().getPrefix(-2) 
    << "\n-1:" << interest.getName().getPrefix(-1) 
    << "\n0:" << interest.getName().getPrefix(0) 
    << "\n1:" << interest.getName().getPrefix(1)
    << "\n2:" << interest.getName().getPrefix(2)
    << "\nTEST: name.at(n)"
    << "\n-2:" << interest.getName().at(-2) 
    << "\n-1:" << interest.getName().at(-1) 
    << "\n0:" << interest.getName().at(0) 
    << "\n1:" << interest.getName().at(1)
    << "\n2:" << interest.getName().at(2)
    << "\nTEST: name.getSubName(n)"
    << "\n-2:" << interest.getName().getSubName(-2)
    << "\n-1:" << interest.getName().getSubName(-1)
    << "\n0:" << interest.getName().getSubName(0)
    << "\n1:" << interest.getName().getSubName(1)
    << "\n2:" << interest.getName().getSubName(2) << std::endl;
