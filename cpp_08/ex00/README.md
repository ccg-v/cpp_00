# Exercise 00: Easy find

## Containers

In C++, a container is a type of data structure that holds and organizes a collection of elements. Containers are part of the Standard Template Library (STL) and are designed to store objects, provide efficient access to them, and offer a variety of operations to manipulate the collection (such as adding, removing, and searching for elements).

### Container categories

There are three primary categories of containers in C++:

1. **Sequence Containers**

	These containers store elements in a linear sequence, where the order of the elements is determined by the order in which they are inserted. Some examples include:

	* `std::vector`: A dynamic array that can grow and shrink as needed. Elements are stored in contiguous memory locations.
	* `std::deque`: A double-ended queue that allows fast insertion and deletion at both the front and back.
	* `std::list`: A doubly linked list that allows fast insertion and deletion anywhere in the list, but slower random access compared to a vector.
	* `std::array`: A fixed-size array with compile-time known size.
	* `std::forward_list`: A singly linked list, optimized for minimal memory overhead, but slower random access.

2. **Associative Containers**

	These containers store elements in a way that allows fast searching, insertion, and deletion based on keys. The elements are usually stored in a sorted manner. Some examples include:

	* `std::set`: A container that stores unique elements in a specific order.
	* `std::map`: A collection of key-value pairs, where each key is unique, and elements are sorted by key.
	* `std::multiset`: Like set, but allows duplicate elements.
	* `std::multimap`: Like map, but allows duplicate keys.

3. **Unordered Containers**

	These containers are similar to associative containers but do not maintain any specific order for the elements. They are based on hash tables and provide very fast access times for searching, insertion, and deletion. Examples include:

	* `std::unordered_set`: A set that stores unique elements with no particular order.
	* `std::unordered_map`: A map that stores key-value pairs with no particular order.
	* `std::unordered_multiset`: A set that allows duplicates and does not maintain any order.
	* `std::unordered_multimap`: A map that allows duplicate keys with no particular order.

### Key Features:

* **Generic**: Containers can store any data type, and you can specify the type of elements they hold using templates.

	```
	std::vector<int> v;       // Vector of integers
	std::set<std::string> s;  // Set of strings
	```

* **Iterators**: Containers provide iterators, which are objects that allow you to traverse through the elements of the container in a uniform way. They act like pointers to the elements in the container.

* **Efficiency**: Different containers are optimized for different operations. For example:

    - `std::vector` is efficient for random access and appending elements at the end.
    - `std::list` is efficient for insertion and deletion at any point in the list.
    - `std::map` provides efficient searching by key.

* **Safety**: Containers automatically manage memory for the objects they store, reducing the risk of memory leaks and pointer errors.

### Example Usage of a Container (std::vector)

	```
	#include <iostream>
	#include <vector>

	int main() {
		std::vector<int> numbers;

		// Adding elements to the vector
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);

		// Accessing elements using an iterator
		for (auto it = numbers.begin(); it != numbers.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		return 0;
	}
	```

### Why Use Containers?

	* `Ease of Use`: You don't have to manually handle memory allocation or resizing, as most containers automatically adjust based on their size.
	* `Efficiency`: STL containers are optimized for performance, with various operations (like sorting, searching, and insertion) being handled efficiently.
	* `Flexibility`: C++ containers can store any data type and can be easily extended with custom behavior.

---------------------------------------------------------------------------------------

## Iterators

An iterator is an object that "points" to an element in a container and allows you to move from one element to the next (just like a pointer). However, iterators are more versatile than pointers because they work with all types of containers, not just arrays.

C++ iterators are defined and supported by the **Standard Template Library (STL)**, and they behave somewhat like pointers with additional functionalities.

### Basic Operations with Iterators:

Iterators support various operations depending on the type of container they are used with. Here are the most common operations:

1. **Begin and End**:

    - `container.begin()`: Returns an iterator pointing to the first element of the container.
    - `container.end()`: Returns an iterator pointing **past the last element**.

	```
	std::vector<int> vec = {10, 20, 30};
	auto it = vec.begin();  // 'it' points to the first element (10)
	```

2. **Dereferencing (*)**:

    You can access the value an iterator points to using the dereference operator (*):

	`int value = *it;  // Gets the value at the current iterator (in this case, 10)`

3. **Increment (++)**:

    You can move the iterator to the next element using the increment operator (++):

	`++it;  // Moves the iterator to the next element (in this case, to 20)`

4. **Equality Comparison (==, !=)**:

    You can compare iterators to see if they are equal or different. This is useful when looping through a container:

	```
	if (it != vec.end()) {
		// Still within the bounds of the container
	}
	```

### Iterator Categories:

Iterators can be classified into different categories based on the operations they support:

* `Input Iterator`: Supports reading the data from a container (like a read-only stream).
* `Output Iterator`: Supports writing data to a container (like an output stream).
* `Forward Iterator`: Supports moving in a single direction (like a singly linked list).
* `Bidirectional Iterator`: Supports moving forward and backward (like a doubly linked list).
* `Random Access Iterator`: Supports arbitrary jumps (like a pointer or array). std::vector provides random access iterators.

### Common Containers and Their Iterator Types:

* `std::vector`: Random access iterator (allows accessing any element in constant time).
* `std::list`: Bidirectional iterator (only allows moving forward or backward one element at a time).
* `std::deque`: Random access iterator.
* `std::set/std::map`: Bidirectional iterator.

--------------------------------------------------------------------------------------- 

## Algorithms

An algorithm is a well-defined set of instructions or steps designed to perform a specific task or solve a particular problem. In the context of programming, it represents the logic or strategy behind how a task is carried out. An algorithm defines how to do something, such as sorting a list, searching for a value, or finding the maximum of a set of numbers.

In C++ programming (especially in the Standard Template Library (STL)), the term *"algorithm"* often refers to **predefined generic algorithms** provided by the STL. These algorithms are designed to work with different types of containers via iterators, such as sorting, searching, or modifying elements. Some examples of common STL algorithms are:

* `std::find`: Searches for an element in a range of elements.
* `std::sort`: Sorts a range of elements in ascending order.
* `std::for_each`: Applies a function to each element in a range.
* `std::reverse`: Reverses the order of elements in a container.

### Difference between algorithms and functions

**Conceptual vs. Concrete**:

* An algorithm is a concept: It is a logical set of steps or instructions to solve a problem. Algorithms are abstract ideas, often independent of programming languages.
* A function is a concrete implementation: It is a specific piece of code written in a programming language to execute a task, which may implement an algorithm.

**Task vs. Process**:

* An algorithm describes how a task should be performed, without necessarily specifying the exact code.
* A function is the actual code that performs the task, often by implementing an algorithm.

**Reusability**:

* Algorithms can be generalized and reused in many different situations, often independent of any particular implementation. For instance, a sorting algorithm can be described without worrying about the specific data types.
* Functions are reusable blocks of code that can be called in a program to avoid code duplication, but they are tied to the specific language or implementation.

In the STL, functions like `std::find`, `std::sort`, and others are part of the **algorithms** category because they implement well-known, abstract algorithms (like linear search or sorting) and follow a standard sequence of steps.

However, when you call `std::find` or `std::sort`, you're actually invoking functions that take parameters (like iterators, ranges, or comparison functions) and return results (like an iterator or nothing in the case of sort). **Thus, you would not be wrong to refer to them as functions**. In fact, they are **function templates**, i.e. functions that are parameterized with types and work across different types of containers. It's just that in C++, these functions are part of the broader category called "STL algorithms" because they follow well-known algorithmic strategies.

---------------------------------------------------------------------------------------