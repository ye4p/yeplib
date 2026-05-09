#pragma once

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
        vector();
        ~vector();
        size_t size();
    };
}