template <typename T>
class stack {
private:
    T *arr;
    T *cursor;
    T *end;
public:
    stack(decltype(sizeof 0) size = 64) try : arr {new T[size] {}}, cursor {this->arr}, end {this->arr + size} {}catch(...) {
        delete[] this->arr;
        throw;
    }
    stack(const stack &rhs) try : arr {new T[rhs.end - rhs.arr] {}}, cursor {this->arr}, end {this->arr + (rhs.end - rhs.arr)} {
        for(auto cursor {rhs.arr}; cursor not_eq rhs.cursor;) {
            *this->cursor++ = *cursor++;
        }
    }catch(...) {
        delete[] this->arr;
        throw;
    }
    stack(stack &&rhs) noexcept : arr {rhs.arr}, cursor {rhs.arr}, end {rhs.end} {
        rhs.arr = rhs.cursor = nullptr;
    }
    ~stack() {
        delete[] this->arr;
    }
public:
    stack &operator=(const stack &rhs) {
        const auto size {rhs.end - rhs.begin};
        T *new_arr {new T[size]};
        auto new_arr_cursor {new_arr};
        try {
            for(auto cursor {rhs.arr}; cursor not_eq rhs.cursor;) {
                *new_arr_cursor++ = *cursor++;
            }
            delete[] this->arr;
        }catch(...) {
            delete[] new_arr;
            throw;
        }
        this->arr = new_arr;
        this->cursor = new_arr_cursor;
        this->end = new_arr + size;
        return *this;
    }
    stack &operator=(stack &&rhs) noexcept {
        if(this == &rhs) {
            return *this;
        }
        delete[] this->arr;
        this->arr = rhs.arr;
        this->cursor = rhs.cursor;
        this->end = rhs.end;
        rhs.arr = nullptr;
        return *this;
    }
public:
    void push(const T &value) {
        if(this->cursor == this->arr) {
            throw "The stack is full!";
        }
        *this->cursor++ = value;
    }
    void pop() {
        if(this->cursor == this->arr) {
            throw "The stack is empty";
        }
        --this->cursor;
    }
    T &top() noexcept {
        return *this->cursor;
    }
    const T &top() const noexcept {
        return *this->cursor;
    }
    void clear() noexcept {
        this->cursor = this->arr;
    }
    bool empty() const noexcept {
        return this->arr == this->cursor;
    }
};
