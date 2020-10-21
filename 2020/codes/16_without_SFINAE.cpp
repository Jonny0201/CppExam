template <typename T>
struct add_lvalue_reference {
    using type = T &;
};

// void 型別
template <>
struct add_lvalue_reference<void> {
    using type = void;
};
template <>
struct add_lvalue_reference<const void> {
    using type = const void;
};
template <>
struct add_lvalue_reference<volatile void> {
    using type = volatile void;
};
template <>
struct add_lvalue_reference<const volatile void> {
    using type = const volatile void;
};

// 復雜的函式型別
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) &> {
    using type = T (Args...) &;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) &> {
    using type = T (Args..., ...) &;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) &&> {
    using type = T (Args...) &&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) &&> {
    using type = T (Args..., ...) &&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const> {
    using type = T (Args...) const;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const> {
    using type = T (Args..., ...) const;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const&> {
    using type = T (Args...) const&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const&> {
    using type = T (Args..., ...) const&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const&&> {
    using type = T (Args...) const&&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const&&> {
    using type = T (Args..., ...) const&&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) volatile> {
    using type = T (Args...) volatile;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) volatile> {
    using type = T (Args..., ...) volatile;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) volatile&> {
    using type = T (Args...) volatile&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) volatile&> {
    using type = T (Args..., ...) volatile&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) volatile&&> {
    using type = T (Args...) volatile&&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) volatile&&> {
    using type = T (Args..., ...) volatile&&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const volatile> {
    using type = T (Args...) const volatile;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const volatile> {
    using type = T (Args..., ...) const volatile;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const volatile&> {
    using type = T (Args...) const volatile&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const volatile&> {
    using type = T (Args..., ...) const volatile&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const volatile&&> {
    using type = T (Args...) const volatile&&;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const volatile&&> {
    using type = T (Args..., ...) const volatile&&;
};

// C++17 起 noexcept 可存在於函式型別
#if (__cplusplus >= 201703L || __cpp_noexcept_function_type >= 201510L)
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) & noexcept> {
    using type = T (Args...) & noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) & noexcept> {
    using type = T (Args..., ...) & noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) && noexcept> {
    using type = T (Args...) && noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) && noexcept> {
    using type = T (Args..., ...) && noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const noexcept> {
    using type = T (Args...) const noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const noexcept> {
    using type = T (Args..., ...) const noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const& noexcept> {
    using type = T (Args...) const& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const& noexcept> {
    using type = T (Args..., ...) const& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const&& noexcept> {
    using type = T (Args...) const&& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const&& noexcept> {
    using type = T (Args..., ...) const&& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) volatile noexcept> {
    using type = T (Args...) volatile noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) volatile noexcept> {
    using type = T (Args..., ...) volatile noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) volatile& noexcept> {
    using type = T (Args...) volatile& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) volatile& noexcept> {
    using type = T (Args..., ...) volatile& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) volatile&& noexcept> {
    using type = T (Args...) volatile&& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) volatile&& noexcept> {
    using type = T (Args..., ...) volatile&& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const volatile noexcept> {
    using type = T (Args...) const volatile noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const volatile noexcept> {
    using type = T (Args..., ...) const volatile noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const volatile& noexcept> {
    using type = T (Args...) const volatile& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const volatile& noexcept> {
    using type = T (Args..., ...) const volatile& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args...) const volatile&& noexcept> {
    using type = T (Args...) const volatile&& noexcept;
};
template <typename T, typename ...Args>
struct add_lvalue_reference<T (Args..., ...) const volatile&& noexcept> {
    using type = T (Args..., ...) const volatile&& noexcept;
};
#endif
