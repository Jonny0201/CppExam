void f(char &) noexcept;
int main(int argc, char *argv[]) {
    decltype(f) *fp;
    fp = f;
    char c = 0;
    fp(c);
    auto *p = new int;
    const int *cp = p;
    //const_cast<int *>(cp) = p;
    struct Foo {
        int *p;
        struct Bar {
            int i = 0;
            decltype(f) *fp = f;
            bool operator()(char c) noexcept {
                if(this->i == c) {
                    return false;
                }
                fp(c);
                return true;
            }
        };
    };
}
