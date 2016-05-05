#pragma once

#include <sstream>
#include <string>

namespace string_utils
{
  namespace details
  {
    // End-case: There are no more parameters to output.
    // Occurs when no parameters are given to the join function.
    inline void join_impl(std::stringstream &stream, std::string separator) {}
    
    // End-case: The last argument to output. End the recursion here.
    template <typename Arg>
    inline void join_impl(std::stringstream &stream, std::string separator, Arg last)
    {
      stream << last;
    }
    
    // Recursively output the arguments to the stream until an end-case is hit.
    template <typename Arg, typename ...Rest>
    inline void join_impl(std::stringstream &stream, std::string separator, Arg first, Rest ...rest)
    {
      stream << first << separator;
      join_impl(stream, separator, rest...);
    }
  }
  
  // Join data together with a custom separator.
  template <typename ...Args>
  inline std::string join(std::string separator, Args ...args)
  {
    std::stringstream stream;
    
    details::join_impl(stream, separator, args...);
    
    return stream.str();
  }
}
