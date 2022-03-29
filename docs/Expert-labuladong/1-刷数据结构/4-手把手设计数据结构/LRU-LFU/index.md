# 设计数据结构

## LRU & LFU

两者相同点：

一、capacity

当capacity满后，需要删除末尾节点

二、一旦get、put，就需要更新这个node的属性：

在LRU中，需要`makeRecently`；

在LFU中，需要`increaseFreq`；

三、两者的`put`逻辑类似

