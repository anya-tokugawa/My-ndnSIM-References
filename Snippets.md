# 書き方

現在時刻を取得

```cxx
ns3::Time nowTime = Simulator::Now();
double nowTimeSecond1 = nowTime.ToDouble(Time::S);
double nowTimeSecond2 = nowTime.GetDouble();
```

ノードを取得

```cxx
// 以下をincludeする必要あり．
#include <ns3/node-list.h>
#include <ns3/node.h>

uint32_t context = ns3::Simulator::GetContext();
// コンテキストがuint32_tの最大値4294967295(=2^32 -1)の場合は未定義扱い．
if(context != std::numeric_limits<uint32_t>::max())
{
    // ポインタとしてノードを取得できる．
    ns3::Ptr<ns3::Node> node = ns3::NodeList::GetNode(context);
    // Idをとる．
    uint32_t nodeId = node->GetId();
}
```

ノードからNetDeviceFaceを取得する方法．

```cxx
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

##  シーケンス番号（チャンク番号）について

Nameに挿入する

```cxx
shared_ptr<Name> name = make_shared<Name>("/path/to/content/name");
nameObj->appendSequenceNumber(seq);
```

Nameから取得する

```cxx
Name& name = interest->getName();
uint32_t seq = name.at(-1).toSequenceNumber();
```

## ノードコンテナを用いて，ノードの集合を作る．


```cxx
NodeContainer c;
c.Add(NodeObj);
for (NodeContainer::Iterator i = c.Begin(); i != c.End(); ++i) {
    (*i)->GetId();
}
```

## 自分自身に対し定期的に呼び出し直す．

classname.hpp

```cxx
public:
    void processing(Ptr<YansWifiPhy> sender> const;
```

classname.cpp

```cxx
void processing() const {
   // processing...
   Simulator::Schedule(Seconds(INTERVAL),&ClassName::processing,this); 
}
```

