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
        Node() = default;
    };

    Node dummy_head_{};
    Node *tail_{nullptr};

public:
    SinglyLinkedList()
    {
    }
    SinglyLinkedList(const SinglyLinkedList &other) = delete;
    SinglyLinkedList &operator=(const SinglyLinkedList &other) = delete;

    /// @brief append to tail
    /// @param new_value
    void push(T new_value)
    {
        tail_->data_ = std::move(new_value);
        std::unique_ptr<Node> new_node;
        Node *const new_tail = new_node.get();
        tail_->next_ = std::move(new_node);
        tail_ = new_tail;
    }
};
