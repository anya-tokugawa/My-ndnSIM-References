# ndnSIM 2.1のインストール

```bash
mkdir project

cd project
git clone https://github.com/named-data-ndnSIM/ns-3-dev.git ns-3
git clone https://github.com/named-data-ndnSIM/pybindgen.git pybindgen
git clone --recursive https://github.com/named-data-ndnSIM/ndnSIM.git ns-3/src/ndnSIM

cd ns-3
git checkout ns-3.23-dev-ndnSIM-2.1

cd src/ndnSIM
git checkout ndnSIM-2.1

cd NFD
git checkout NFD-0.3.4

cd ../ndn-cxx
git checkout ndn-cxx-0.3.4-ndnSIM

cd ../../../
./waf configure --enable-examples
./waf
./waf --run ndn-simple
```
