# Stack order

stack order: 对于所有需要一对相反的操作，都是可以使用stack来进行模拟的。比如open/close，connect/disconnect，new/delete；

这非常类似于括号匹配，这就引发了一个问题：括号匹配问题。

这引发了我对RAII的思考: RAII，括号，stack，其实它已经展示了三种之间的关系，这是stack order在C++中，非常显著的application。

