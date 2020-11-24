# Kettle++

Reduce boilerplate code of `operator`s in `C++` using CRTP.

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

Now imagine implements `operator-`, `operator*` and `operator/` -- that's a lot of boilerplate. 
`Kettle++` uses the [CRTP](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) and implementation classes to reduce the amount of boilerplate code:
```c++ 
struct PointImpl{
  int x;
  int y;

  friend Point &operator+=(Point& lhs, Point const& rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
  }
};

struct Point : public PointImpl, protected binary_plus<PointImpl>{
  using PointImpl::PointImpl;
};
```

This project was inspired by a question on [reddit.com/r/cpp_questions](https://www.reddit.com/r/cpp_questions/comments/jz5nnd/is_it_a_bad_idea_to_give_my_classes_a_crtp_base/?utm_source=share&utm_medium=web2x&context=3)
