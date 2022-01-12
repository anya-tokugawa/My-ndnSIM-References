# Snippets Memo

pick times

```cxx
double nowTime = Simulator::Now().ToDouble(Time::S);
```

pick node


```cxx
#include <ns3/node-list.h>
#include <ns3/node.h>
// rerturn ptr.
uint32_t context = ns3::Simulator::GetContext();
if(context != std::numeric_limits<uint32_t>::max())
{
    Ptr<ns3::Node> node = ns3::NodeList::GetNode(context);
}
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
shared_ptr<Name> nameObj = make_shared<Name>(m_interestName);
nameObj->appendSequenceNumber(seq);
```

get seq

```cxx
uint32_t seq = interest->getName().at(-1).toSequenceNumber();
```

## NodeContainer


```cxx
NodeContainer c;
c.Add(NodeObj);
for (NodeContainer::Iterator i = c.Begin(); i != c.End(); ++i) {
    (*i)->GetId();
}
```

## Schedule

hpp

```cxx
public:
    void foobarLogging(Ptr<YansWifiPhy> sender> const;
```

呼び出す関数は `const` で定義。

```cxx
void foobarLogging() const {
   // processing...
   Simulator::Schedule(Seconds(INTERVAL),&YourClassName::foobarLogging,this); 
}
```

