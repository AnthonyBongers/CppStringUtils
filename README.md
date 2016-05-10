# String Utils

A quick header-only collection of useful string manipulation functionality. Check out [this code](./main.cpp) for some executable examples.

## Concat

Used to quickly wrangle data together and return the values as one string. Can take any data that can be sent to an ostream.

Example: 

```cpp
std::string name = "Anthony";
int age = 90;
std::cout << concat("Hello, my name is ", name, ". I am ", age, " years old!");

// Output: Hello, my name is Anthony. I am 90 years old!
```

Although the lack of string format specifiers make it not practical for localizations, I find this useful for logging purposes and quick val-to-string conversions.

## Join

Used to join together a bunch of data interleaved with a specific separator. Can take any data that can be sent to an ostream.

```cpp
std::cout << join(", ", 1, 1.5f, 2, 2.5f);

// Output: 1, 1.5, 2, 2.5
```

Can be used to separate data in meaningful ways, such as generating comma-separated values in a CSV file. Or whatever you want; the sky is the limit!

## Split

Used to split up text into chunks, separated by a given token.

```cpp
std::string sentence = "The quick brown fox jumps over the lazy dog";
auto words = split(sentence, " ");

std::cout << "The 5th word in the sentence is " << words[4] << "!";

// Output: The 5th word in the sentence is jumps!
```


