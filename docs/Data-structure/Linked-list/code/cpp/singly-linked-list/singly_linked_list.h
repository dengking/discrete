#include <memory>

template <typename T>
class SinglyLinkedList
{
    struct Node
    {
        T data_;
        std::unique_ptr<Node> next_;
        Node(T data) : data_(std::move(data))
        {
        }
    };

    std::unique_ptr<Node> head_;
    Node *tail_{nullptr};

public:
    SinglyLinkedList() = default;
    SinglyLinkedList(const SinglyLinkedList &other) = delete;
    SinglyLinkedList &operator=(const SinglyLinkedList &other) = delete;

    /// @brief 
    /// 一、append to tail
    /// 二、需要考虑队列是否为空
    /// @param new_value
    void push(T new_value)
    {
        std::unique_ptr<Node> new_node(new Node(std::move(new_value)));
        Node *const new_tail = new_node.get();
        if (tail_) // 队列非空
        {
            tail_->next_ = std::move(new_node);
        }
        else // 队列为空
        {
            head_ = std::move(new_node);
        }
        tail_ = new_tail; // 总是让tail指向new tail_
    }
    
    /// @brief 以迭代的方式获得链表节点的个数，由于本实现中是使用的smart pointer std::unique_ptr来管理node的，
    /// 因此本方法的实现需要对smart pointer的使用有一定的了解: 由于我们是iteration，仅仅access node而已，因此使用
    /// `std::unique_ptr.get()`
    /// @return
    size_t get_size_by_iteration()
    {
        size_t size = 0;
        for(Node *itor = head_.get();itor;itor = itor->next_.get())
        {
            ++size;
        }
        return size;
    }
};
