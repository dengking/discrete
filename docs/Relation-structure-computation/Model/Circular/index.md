# Circular

关于relation，一个比较有趣的问题就是：circular。我们讨论两种circular：

- 同一个relation内形成circular
- 多个relation间形成circular



## 同一个relation内形成circular

沿着relation不停地进行rewrite（或者说 推导，参见前面相应的章节），通过最终到达了源点，则形成了circular。当使用graph来表示relation时，这种现象是非常任意理解的。

## 多个relation间形成circulars

在`Book-Discrete-Mathematics-and-Its-Applications\Chpater-9-Relations\Supplementary Exercises`中给出了circular的描述：

> Arelation R is called circular if `aRb` and `bRc` imply that `cRa`. Show that `R` is reflexive and circular if and only if it is an equivalence relation.



