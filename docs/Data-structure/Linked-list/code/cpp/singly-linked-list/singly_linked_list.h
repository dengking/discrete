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
    /// @param new_value
    void push(T new_value)
    {
        std::unique_ptr<Node> new_node(new Node(std::move(new_value)));
        Node *const new_tail = new_node.get();
        if (tail_)
        {
            tail_->next_ = std::move(new_node);
        }
        else
        {
            head_ = std::move(new_node);
        }
        tail_ = new_tail; // 总是让tail指向new tail_
    }
    /// @brief 以迭代的方式获得链表节点的个数
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
