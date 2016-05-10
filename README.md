# String Utils

A quick header-only collection of useful string manipulation functionality. 

## Concat

Used to quickly wrangle data together and return the values as one string. Can take any data that can be sent to an ostream.

Example: 

```cpp
std::string name = "Anthony";
int age = 25;
std::cout << concat("Hello, my name is ", name, ". I am ", age, " years old");
```

Although the lack of string format specifiers make it not practical for localizations, I find this useful for logging purposes and quick val-to-string conversions.

## Join

## Split
