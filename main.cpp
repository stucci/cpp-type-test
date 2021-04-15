#include <type_traits>
#include <string>
#include <vector>
#include <array>

// [is_scalar - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/type_traits/is_scalar.html)
static_assert(std::is_scalar<int>::value == true, "value == true, int is scalar");
static_assert(std::is_same<std::is_scalar<int>::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::is_scalar<int>::type, std::true_type>::value, "type == true_type");
static_assert(std::is_scalar<int>() == true, "is_scalar<int>() == true");

static_assert(std::is_scalar<void>::value == false, "value == false, void is not scalar");
static_assert(std::is_same<std::is_scalar<void>::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::is_scalar<void>::type, std::false_type>::value, "type == false_type");
static_assert(std::is_scalar<void>() == false, "is_scalar<void>() == false");

enum e{};
class c{};
union u{};
static_assert(std::is_scalar<e>::value == true, "enum is scalar");
static_assert(std::is_scalar<c>::value == false, "class is not scalar");
static_assert(std::is_scalar<u>::value == false, "union is not scalar");
static_assert(std::is_scalar<const volatile int>::value == true, "const volatile int is scalar");
static_assert(std::is_scalar<int*>::value == true, "int* is scalar");
static_assert(std::is_scalar<int[1]>::value == false, "int[1] is not scalar");
static_assert(std::is_scalar<int&>::value == false, "int& is not scalar");
static_assert(std::is_scalar<int ()>::value == false, "int () is not scalar");
static_assert(std::is_scalar<std::nullptr_t>::value == true, "std::nullptr_t is scalar");

struct s
{
  int member_object;        // decltype(&s::member_object) は int s::*
  void member_function(){}; // decltype(&s::member_function) は void (s::*)()
};
static_assert(std::is_scalar<int s::*>::value == true, "int s::* is scalar");
static_assert(std::is_scalar<void (s::*)()>::value == true, "void (s::*)() is scalar");

// add
static_assert(std::is_scalar<char>::value == true, "value == true, char is scalar");
static_assert(std::is_scalar<int64_t>::value == true, "value == true, int64_t is scalar");
static_assert(std::is_scalar<double>::value == true, "value == true, double is scalar");
static_assert(std::is_scalar<std::string>::value == false, "value == false, string is not scalar");
static_assert(std::is_scalar<std::vector<int>>::value == false, "value == false, std::vector<int> is not scalar");

// [is_trivial - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/type_traits/is_trivial.html)
static_assert(std::is_trivial<int>::value == true, "value == true, int is trivial");
static_assert(std::is_same<std::is_trivial<int>::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::is_trivial<int>::type, std::true_type>::value, "type == true_type");
static_assert(std::is_trivial<int>() == true, "is_trivial<int>() == true");

static_assert(std::is_trivial<int&>::value == false, "value == false, int& is not trivial");
static_assert(std::is_same<std::is_trivial<int&>::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::is_trivial<int&>::type, std::false_type>::value, "type == false_type");
static_assert(std::is_trivial<int&>() == false, "is_trivial<int&>() == false");

static_assert(std::is_trivial<const volatile int>::value == true, "const volatile int is trivial");
static_assert(std::is_trivial<int&>::value == false, "int& is not trivial");

class trivial_class{};
struct non_trivial_class {
  non_trivial_class() {}    // デフォルトコンストラクタが非トリビアル
};
static_assert(std::is_trivial<trivial_class>::value == true, "trivial_class is trivial");
// static_assert(std::is_trivial<trivial_class&>::value == true, "trivial_class& is trivial");
static_assert(std::is_trivial<trivial_class&>::value == false, "trivial_class& is not trivial");
static_assert(std::is_trivial<non_trivial_class>::value == false, "non_trivial_class is not trivial");
static_assert(std::is_trivial<non_trivial_class&>::value == false, "non_trivial_class& is not trivial");

// add
static_assert(std::is_trivial<char>::value == true, "value == true, char is trivial");
static_assert(std::is_trivial<int64_t>::value == true, "value == true, int64_t is trivial");
static_assert(std::is_trivial<double>::value == true, "value == true, double is trivial");
static_assert(std::is_trivial<std::string>::value == false, "value == false, string is not trivial");
static_assert(std::is_trivial<std::vector<int>>::value == false, "value == false, std::vector<int> is not trivial");
static_assert(std::is_trivial<std::array<int, 3>>::value == true, "value == false, std::array<int, 3> is trivial");
static_assert(std::is_trivial<int*>::value == true, "value == true, int* is trivial");
static_assert(std::is_trivial<int[]>::value == false, "value == false, int[] is not trivial");

// [true_type - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/type_traits/true_type.html)
static_assert(std::true_type::value == true, "value == true");
static_assert(std::is_same<std::true_type::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::true_type::type, std::true_type>::value, "type == true_type");
static_assert(std::true_type() == true, "true_type() == true");

// [false_type - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/type_traits/false_type.html)
static_assert(std::false_type::value == false, "value == false");
static_assert(std::is_same<std::false_type::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::false_type::type, std::false_type>::value, "type == false_type");
static_assert(std::false_type() == false, "false_type() == false");

int main(){}
