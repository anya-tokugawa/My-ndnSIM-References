# Snippets Memo

pick times

```cxx
double nowTime = Simulator::Now().ToDouble(Time::S);
```

pick faces from node.

```cxx
  ns3::Ptr<ns3::Node> node = ns3::NodeList::GetNode(ns3::Simulator::GetContext());
  ns3::Ptr<ns3::ndn::L3Protocol> ndn = node->GetObject<ns3::ndn::L3Protocol>();
  for (uint32_t i = 0; i < node->GetNDevices(); i++)
  {
    shared_ptr<Face> face = ndn->getFaceByNetDevice(node->GetDevice(i));
  }
```

pick forwarder obj. from node.

```cxx
node->GetObject<ndn::L3Protocol>()->getForwarder()->
```

##  SequenceNumber

set at consumer

```cxx
shared_ptr<Name> name = make_shared<Name>(m_interestName);
nameWithSequence->appendSequenceNumber(seq);
```

pick

```cxx
uint32_t seq = interest->getName().at(-1).toSequenceNumber();
```
