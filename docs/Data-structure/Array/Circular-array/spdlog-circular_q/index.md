# spdlog `circular_q`

源：https://github.com/gabime/spdlog/blob/v1.x/include/spdlog/details/circular_q.h

本程序中overrun与overwrite同义，关于overwrite，参见 https://en.wikipedia.org/wiki/Circular_buffer

`tail_`所指向的位置是留空的

本程序采用的是https://en.wikipedia.org/wiki/Circular_buffer#Circular_buffer_mechanics中描述的表示buffer的full状态、empty状态的方法
当`tail_`与`head_`相等时，表示buffer满了，则就需要overwrite，此时需要将`head_`后移，移动后，buffer依然是full的状态。

```c++
// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

// circular q view of std::vector.
#pragma once

#include "stddef.h"
#include <vector>

/**
 * 源：https://github.com/gabime/spdlog/blob/v1.x/include/spdlog/details/circular_q.h
 * 本程序中overrun与overwrite同义，关于overwrite，参见 https://en.wikipedia.org/wiki/Circular_buffer
 *
 * tail_所指向的位置是留空的
 * 本程序采用的是https://en.wikipedia.org/wiki/Circular_buffer#Circular_buffer_mechanics中描述的表示buffer的full状态、empty状态的方法
 * 当tail_与head_相等时，表示你buffer满了，则就需要overwrite，此时需要将head_后移，移动后，buffer依然是full的状态
 */
namespace spdlog {
namespace details {
template<typename T>
class circular_q
{
    size_t max_items_ = 0;
    // index
    typename std::vector<T>::size_type head_ = 0;
    typename std::vector<T>::size_type tail_ = 0;
    size_t overrun_counter_ = 0;
    std::vector<T> v_;

public:
    using value_type = T;

    // empty ctor - create a disabled queue with no elements allocated at all
    circular_q() = default;

    explicit circular_q(size_t max_items)
        : max_items_(max_items + 1) // one item is reserved as marker for full q
        , v_(max_items_)
    {}

    circular_q(const circular_q &) = default;
    circular_q &operator=(const circular_q &) = default;

    // move cannot be default,
    // since we need to reset head_, tail_, etc to zero in the moved object
    circular_q(circular_q &&other) noexcept
    {
        copy_moveable(std::move(other));
    }

    circular_q &operator=(circular_q &&other) noexcept
    {
        copy_moveable(std::move(other));
        return *this;
    }

    // push back, overrun (oldest) item if no room left
    void push_back(T &&item)
    {
        if (max_items_ > 0)
        {
            v_[tail_] = std::move(item);
            tail_ = (tail_ + 1) % max_items_;

            if (tail_ == head_) // overrun last item if full
            {
                head_ = (head_ + 1) % max_items_;
                ++overrun_counter_;
            }
        }
    }

    // Return reference to the front item.
    // If there are no elements in the container, the behavior is undefined.
    const T &front() const
    {
        return v_[head_];
    }

    T &front()
    {
        return v_[head_];
    }

    // Return number of elements actually stored
    size_t size() const
    {
        if (tail_ >= head_)
        {
            return tail_ - head_;
        }
        else
        {
            return max_items_ - (head_ - tail_);
        }
    }

    // Return const reference to item by index.
    // If index is out of range 0鈥?size()-1, the behavior is undefined.
    const T &at(size_t i) const
    {
        assert(i < size());
        return v_[(head_ + i) % max_items_];
    }

    // Pop item from front.
    // If there are no elements in the container, the behavior is undefined.
    void pop_front()
    {
        head_ = (head_ + 1) % max_items_;
    }

    bool empty() const
    {
        return tail_ == head_;
    }

    bool full() const
    {
        // head is ahead of the tail by 1
        if (max_items_ > 0)
        {
            return ((tail_ + 1) % max_items_) == head_;
        }
        return false;
    }

    size_t overrun_counter() const
    {
        return overrun_counter_;
    }

private:
    // copy from other&& and reset it to disabled state
    void copy_moveable(circular_q &&other) noexcept
    {
        max_items_ = other.max_items_;
        head_ = other.head_;
        tail_ = other.tail_;
        overrun_counter_ = other.overrun_counter_;
        v_ = std::move(other.v_);

        // put &&other in disabled, but valid state
        other.max_items_ = 0;
        other.head_ = other.tail_ = 0;
        other.overrun_counter_ = 0;
    }
};
} // namespace details
} // namespace spdlog

#include "circular_q.h"
using namespace spdlog::details;
int main()
{
    circular_q<int> my_q(10);
    for (int i = 0; i < 100; i++)
    {
        my_q.push_back(i);
    }
}
// g++ --std=c++11 main.cpp

```

