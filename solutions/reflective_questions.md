### Reflection Questions
#### Task 1:
**1. How do you link prev and next pointers correctly using a static array?**  
In a static array, each element already exists in memory at fixed positions. To link the `prev` and `next` pointers, I use the array indexes. For example, for `nodes[i]`, I set `nodes[i].prev = &nodes[i - 1]` if `i > 0`, and `nodes[i].next = &nodes[i + 1]` if `i < size - 1`. This way, the nodes are connected without using dynamic memory.

**2. What are advantages and limitations of compile-time vs. dynamic allocation?**  
The main advantage of compile-time allocation is performance. It is faster and safer because there is no need for `malloc` or `free`, and memory is managed automatically. It also avoids memory leaks.  
However, the main limitation is flexibility. With static memory, I cannot add or remove nodes at runtime. The size is fixed at compile time, which is not good for applications where the list size is unknown or changing.

**3. How would you extend this static list to include additional data fields?**  
To add more data to each node, I just need to add new fields to the `DNode` struct. For example, I can add an `int id` or a `char name[20]`. Then I initialize those fields in the same loop where I set the `data`, `prev`, and `next` pointers.

#### Task 2:
**1. Why is malloc necessary when adding nodes dynamically?**
Malloc is necessary because we don't know how many nodes we will need at runtime. With malloc, we can allocate memory from the heap whenever the user adds a node. Without malloc, we would have to define a fixed-size array, which is not flexible. Malloc makes the list dynamic and scalable.

**2. How can you traverse the list to print each node’s address and value?**
We can use a pointer variable to go through the list. Start at the head and use a while loop to follow the next pointers. In each step, we print the address using %p and the value using %d.

Example:

```c
SNode *p = head;
while (p != NULL) {
    printf("Node at %p: %d\n", (void*)p, p->value);
    p = p->next;
}
```
**3. What are the consequences of not freeing the list before exit?**
If we don't free the list, the memory allocated with malloc stays reserved until the program ends. This causes memory leaks, which is a problem if the program runs for a long time or if we repeat the operation many times. It also shows bad programming practice, especially in embedded systems where memory is limited.

#### Task 3
**1. How does using getopt make the program more flexible than argv[1]?**  
   Using `getopt` makes the program more flexible because it allows named options like `-i`, which makes the command line arguments easier to understand and extend. Instead of relying on the order of arguments (like `argv[1]`), `getopt` lets the user provide options in any order, and it also makes it possible to add more flags in the future.

**2. What happens if the user omits the -i option?**  
   If the user does not provide the `-i` option, the program will call the `usage()` function and exit with an error message. This prevents the program from running without a valid input file and helps avoid undefined behavior.

**3. How can you validate that the JSON file loaded is indeed an array?**  
   After loading the JSON with `json_load_file()`, you can check the type using `json_is_array()`. This function returns true if the root element is a JSON array. If it returns false, the program should show an error and exit to avoid parsing invalid or unexpected structures.

```
