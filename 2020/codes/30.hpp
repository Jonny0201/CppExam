#include <memory>

template <typename T, typename Deleter = std::default_delete<T>>
struct unique_ptr_helper {
protected:
    std::unique_ptr<T, Deleter> *ptr;
    T *temp_ptr;
public:
    constexpr unique_ptr_helper() noexcept = default;
    explicit unique_ptr_helper(std::unique_ptr<T, Deleter> &ptr) noexcept : ptr {&ptr}, temp_ptr {ptr.release()} {}
    unique_ptr_helper(const unique_ptr_helper &) = delete;
    unique_ptr_helper(unique_ptr_helper &&rhs) noexcept : ptr {std::exchange(rhs.ptr, nullptr)} {}
    virtual ~unique_ptr_helper() noexcept {
        if(this->ptr) {
            this->ptr->reset(this->temp_ptr);
        }
    }
public:
    unique_ptr_helper &operator=(const unique_ptr_helper &) & = delete;
    unique_ptr_helper &operator=(unique_ptr_helper &&) & noexcept = delete;
    explicit virtual operator T **() && noexcept {
        return &this->temp_ptr;
    }
};

template <typename T>
unique_ptr_helper<T> unique_ptr_transfer(std::unique_ptr<T> &p) {
    return unique_ptr_helper<T>(p);
}
