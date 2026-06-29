#include "yeplib/unique_ptr.h"

namespace yep
{
    template <class T>
    class unique_ptr
    {
        T *ptr_;

    public:
        unique_ptr() : ptr_(nullptr) {}
        explicit unique_ptr(T *ptr) : ptr_(ptr) {}
        ~unique_ptr() { delete ptr_; }
    };
}