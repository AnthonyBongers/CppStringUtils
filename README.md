# Data Joining

This function takes all the data given, and separates them by a string of your choosing.

```cpp
string result = join(" - ", "Anthony", 1, 1.32, 's');
// result = "Anthony - 1 - 1.32 - s"
```

## Pros

Typesafe and easy to use.

## Cons

Streams can be slow.  
Stream manipulators (ex. boolalpha) count as an element even though they don't print anything. 
