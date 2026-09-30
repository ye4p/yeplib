namespace yep
{
    template <class T>
    class unique_ptr
    {
        T *ptr_;

    public:
        // Constructor
        unique_ptr() : ptr_(nullptr) {

        }
        explicit unique_ptr(T *ptr) : ptr_(ptr) {}

        //Destructor
        ~unique_ptr() { 
            delete ptr_; 
        }

        // Copy constructor
        unique_ptr(const unique_ptr &other) = delete;

        // Copy assignment operator
        unique_ptr& operator=(const unique_ptr &other) = delete;

        // Move constructor
        unique_ptr(unique_ptr&& other) : ptr_(other.ptr_) {
            other.ptr_ = nullptr;
        }

        // Move assignment operator
        unique_ptr& operator=(unique_ptr&& other) {
            if (this != &other) {
                delete ptr_;
                ptr_ = other.ptr_;
                other.ptr_ = nullptr;

            }
            return *this;
        }

        T& operator*() const
        {
            return *ptr_;
        }

        T* operator->() const
        {
            return ptr_;
        }

        T* get() const
        {
            return ptr_;
        }
        
        operator bool() const {
            return ptr_ != nullptr;
        }

        T* release() {
            T* temp = ptr_;
            ptr_ = nullptr;
            return temp;
        }

        void reset(T* ptr = nullptr) {
            delete ptr_;
            ptr_ = ptr;
        }
    };
}
int main() {}
