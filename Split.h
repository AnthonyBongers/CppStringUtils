#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace string_utils
{
  inline std::vector<std::string> split(const std::string &value, const std::string &token)
  {
    std::vector<std::string> collection;
    auto begin = value.begin();
    
    while (begin != value.end())
    {
      auto end = std::search(begin, value.end(), token.begin(), token.end());
      
      collection.push_back({ begin, end });
      
      if (end != value.end()) begin = end + token.length();
      else break;
    }
    
    return collection;
  }
}
