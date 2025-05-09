# machstic
match them std::variants with ease

This provides two functions: `match` and `match_mut`.

- `match`: allows you to access variants of a `std::variant` in a `const` way.
- `match_mut`: allows you to modify variants of a `std::variant`.

# Example

```c++
#include "../machstic.hpp"

#include <iostream>

int main() {
    std::variant<int, float> number = (int)69;

    match(number,
        [](const int& integer) {
            std::cout << "Integer: " << integer << std::endl;
        },
        [](const float& float_num) {
            std::cout << "Float: " << float_num << std::endl;
        }
    );

    match_mut(number,
        [](int& integer) {
            integer = 420;
        },
        [](float& float_num) {
            float_num = 100.0;
        }
    );

    return 0;
}
```

More examples in `examples/` directory. You can build them with `make example`, and view the executables (and source code) in `examples/`

Note: by including `machstic.hpp` you are automatically including `<variant>`,
so you don't have to manually include that.

As for performance... I don't know. This does use lambdas, polymorphism and heap
allocation so it should be pretty slow. I recommend you use this only for basic tasks.
