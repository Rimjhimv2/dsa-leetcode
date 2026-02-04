Approach / Logic
Since we need the longest continuous substring, we use the sliding window (two pointers) technique.
For each index i, the cost to convert s[i] to t[i] is
abs(s[i] - t[i]).
We maintain a window [left, right] and keep track of the current total cost of converting characters inside the window.
As we expand the window by moving right, we add the conversion cost of the new character.
If the total cost exceeds maxCost, we shrink the window from the left until the cost becomes valid again.
For every valid window (cost ≤ maxCost), we update the maximum window length.
The final answer is the maximum length of any valid window.