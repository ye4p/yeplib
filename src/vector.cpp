#include "../include/yeplib/vector.hpp"

namespace yep
{
    template <class T>
    class vector
    {
    private:
        T *data_;
        size_t capacity_;
        size_t size_;

    public:
        vector()
        {
            data_ = nullptr;
            capacity_ = 0;
            size_ = 0;
        }

        vector(size_t count)
        {
            // Add some kind of check or something to not just set everything if count=0
            data_ = new T[count];
            capacity_ = count;
            size_ = count;
        }

        ~vector()
        {
            delete[] data_;
        }

        // Copy constructor
        vector(const vector &other)
        {
            size_ = other.size();
            capacity_ = other.capacity();
            delete[] data_;
            data_ = new T[capacity];
            for (int i = 0; i < size_; i++)
            {
                data[i] = other[i];
            }
        }

        //  Copy assignment operator
        vector &operator=(const vector &other)
        {
        }

        size_t size()
        {
            return size_;
        };

        size_t capacity()
        {
            return capacity_;
        }

        bool empty()
        {
            return !size_;
        }

        void push_back(const T &el)
        {
            if (capacity == 0)
            {
                capacity = 1;
                data_ = new T[1];
                data[size] = el;
                size++;
            }
            else if (size_ < capacity_)
            {
                data_[size_] = el;
                size_++;
            }
            else
            {
                capacity_ *= 2;
                T *intermediate_array = new T[capacity_];
                for (int i = 0; i < size_; i++)
                    intermediate_array[i] = data_[i];
                intermediate_array[size_] = el;
                size_++;
                delete[] data_;
                data_ = intermediate_array;
            }
        }

        void reserve(size_t new_capacity)
        {
            if (new_capacity <= capacity)
            {
                return;
            }
            capacity_ = new_capacity;
            T *ir_arr = new T[capacity_];
            for (int i = 0; i < size_; i++)
                ir_arr[i] = data_[i];
            delete[] data_;
            data_ = ir_arr;
        }

        T &operator[](size_t index)
        {
            return data_[index];
        }
    };
}