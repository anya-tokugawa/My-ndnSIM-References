# Examplesの管理方法例

```bash
cd src/ndnSIM/examples/
mkdir ndn-research-test-senaerios
cp wscript ndn-research-test-senarios/
```

`src/ndnSIM/examples/wscript` に下記を追加．

```python
    senario_dirs = ['ndn-research-test-senarios'];
    for dir in senario_dirs:
        bld.recurse(dir)
``` 

