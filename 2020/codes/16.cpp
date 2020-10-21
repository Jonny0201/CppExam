template <typename T>
struct type_identity {
    using type = T;
};

template <typename T>
type_identity<T&> test_add_reference(int) noexcept;

template <typename T>
type_identity<T>  test_add_reference(...) noexcept;

template <typename T>
struct add_lvalue_reference {
    using type = typename decltype(test_add_reference<T>(0))::type;
};
