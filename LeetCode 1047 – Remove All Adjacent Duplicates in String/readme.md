We use a stack to process characters one by one.
For each character in the string:
If the stack is empty or the top of the stack is not equal to the current character, we push it onto the stack.
If the top of the stack matches the current character, it means we found adjacent duplicates, so we pop the top element.
After processing all characters, the stack contains the result string but in reverse order.
We pop all characters from the stack, append them to a string, and finally reverse it to get the correct order.