#pragma once

#include <sstream>
#include <string>

namespace string_utils
{
  namespace details
  {
    // End-case: There are no more parameters to output.
    inline void concat_impl(std::stringstream &stream) {}
    
    // Recursively output the arguments to the stream until an end-case is hit.
    template <typename Arg, typename ...Rest>
    inline void concat_impl(std::stringstream &stream, Arg first, Rest ...rest)
    {
      stream << first;
      concat_impl(stream, rest...);
    }
  }
  
  // Concatenate data together in a type-safe manner.
  template <typename ...Args>
  inline std::string concat(Args ...args)
  {
    std::stringstream stream;
    
    details::concat_impl(stream, args...);
    
    return stream.str();
  }
}
