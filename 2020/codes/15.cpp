#include <iostream>

struct Foo {
    int a {0};
    int override {1};
    constexpr static int c {3};
    bool operator==(const Foo &rhs) {
        return this->a == rhs.a and this->override == rhs.override;
    }
    Foo() noexcept = default;
    Foo(const Foo &) = delete; Foo(Foo &&rhs) noexcept {
        this->a = rhs.a;
        this->override = rhs.override;
    }
    virtual ~Foo() = default;
};
struct Bar : Foo {
    std::string str;
    Bar(const std::string str = "0") : str(str) {}
};
int main(int argc, char *argv[]) {
    Bar b1("hello");
    Bar b2 = static_cast<Bar &&>(b1);
}
