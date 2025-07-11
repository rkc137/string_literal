# rkc's string literal

## What is this?
A small header only C++ library for passing string literals as template parameters.

## Integration
Use FetchContent to let CMake download it on-demand
```CMake
FetchContent_Declare(
    string_literal
    GIT_REPOSITORY https://github.com/rkc137/string_literal.git
    GIT_TAG <latest-git-tag>
)
FetchContent_MakeAvailable(string_literal)
```
Or, if you use CPM.cmake:
```CMake
CPMAddPackage("gh:rkc137/string_literal@<latest-git-tag>")
```
## Examples
very expresive and self explanatory code, but without passing string every time:
```c++
#include <rkc/string_literal.hpp>

template <rkc::string_literal_t name>
void set_univalue(float value)
{
    static auto location = glGetUniformLocation(shader_program, name.value); 
    glUniform1f(location, value);
}
//...
anim += 0.01;
shader.set_uniform_value<"animation1">(glm::sin(anim));
shader.set_uniform_value<"animation2">(glm::cos(anim));
```
or for pretty exits on parsing args:
```c++
#include <rkc/string_literal.hpp>

// this is absolutely unnecessary here, but i really like it u know
template <rkc::string_literal_t err>
void exit_if(bool expr)
{
    if(!expr) return; 
    std::cout << err << usage;
    std::exit(0);
};
//...
// feels like a straight sentence "exit if folder exist"
exit_if<"folder with this name allready exists">(fs::exists(arg));
```

## why?
cause i can


and cause i wanna try make lib with cmake
