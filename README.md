# Kettle++

Reduce boilerplate code of `operator`s in `C++` using `SFINAE` and `enable_if`.

## Example
You've written a class and defined `operator+=` and now want to implement binary `operator+`. A common approach is to define this using `operator+=`:

```c++ 
struct Point{
  int x;
  int y;

  friend Point &operator+=(Point& lhs, Point const& rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
  }

  friend Point operator+(Point const& lhs, Point const& rhs) {
    Point tmp{lhs};
    tmp += rhs;
    return tmp;
  }  
};
```

Now imagine implementing `operator-`, `operator*` and `operator/` -- that's a lot of boilerplate!
`Kettle++` uses the ["Substitution Failure Is Not An Error"](https://en.cppreference.com/w/cpp/language/sfinae) and [`enable_if_t`](https://en.cppreference.com/w/cpp/types/enable_if) to reduce the amount of boilerplate code:
```c++ 
using ktl::operator+;
struct Point{
  int x;
  int y;

  friend Point &operator+=(Point& lhs, Point const& rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
  }
};

Point p{1,2};
Point q{1,2};
p + q; // works!
```



This project was inspired by a question on [reddit.com/r/cpp_questions](https://www.reddit.com/r/cpp_questions/comments/jz5nnd/is_it_a_bad_idea_to_give_my_classes_a_crtp_base/?utm_source=share&utm_medium=web2x&context=3)
