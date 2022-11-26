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
    Node *tail_;

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
        if (tail)
        {
            tail->next = std::move(new_node);
        }
        else
        {
            head = std::move(new_node);
        }
        tail = new_tail;
    }
};

int main()
{
    SinglyLinkedList<int> l;
    l.push(1);
    l.push(2);
    l.push(3);
}