# Ordering and object lifetime

## draft 1

不可依赖于未知的、无序的、不可靠的，而是要进行显式的、可靠的控制(take control)，这在对object的lifetime的控制中尤为重要:

process exit的 时候，对destructor的调用顺序是比较复杂的，并且当object非常多的时候，programmer压根就无法进行准确的把控，对它们之间的依赖关系是未知的，尤其是当使用multiple thread、`shared_ptr`等，就会使情况更加复杂。

> NOTE: 
>
> 下面是multiple thread中的一个例子: 
>
> 原来的程序将对行情插件的重订阅线程、行情消息处理线程的停止放到了行情 类的析构函数中，由于对析构函数的调用不受programmer的控制，这就可能出现: 重订阅线程、行情消息处理线程没有被及时地停止并且使用已经被析构的对象而导致segment fault；修改方法是：显示地调用线程停止函数将重订阅线程、行情消息处理线程停止，从而确保不会出现前面描述的情况

过去我总是习惯于将一些资源的释放放到destructor中，正如前面所述，destructor有时也是不可靠的，因此在一些情况下，我们要尽可能地选择更加准确的、可靠的控制方式，比如在`OnStop`中显式地将资源释放，这样的程序是更加健壮的。



## draft 2 Dangling pointer

在TCP SDK（网络库，可以认为是一个[Event-driven architecture](https://en.wikipedia.org/wiki/Event-driven_architecture)），一般采 [Publish–subscribe pattern](https://en.wikipedia.org/wiki/Publish%E2%80%93subscribe_pattern)、[Observer pattern](https://en.wikipedia.org/wiki/Observer_pattern) ；这两种模式的一个共性就是: 将**Listener对象**传入到TCP SDK（网络库），一般是通过pointer、reference的方式进行注册；TCP SDK会network的各种event通过回调**Listener对象**的成员方法通知到应用层，比如将**连接断开**的事件通过调用**Listener对象**的`OnDisconnected`通知到应用层。下面描述了在这种模式下非常容易出现的一个问题:

如果TCP SDK的网络断开是**异步**的，并且不对**Listener对象**的lifetime的进行控制；那么就存在这样的一种可能: **Listener对象**已经被释放了，而TCP SDK并不知晓，依然调用`OnDisconnected`；

则这样就发生了本节标题中描述的dangling pointer错误，导致程序core dump。

对网络连接的断开、object的lifetime不就行**控制**而导致的问题，修正方法是：首先将网络连接关闭（使用阻塞的方法），待关闭完成后（`OnDisconnected`被调用了），再来析构`Listener`对象。





## draft 2

Static Initialization Order Fiasco

参见工程programming-language的相关章节。



## draft

以Access outside of object lifetime来组织很多内容

