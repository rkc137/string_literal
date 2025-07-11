#pragma once

namespace rkc
{

template<size_t N>
struct string_literal_t
{
public:
    char value[N];

    using str_t = const char[N];
    
    constexpr string_literal_t(str_t &str)
    {
        copy_n(str, N, value);
    }

    constexpr operator str_t&() const
    {
        return value;
    }
    
private:
    template<class InputIt, class Size, class OutputIt>
    constexpr OutputIt copy_n(InputIt first, Size count, OutputIt result)
    {
        if(count > 0)
            for(Size i = 0; i < count; i++)
            {
                *result = *first;
                result++;
                first++;
            }
        return result;
    }
};

}