Reduce boilerplate class member functions using some base class CRTP.

**Example**: a class has defined `operator==` and wants to define the usual  `operator!=` by `A(a==b)`. This boilerplate code can be reduced using this libraries mixin types:
```c++ 
struct A : crtpi::not_equals<A>{
  int i;
  friend bool operator==(A a, A b) { return a.i == b.i;}
};
```    
This is an example of the curiously recurring template pattern (CRTP)[https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern]
