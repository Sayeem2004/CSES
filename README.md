# Solutions

## Introductory Problems

- [x] [Weird Algorithm](IntroductoryProblems/1068.cpp) - Follow the instructions and simulate the algorithm.

- [x] [Missing Number](IntroductoryProblems/1083.cpp) - Missing number is `N * (N + 1) / 2 -` sum of all numbers given.

- [x] [Repetitions](IntroductoryProblems/1069.cpp) - Use for loop and counter to count the longest sequence of equal characters.

- [x] [Increasing Array](IntroductoryProblems/1094.cpp) - Sum of differences greater than `0` between adjacent elements including updates.

- [x] [Permutations](IntroductoryProblems/1070.cpp) - Print even numbers first and then odd numbers. Edge cases of `N < 4`.

- [x] [Number Spiral](IntroductoryProblems/1071.cpp) - Diagonal of Nth square is `N * N - N + 1`, move up or down from the diagonal.

- [x] [Two Knights](IntroductoryProblems/1072.cpp) - Total ways is `N * N * (N * N - 1) / 2`. Consider `N - 1` by `N - 1` board, each knight attacks `4` squares except knights on edge attack `2`, so we subtract `4 * (N - 1) * (N - 2)` from total ways.

- [x] [Two Sets](IntroductoryProblems/1092.cpp) - If `N % 4 == 1` or `N % 4 == 2` then no solution, otherwise split numbers by groups of `4` which can be split into two sets. If `N % 4 == 3` then one group will have `1 2` and the other `3`.

- [x] [Bit Strings](IntroductoryProblems/1617.cpp) - Number of bit strings is `2^N`, use `MOD` to avoid overflow.

- [x] [Trailing Zeros](IntroductoryProblems/1618.cpp) - Trailing zeros are created by `2 * 5`, latter is less frequent, so count number of `5` factors. Done by summing `N / 5^i` for `i = 1, 2, ...`.

- [x] [Coin Piles](IntroductoryProblems/1754.cpp) - Requirements are that larger pile isn't more than twice as large as smaller because `2/1` ratio is max and total coins is divisible by `3` because we can only remove `3` coins at a time.

- [x] [Palindrome Reorder](IntroductoryProblems/1755.cpp) - Atmost one character can have odd count, put that character in the middle and then put the rest of the characters on both sides in pairs.

- [x] [Gray Code](IntroductoryProblems/2205.cpp) - Solution of `N` is two copies of solution of `N - 1` with `0` and `1` prepended to each respectively and the latter reversed.

- [x] [Tower of Hanoi](IntroductoryProblems/2165.cpp) - Numbers of moves is `2^N - 1`, print the moves recursively using the fact that `N` disks can be moved to the third peg by moving `N - 1` disks to the second peg, moving the last disk to the third peg and then moving the `N - 1` disks to the third peg.

- [x] [Creating Strings I](IntroductoryProblems/1622.cpp) - Use `next_permutation` on sorted string to generate all permutations in order.

- [x] [Apple Division](IntroductoryProblems/1623.cpp) - Use bitmask to generate all possible subsets of apples and calculate minimum difference. Can also be done recursively.

- [x] [Chessboard and Queens](IntroductoryProblems/1624.cpp) - Iterate across rows, and check if queen can be placed in each columns using arrays to keep track of used columns and diagonals. Backtrack if queen can't be placed.

- [x] [Digit Queries](IntroductoryProblems/2431.cpp) - Can calculate number of digits from `1` to `N` using fact that there are `9 * 10^(i - 1) * i` digits from `10^(i - 1)` to `10^i - 1` for `i = 1, 2, ...`. Then use binary search to find the number that contains the `K`th digit.

- [x] [Grid Paths](IntroductoryProblems/1625.cpp) - Use backtracking to generate all possible paths and count the ones that reach the bottom left corner. Use optimizations that if reach bottom left corner before `48` moves then fail, if more than `48` moves then fail, if out of bounds then fail, and finally if front and back blocked, but left and right open then fail.

## Sorting and Searching

- [x] [Distinct Numbers](SortingAndSearching/1621.cpp) - Insert numbers into a set and then print the size of the set.

- [x] [Apartments](SortingAndSearching/1084.cpp) - Sort both apartments and applicants, then assign applicants to smallest apartment that they will accept.

- [x] [Ferris Wheel](SortingAndSearching/1090.cpp) - Sort children by weight, then use two pointers to assign heaviest child with lightest child that they will accept, if no child will accept then assign heaviest child alone.

- [x] [Concert Tickets](SortingAndSearching/1091.cpp) - Use multiset to store ticket prices, then assign each customer the ticket with the larger price that they will accept.

- [x] [Restaurant Customers](SortingAndSearching/1619.cpp) - Iterate through all given start and end times in order, increment counter for start times and decrement counter for end times, keep track of maximum counter value.

- [x] [Movie Festival](SortingAndSearching/1629.cpp) - Sort movies by end time, then greedily choose the movies if they start after the previous movie ends.

- [x] [Sum of Two Values](SortingAndSearching/1640.cpp) - Sort numbers, then use two pointers to find the pair that sums to `X`.

- [x] [Maximum Subarray Sum](SortingAndSearching/1643.cpp) - Use Kadane's algorithm to find the maximum subarray sum. `curr = max(curr + x, x)` and `ans = max(ans, curr)`.

- [x] [Stick Lengths](SortingAndSearching/1074.cpp) - Optimal length is the median of the lengths, so sort the lengths and then calculate the median.

- [x] [Missing Coin Sum](SortingAndSearching/2183.cpp) - Sort coins, start with being able to create all numbers from `0` to `X = 0`. If next coin `C` is greater than `X + 1` then we can't create `X + 1`, otherwise we can create `X + 1` by using the next coin and now we can create all numbers from `0` to `X + C` by induction.

- [x] [Collecting Numbers](SortingAndSearching/2216.cpp) - Iterate through numbers in order, if position of number is less than position of previous number then increment counter. Use map to store position of each number.

- [x] [Collecting Numbers II](SortingAndSearching/2217.cpp) - Use previous solution to calculate initial counter, then deal with `V[a]` and `V[b]` along with their neighbors and update counter accordingly. Use set to not count duplicates.

- [x] [Playlist](SortingAndSearching/1141.cpp) - Use map to store last position of each song, then iterate through songs and update counter with the max difference between current position and last position of song.

- [x] [Towers](SortingAndSearching/1073.cpp) - Directly simulate the process using multiset and add box to smallest tower that it will fit in, if no tower will fit then create new tower.

- [x] [Traffic Lights](SortingAndSearching/1163.cpp) - Use multiset to store traffic light positions and differences. When a new light is added find light before and after it, remove the difference between them from the multiset and add the difference between the new light and the two lights to the multiset.

- [x] [Josephus Problem I](SortingAndSearching/2162.cpp) - Use ordered set to efficiently store and remove people. Use a pointer to keep track of the current person and increment it by `2` and mod by size each time.

- [x] [Josephus Problem II](SortingAndSearching/2163.cpp) - Use ordered set to efficiently store and remove people. Use a pointer to keep track of the current person and increment it by `K` and mod by size each time.

- [x] [Nested Ranges Check](SortingAndSearching/1144.cpp) - Sort ranges in order by start time primarily, and in reverse order by end time secondarily. Iterate from first to last keeping track of maximum end time, if current end time is less than maximum end time then the current range is nested inside a previous range. Iterate from last to first keeping track of minimum end time, if current end time is greater than minimum end time then a previous range is nested inside current range.

- [x] [Nested Ranges Count](SortingAndSearching/2169.cpp) - Same logic as previous problem, except use ordered set to keep track of end times and use `order_of_key` to find number of end times less than/greater than current end time.

- [x] [Room Allocation](SortingAndSearching/1164.cpp) - Use a min heap priority queue to store an array of end time, counter, and index. Insert rooms by index into priority queue, if the top room ends before the current customer then remove it and insert the current customer into the room, else create a new room for the current customer by incrementing the counter. Once all customers are processed, print the counter and the room number for each customer using the index.

- [x] [Factory Machines](SortingAndSearching/1620.cpp) - Given a time `T`, you can calculate the number of products that can be produced by iterating through all machines and adding `T / V[i]` to the total. Use binary search to find the minimum time `T` such that the total number of products is greater than or equal to `N`.

- [x] [Tasks And Deadlines](SortingAndSearching/1630.cpp) - It is optimal to do the tasks in order of duration from shortest to longest, consider arbitrary short task A, and long task B, and the two orders possible. Furthermore, for the same duration, it is optimal to do the tasks in order of deadline from earliest to latest, pretty self explanatory. Sort the tasks in this order and then iterate through them to calculate the total cost.

- [x] [Reading Books](SortingAndSearching/1631.cpp) - And optimal method is to have person A read the longest book, and the person B read the smaller books in the meantime. Once the longest book is read, Person A just reads the books in order of decreasing length, person B can follow just behind person A. This leads to a total time of either sum of all books, or twice the longest book.

- [x] [Sum Of Three Values](SortingAndSearching/1642.cpp) - `O(N^2)` is allowed, so iterate through all numbers once, and then two pointers on the remaining suffix to find the pair that sums to `X - V[i]`. This triple satisfies as a solution, if they are unique.

- [x] [Sum Of Four Values](SortingAndSearching/1641.cpp) - Store all sums of pairs, along with their original indices. use two pointers on the pairs to find the pair that sums to `X` and that the indices are unique. Iterate once focusing on moving left pointer forward, and once focusing on moving right pointer backward in case of non-unique indices. This is to handle edge cases.

- [x] [Nearest Smaller Values](SortingAndSearching/1645.cpp) - Use a stack to store the previous numbers, and pop off the stack until the top of the stack is smaller than the current number. If the stack is empty, then the nearest smaller value is `0`. Otherwise, the nearest smaller value is the top of the stack.

- [x] [Subarray Sums I](SortingAndSearching/1660.cpp) - Iterate across array, keeping track of current prefix sum, and storing the frequency of all previous prefix sums in a map. If the current prefix sum minus `X` is in the map, then add the frequency to the answer.

- [x] [Subarray Sums II](SortingAndSearching/1661.cpp) - Previous solution had no dependence on positive numbers, so same exact code works for this problem.

- [x] [Subarray Divisibility](SortingAndSearching/1662.cpp) - Similar to previous two problems, except use a map to store the frequency of all previous prefix sums modulo `N`.

- [x] [Subarray Distinct Values](SortingAndSearching/2428.cpp) - Use a two pointers method of iterating through the array, storing frequencies of numbers in a map. If the number of distinct numbers is less than or equal to `K`, then increment the right pointer, else increment the left pointer until the number of distinct numbers is less than or equal to `K`. At each valid iteration, add the size of the subarray to the answer.

- [x] [Array Division](SortingAndSearching/1085.cpp) - Given a maximum subarray sum, you can calculate the number of subarrays necessary in `O(N)` by iterating through the array. Use binary search to find the minimum subarray sum that has a number of subarrays is less than or equal to `K`.

- [x] [Sliding Median](SortingAndSearching/1076.cpp) - Use an ordered set to efficiently query for the median using `find_by_order`. Using a sliding window over the array to add and remove elements from the ordered set.

- [x] [Sliding Cost](SortingAndSearching/1077.cpp) - Use two multisets to represents the window above the median and the window less than or equal to the median. Also keep track of the sum of these multisets. Figure out adding and removing logistics for each multiset. To answer each window for the lower multiset subtract sum of lower multiset from median times size of lower multiset, and add sum of upper multiset minus median times size of upper multiset.

- [x] [Movie Festival II](SortingAndSearching/1632.cpp) - Similar to the previous version, except this time use a multiset to store the end times of the movies currently being watched by the `K` people, and replace the person with the latest end time before the current potential movie with the current potential movie.

- [x] [Maximum Subarray Sum II](SortingAndSearching/1644.cpp) - Calculate all prefix sums, and then iterate through the indices of the array. Store the prefix sums of the indices between `A` and `B` less than the current index in a multiset. Update the answer by subtracting the minimum prefix sum from the current prefix sum, this is the maximum subarray sum ending at the current index. Checking all indices leads to the maximum subarray sum of the entire array.

## Dynamic Programming

- [x] [Dice Combinations](DynamicProgramming/1633.cpp) - The state `DP[i]` will represent the number of ways to get a sum of `i` using the dice. The initial state is `DP[0] = 1` representing one way to get a sum of `0`, and the transition is `DP[i] = sum(DP[i - q])` for `1 <= q <= 6`, representing rolling a `1` throught `6` on the dice. The answer is `DP[N]`.

- [x] [Minimizing Coins](DynamicProgramming/1634.cpp) - The state `DP[i]` will represent the minimum number of coins to get a sum of `i`. The initial state is `DP[0] = 0` representing zero coins to get a sum of `0`, and the transition is `DP[i] = min(DP[i - c] + 1)` representing using a coin of value `c` to get a sum of `i` from the minimum of `i-c`. The answer is `DP[N]`.

- [x] [Coin Combinations I](DynamicProgramming/1635.cpp) - The state `DP[i]` will represent the number of ways to get a sum of `i` using the coins. The initial state is `DP[0] = 1` representing one way to get a sum of `0`, and the transition is `DP[i] = sum(DP[i - c])` for `c` in the coins, representing using a coin of value `c` to get a sum of `i` from the sum of `i-c`. The answer is `DP[N]`.

- [x] [Coin Combinations II](DynamicProgramming/1636.cpp) - The state `DP[i][q]` will represent the number of ways to get a sum of `q` using the first `i` coins. The initial state is `DP[0][0] = 1` representing one way to get a sum of `0` using the first `0` coins, and the transition is `DP[i][q] = DP[i - 1][q] + DP[i][q - c]` for `c` in the coins, representing not using the `i`th coin, or using the `i`th coin. The answer is `DP[N][X]` and this is an example of 0-1 knapsack.

- [x] [Removing Digits](DynamicProgramming/1637.cpp) - The state `DP[i]` will represent the minimum number of steps to get from `i` to `0`. The initial state is `DP[0] = 0` representing zero steps to get from `0` to `0`, and the transition is `DP[i] = min(DP[i - d] + 1)` for `d` in the digits of `i`, representing using a digit of value `d` to get from `i` to `i-d`. The answer is `DP[N]`.

- [x] [Grid Paths](DynamicProgramming/1638.cpp) - The state `DP[i][q]` will represent the number of ways to get to the cell `(i, q)`. The initial state is `DP[0][0] = 1` representing one way to get to the cell `(0, 0)`, and the transition is `DP[i][q] = DP[i - 1][q] + DP[i][q - 1]` representing using the cell above or the cell to the left. Remember to check if the cell is blocked and thus unusable. The answer is `DP[N - 1][N - 1]`.

- [x] [Book Shop](DynamicProgramming/1643.cpp) - The state `DP[i][q]` will represent the maximum number of pages to get with `q` money and `i` books. The initial state is `DP[0][0] = 0` representing zero pages to get with `0` money and `0` books, and the transition is `DP[i][q] = max(DP[i - 1][q - p] + x, DP[i - 1][q])` for `p` in the prices of the books, representing using the `q`th book or not. The answer is `DP[N][X]`.

- [x] [Array Description](DynamicProgramming/1746.cpp) - The state `DP[i][q]` will represent the number of ways to have an array of `i` elements with the last element being `q`. The initial state is `DP[0][i] = 1` if `V[0] = i` (value is set to `i`), or `V[0] = 0` (value can be anything). The transition is `DP[i][q] = sum(DP[i - 1][q - 1], DP[i - 1][q], DP[i - 1][q + 1])` for `q` in the range `[1, M]` representing the previous element being `q - 1`, `q`, or `q + 1`. Only apply the transition if `V[i] = 0` or `V[i] = q` which means placement is valid. The answer is `sum(DP[N - 1][q])` for `q` in the range `[1, M]` representing the different possible last elements.

- [x] [Counting Towers](DynamicProgramming/2413.cpp) - There are two possible ways to build the last layer of the tower. The layer can have two cut/unconnected pieces or two uncut/connected pieces. Let `DP[i][0]` represent number of ways to build tower given last layer is cut, and `DP[i][0]` representing uncut. The initial state is `DP[0][0] = 1` and `DP[0][1] = 1` representing one way to build a tower of height `0` with the last layer cut or uncut. The transition is `DP[i][0] = DP[i - 1][1] + 4 * DP[i - 1][0]` and `DP[i][1] = DP[i - 1][0] + 2 * DP[i - 1][1]` representing the different ways to build the last layer. The cut pieces can be combined 4 different ways with an cut layer below it, but only once with an uncut layer. The uncit pieces can be combined once with a cut layer below it, or twice with an uncut layer. The answer is `DP[N][0] + DP[N][1]`.

- [x] [Edit Distance](DynamicProgramming/1639.cpp) - Given strings `S` and `T`, `DP[i][q]` represents edit distance between `S[0..i]` and `T[0..q]`. The initial state is `DP[0][0] = 0` representing the edit distance between two empty strings. The transition is `DP[i][q] = min(DP[i - 1][q] + 1, DP[i][q - 1] + 1, DP[i - 1][q - 1] + (S[i] != T[q]))` representing the different ways to edit the strings. The first way is deleting a character from the substring of `T`, the second way is deleting a character from the substring of `S`, and the third way is replacing a character in the substring of `S` with a character in the substring of `T` if needed. The answer is `DP[N][M]`.

- [x] [Rectangle Cutting](DynamicProgramming/1744.cpp) - The state `DP[i][q]` represents minimum number of moves to cut a rectangle of size `i x q` into a square. The initial state is `DP[i][i] = 0` representing zero moves to cut a rectangle of size `i x i` into a square. The transition is `DP[i][q] = min(DP[i - j][q] + DP[j][q] + 1, DP[i][q - j] + DP[i][j] + 1)` for `j` in the range `[1, i - 1]` representing the different ways to cut the rectangle. The first way is cutting the rectangle horizontally, and the second way is cutting the rectangle vertically. The answer is `DP[N][M]`.

- [x] [Money Sums](DynamicProgramming/1745.cpp) - The state `DP[i][q]` represents if it is possible to create a sum of `q` using the first `i` coins. The initial state is `DP[0][0] = true` representing it is possible to create a sum of `0` using `0` coins. The transition is `DP[i][q] = DP[i - 1][q] || DP[i - 1][q - V[i]]` representing using the `i`th coin or not. The answer are the `DP[N][q]` that are true.

- [x] [Removal Game](DynamicProgramming/1097.cpp) - The state `DP[i][q]` represents the maximum score difference between the first and second player given the coins in the range from `i` to `q`. The initial state is `DP[i][i] = V[i]` representing the maximum score difference between the first and second player given the coin `i`, as the first player would always take this coin. The transition is `DP[i][q] = max(V[i] - DP[i + 1][q], V[q] - DP[i][q - 1])` representing the different ways to take a coin. The first way is the first player takes the `i`th coin and the second player, now being the first player of `i+1` to `q` coins plays optimally. The second way is the first player takes the `q`th coin and the second player, now being the first player of `i` to `q-1` coins plays optimally. The maximum score difference for player one is `DP[0][N - 1]`, so the maximum score is `(sum(V) + DP[0][N - 1]) / 2`. Iterate backwards over `i` and use two pointers, incrementing the right side to iterate over `q` to fill the DP table.

- [x] [Two Sets II](DynamicProgramming/1093.cpp) - This problem is equivalent to finding the numbers of ways to sum to `N/2` using the numbers given, the unused numbers can be used to sum to `N/2` as well. The state `DP[i][q]` represents the number of ways to create a sum of `q` using the first `i` numbers. The initial state is `DP[0][0] = 1` representing one way to create a sum of `0` using `0` numbers. The transition is `DP[i][q] = DP[i - 1][q] + DP[i - 1][q - i]` representing using the `i`th number or not. The answer is `DP[N][sum(V) / 2] / 2` to prevent double counting, remember to use division under modulo.

- [x] [Increasing Subsequence](DynamicProgramming/1145.cpp) - We will represent the optimal solution as a multiset. Iterate through the numbers. If the number is greater than the end of the multiset, then directly insert it into the multiset. Otherwise, find the smallest number in the multiset that is greater than the current number and replace it with the current number. The answer is the size of the multiset. This works because if the multiset is the optimal solution before the current index, then adding a larger number and increasing the subsequence size is possible, and replacing a number with a smaller number will not decrease the subsequence size, but instead potentially allow for another number to be added later.

- [x] [Projects](DynamicProgramming/1140.cpp) - This has a simple transition of the current day being the max of yesterday, or the max of the day before the start of the project plus the value of the project. The complexity comes from having to do index compression because we can not iterate across the range `10^9`. Index compress and iterate across the compression, instead of the whole range.

- [x] [Elevator Rides](DynamicProgramming/1653.cpp) - The state `DP[i][0]` represents minimum number of elevator rides needed to transport the subset of people in the bitwise representation of `i`, `DP[i][1]` represents the weight of the last elevator ride of that subset. The transition is for each person in the subset, get the state without everyone else, and then attempt to add this person to the last elevator ride updating accordingly. Make the current state the minimum of these states. The answer is `DP[2^N - 1][0]`.

- [ ] [Counting Tilings](DynamicProgramming/2181.cpp)

- [ ] [Counting Numbers](DynamicProgramming/2220.cpp)

## Graph Algorithms

- [x] [Counting Rooms](GraphAlgorithms/1192.cpp) - Set up a 2D array where walls are true, and floors are false. Then iterate through whole grid, if the current cell is a floor, then do a DFS to mark all connected floors as visited. Increment the answer by one, and continue iterating through the grid.

- [x] [Labyrinth](GraphAlgorithms/1193.cpp) - Set up a 2D array where walls are true, and floors are false. Start a BFS from the starting cell, and keep track of the previous cell for each cell. When the BFS reaches the end cell, then reconstruct the path by following the previous cell for each cell if possible.

- [x] [Building Roads](GraphAlgorithms/1666.cpp) - We need to connect all the separate connected components of this graph. We can simulate these connected components by adding and uniting a DSU. We can connect every component to the component containing the first city like so. Iterate through the cities, and if the current city is not in the same component as the first city, then connect them and add the road to the answer. The answer is the number of roads added, and the roads added.

- [x] [Message Route](GraphAlgorithms/1667.cpp) - A little overkill, but we can use Dijkstra's starting from the start node. When we add a node to the priority queue, we can keep track of the previous node. When we reach the end node, we can reconstruct the path by following the previous node for each node if possible. The answer is the number of nodes in the path, and the path.

- [x] [Building Teams](GraphAlgorithms/1668.cpp) - Since there are only two colors, we can greedily color the graph using a DFS. For each uncolored node, start a DFS with a certain color and color each child node the opposite color if possible. If we reach a node containing the same color as the parent, then we can not color the graph. Otherwise, we can color the graph. The answer is the color of each node.

- [x] [Round Trip](GraphAlgorithms/1669.cpp) - For each unvisited node, start a DFS and keep track of the previous node. If we reach a node that is already visited, then we have found a cycle. We can reconstruct the cycle by following the previous node for each node if possible. The answer is the number of nodes in the cycle + 1, and the cycle with one node repeated.

- [x] [Monsters](GraphAlgorithms/1194.cpp) - Use BFS to find the shortest distance from a monster to each cell. Then use BFS to find the shortest distance from the starting cell to each cell along with storing the previous node. Only move to a new node if the human distance is smaller than the monster distance. If we reach the end cell, then reconstruct the path by following the previous node for each node if possible. The answer is the number of nodes in the path, and the path.

- [x] [Shortest Routes I](GraphAlgorithms/1671.cpp) - Use Dijkstra's algorithm to find the shortest distance from the starting node to each node. The answer is the distance to each node.

- [x] [Shortest Routes II](GraphAlgorithms/1672.cpp) - Use Floyd-Warshall's algorithm to find the shortest distance from each node to each node. The answer is the distance from each node to each node in the queries.

- [ ] [High Score](GraphAlgorithms/1673.cpp)

- [ ] [Flight Discount](GraphAlgorithms/1195.cpp)

- [ ] [Cycle Finding](GraphAlgorithms/1197.cpp)

- [ ] [Flight Routes](GraphAlgorithms/1196.cpp)

- [ ] [Round Trip II](GraphAlgorithms/1678.cpp)

- [ ] [Course Schedule](GraphAlgorithms/1679.cpp)

- [ ] [Longest Flight Route](GraphAlgorithms/1680.cpp)

- [ ] [Game Routes](GraphAlgorithms/1681.cpp)

- [ ] [Investigation](GraphAlgorithms/1202.cpp)

- [ ] [Planets Queries I](GraphAlgorithms/1750.cpp)

- [ ] [Planets Queries II](GraphAlgorithms/1160.cpp)

- [ ] [Planets Cycles](GraphAlgorithms/1751.cpp)

- [ ] [Road Reparation](GraphAlgorithms/1675.cpp)

- [ ] [Road Construction](GraphAlgorithms/1676.cpp)

- [ ] [Flight Routes Check](GraphAlgorithms/1682.cpp)

- [ ] [Planets and Kingdoms](GraphAlgorithms/1683.cpp)

- [ ] [Giant Pizza](GraphAlgorithms/1684.cpp)

- [ ] [Coin Collector](GraphAlgorithms/1686.cpp)

- [ ] [Mail Delivery](GraphAlgorithms/1691.cpp)

- [ ] [De Bruijn Sequence](GraphAlgorithms/1692.cpp)

- [ ] [Teleporters Path](GraphAlgorithms/1693.cpp)

- [ ] [Hamiltonian Flights](GraphAlgorithms/1690.cpp)

- [ ] [Knights Tour](GraphAlgorithms/1689.cpp)

- [ ] [Download Speed](GraphAlgorithms/1694.cpp)

- [ ] [Police Chase](GraphAlgorithms/1695.cpp)

- [ ] [School Dance](GraphAlgorithms/1696.cpp)

- [ ] [Distinct Routes](GraphAlgorithms/1711.cpp)

## Range Queries

- [ ] [Static Range Sum Queries](RangeQueries/1646.cpp)

- [ ] [Static Range Minimum Queries](RangeQueries/1647.cpp)

- [ ] [Dynamic Range Sum Queries](RangeQueries/1648.cpp)

- [ ] [Dynamic Range Minimum Queries](RangeQueries/1649.cpp)

- [ ] [Range Xor Queries](RangeQueries/1650.cpp)

- [ ] [Range Update Queries](RangeQueries/1651.cpp)

- [ ] [Forest Queries](RangeQueries/1652.cpp)

- [ ] [Hotel Queries](RangeQueries/1143.cpp)

- [ ] [List Removals](RangeQueries/1749.cpp)

- [ ] [Salary Queries](RangeQueries/1144.cpp)

- [ ] [Prefix Sum Queries](RangeQueries/2166.cpp)

- [ ] [Pizzeria Queries](RangeQueries/2206.cpp)

- [ ] [Subarray Sum Queries](RangeQueries/1190.cpp)

- [ ] [Distinct Values Queries](RangeQueries/1734.cpp)

- [ ] [Increasing Array Queries](RangeQueries/2416.cpp)

- [ ] [Forest Queries II](RangeQueries/1739.cpp)

- [ ] [Range Updates and Sums](RangeQueries/1735.cpp)

- [ ] [Polynomial Queries](RangeQueries/1736.cpp)

- [ ] [Range Queries and Copies](RangeQueries/1737.cpp)

## Tree Algorithms

- [ ] [Subordinates](TreeAlgorithms/1674.cpp)

- [ ] [Tree Matching](TreeAlgorithms/1130.cpp)

- [ ] [Tree Diameter](TreeAlgorithms/1131.cpp)

- [ ] [Tree Distances I](TreeAlgorithms/1132.cpp)

- [ ] [Tree Distances II](TreeAlgorithms/1133.cpp)

- [ ] [Company Queries I](TreeAlgorithms/1687.cpp)

- [ ] [Company Queries II](TreeAlgorithms/1688.cpp)

- [ ] [Distance Queries](TreeAlgorithms/1135.cpp)

- [ ] [Counting Paths](TreeAlgorithms/1136.cpp)

- [ ] [Subtree Queries](TreeAlgorithms/1137.cpp)

- [ ] [Path Queries](TreeAlgorithms/1138.cpp)

- [ ] [Path Queries II](TreeAlgorithms/2134.cpp)

- [ ] [Distinct Colors](TreeAlgorithms/1139.cpp)

- [ ] [Finding A Centroid](TreeAlgorithms/2079.cpp)

- [ ] [Fixed-Length Paths I](TreeAlgorithms/2080.cpp)

- [ ] [Fixed-Length Paths II](TreeAlgorithms/2081.cpp)

## Mathematics

- [x] [Josephus Queries](Mathematics/2164.cpp) - First observation is that if `2*K <= N` then the answer is `2*K`, and if `2*K == N+1` then the answer is `1` always. Now consider if these two conditions are not met, in the even case that means we have the remaining sequence of `1, 3, ...`, and we are trying to find the `K-(N+1/2)`th number, this is equivalent to the josephus query of `N/2, K-(N+1/2)` mapped by `2*X-1`. In the odd case we have the remaining sequence of `3, 5, ...`, and we are trying to find the `K-(N+1/2)`th number, this is equivalent to the josephus query of `N/2, K-(N+1/2)` mapped by `2*X+1`. Thus we can recursively solve this problem following the above logic.

- [x] [Exponentiation](Mathematics/1095.cpp) - Basic application of the binary exponentiation algorithm. Remember to use modular exponentiation to prevent overflow.

- [x] [Exponentiation II](Mathematics/1096.cpp) - By Fermat's little theorem, `a^(p-1) = 1 mod p` if `a` and `p` are coprime. Thus `a^b^c mod p = a^(b^c mod p-1) mod p`, which can be calculated using binary exponentiation and modular exponentiation like above.

- [ ] [Counting Divisors](Mathematics/1713.cpp)

- [ ] [Common Divisors](Mathematics/1081.cpp)

- [ ] [Sum of Divisors](Mathematics/1082.cpp)

- [ ] [Divisor Analysis](Mathematics/2182.cpp)

- [ ] [Prime Multiples](Mathematics/2185.cpp)

- [ ] [Counting Coprime Pairs](Mathematics/2417.cpp)

- [x] [Binomial Coefficients](Mathematics/1079.cpp) - Since the binomial coefficient formula includes multiplication and division of factorials, we can precompute the factorials and their inverses under modulo using modular exponentiation. Then we can calculate the binomial coefficient using the formula given.

- [x] [Creating Strings II](Mathematics/1715.cpp) - We can order all the letters of a size `N` string in a total of `N!` ways. However, if we have for example `5` copies of `a` then we can exchange them in `5!` ways and still have the same string. Thus we can divide `N!` by the product of the factorials of the number of copies of each letter to get the answer.
Use modular inverse and precomputation.

- [x] [Distributing Apples](Mathematics/1716.cpp) - We can use the stars and bars method to calculate the number of ways to distribute `K` apples to `N` people. This method entails having a string of `K` stars and `N-1` bars, and counting the number of ways to rearrange them. This is equivalent to `N+K-1 choose N-1`. Use modular inverse and precomputation.

- [x] [Christmas Party](Mathematics/1717.cpp) - If we consider each child as an index and their gift as a number, then our goal is to permute the standard permutation such that no index is equivalent to its value. This is the derangement problem, and the answer is recursively defined as `D(n) = (n-1)(D(n-1)+D(n-2))`.

- [x] [Bracket Sequences I](Mathematics/2064.cpp) - If we consider the first open bracket placed at position `0`, and the closing bracket at position `i`. Then we can split into two recursive bracket sequences, one inside the first pair, and one after it. Multiply these two calls and sum over our index `i`. When written down this formula becomes the Catalan numbers, which can be calculated using modular inverse and precomputation.

- [ ] [Bracket Sequences II](Mathematics/2187.cpp)

- [x] [Counting Necklaces](Mathematics/2209.cpp) - This is an application of Burnside's Lemma, which basically says to find the number of unique elements under a set of transformations, add up the number of unique elements under each transformation and divide by the number of transformations. In this case, there are `N` transformations of shifts from `0` to `N-1`. If we consider a starting position and a given shift, each shift will lead to a chain of connected positions that will be the same color for unique elements. These connected positions continue until they reach the `lcm(i, N) = i * N / gcd(i, N)`, it will reach this by moving `i` each step, and then repeat. Thus each connected chain is length `N / gcd(i, N)`, thus there needs to be `gcd(i, N)` chains to cover every position. Each chain can be any color, so there are `M^gcd(i, N)` options for each shift. Add up all options and then divide by `N` under modulo.

- [x] [Counting Grids](Mathematics/2210.cpp) - This is another application of Burnside's Lemma. This time the number of transformations is `4`, `0`, `90`, `180`, and `270` degrees. The first one allows every square to be colored independently, so we have `2^(N^2)` options. The second one causes cycles of lengths `4`, except for the middle element if the size is odd. We have `N * N / 4` distinct colors to choose, and the middle one adds `N%2`, so we get a total of `2^(N*N/4 + N%2)` options. The third one causes cycles of length `2`, and the same middle problem, so we have `2^(N*N/2 + N%2)` options. The final one is exactly the second one but in the opposite direction, so it has the same count. Thus we add all these up and divide by `4` under modulo and that is our answer.

- [ ] [Fibonacci Numbers](Mathematics/1722.cpp)

- [ ] [Throwing Dice](Mathematics/1096.cpp)

- [ ] [Graph Paths I](Mathematics/1723.cpp)

- [ ] [Graph Paths II](Mathematics/1724.cpp)

- [ ] [Dice Probability](Mathematics/1725.cpp)

- [ ] [Moving Robots](Mathematics/1726.cpp)

- [ ] [Candy Lottery](Mathematics/1727.cpp)

- [ ] [Inversion Probability](Mathematics/1728.cpp)

- [ ] [Stick Game](Mathematics/1729.cpp)

- [ ] [Nim Game I](Mathematics/1730.cpp)

- [ ] [Nim Game II](Mathematics/1098.cpp)

- [ ] [Stair Game](Mathematics/1099.cpp)

- [ ] [Grundy's Game](Mathematics/2207.cpp)

- [ ] [Another Game](Mathematics/2208.cpp)

## String Algorithms

- [ ] [Word Combinations](StringAlgorithms/1731.cpp)

- [ ] [String Matching](StringAlgorithms/1753.cpp)

- [ ] [Finding Borders](StringAlgorithms/1732.cpp)

- [ ] [Finding Periods](StringAlgorithms/1733.cpp)

- [ ] [Minimal Rotation](StringAlgorithms/1110.cpp)

- [ ] [Longest Palindrome](StringAlgorithms/1111.cpp)

- [ ] [Required Substring](StringAlgorithms/1112.cpp)

- [ ] [Palindrome Queries](StringAlgorithms/2420.cpp)

- [ ] [Finding Patterns](StringAlgorithms/2102.cpp)

- [ ] [Counting Patterns](StringAlgorithms/2103.cpp)

- [ ] [Pattern Positions](StringAlgorithms/2104.cpp)

- [ ] [Distinct Substrings](StringAlgorithms/2105.cpp)

- [ ] [Repeating Substrings](StringAlgorithms/2106.cpp)

- [ ] [String Functions](StringAlgorithms/2107.cpp)

- [ ] [Substring Order I](StringAlgorithms/2108.cpp)

- [ ] [Substring Order II](StringAlgorithms/2109.cpp)

- [ ] [Substring Distribution](StringAlgorithms/2110.cpp)

## Geometry

- [ ] [Point Location Test](Geometry/2189.cpp)

- [ ] [Line Segment Intersection](Geometry/2190.cpp)

- [ ] [Polygon Area](Geometry/2191.cpp)

- [ ] [Point In Polygon](Geometry/2192.cpp)

- [ ] [Polygon Lattice Points](Geometry/2193.cpp)

- [ ] [Minimum Euclidean Distance](Geometry/2194.cpp)

- [ ] [Convex Hull](Geometry/2195.cpp)

## Advanced Techniques

- [ ] [Meet In The Middle](AdvancedTechniques/1628.cpp)

- [ ] [Hamming Distance](AdvancedTechniques/2136.cpp)

- [ ] [Beautiful Subgrids](AdvancedTechniques/2137.cpp)

- [ ] [Reachable Nodes](AdvancedTechniques/2138.cpp)

- [ ] [Reachability Queries](AdvancedTechniques/2143.cpp)

- [ ] [Cut And Paste](AdvancedTechniques/2072.cpp)

- [ ] [Substring Reversals](AdvancedTechniques/2073.cpp)

- [ ] [Reversals And Sums](AdvancedTechniques/2074.cpp)

- [ ] [Necessary Roads](AdvancedTechniques/2076.cpp)

- [ ] [Necessary Cities](AdvancedTechniques/2077.cpp)

- [ ] [Eulerian Subgraphs](AdvancedTechniques/2078.cpp)

- [ ] [Monster Game I](AdvancedTechniques/2084.cpp)

- [ ] [Monster Game II](AdvancedTechniques/2085.cpp)

- [ ] [Subarray Squares](AdvancedTechniques/2086.cpp)

- [ ] [Houses And Schools](AdvancedTechniques/2087.cpp)

- [ ] [Knuth Division](AdvancedTechniques/2088.cpp)

- [ ] [Apples And Bananas](AdvancedTechniques/2111.cpp)

- [ ] [One Bit Positions](AdvancedTechniques/2112.cpp)

- [ ] [Signal Processing](AdvancedTechniques/2113.cpp)

- [ ] [New Road Queries](AdvancedTechniques/2101.cpp)

- [ ] [Dynamic Connectivity](AdvancedTechniques/2133.cpp)

- [ ] [Parcel Delivery](AdvancedTechniques/2121.cpp)

- [ ] [Task Assignment](AdvancedTechniques/2129.cpp)

- [ ] [Distinct Routes II](AdvancedTechniques/2130.cpp)

## Additional Problems

- [ ] [Shortest Subsequence](AdditionalProblems/1087.cpp)

- [ ] [Counting Bits](AdditionalProblems/1146.cpp)

- [ ] [Swap Game](AdditionalProblems/1670.cpp)

- [ ] [Prufer Code](AdditionalProblems/1134.cpp)

- [ ] [Acyclic Graph Edges](AdditionalProblems/1756.cpp)

- [ ] [Strongly Connected Edges](AdditionalProblems/2177.cpp)

- [ ] [Even Outdegree Edges](AdditionalProblems/2179.cpp)

- [ ] [Multiplication Table](AdditionalProblems/2422.cpp)

- [ ] [Advertisement](AdditionalProblems/1142.cpp)

- [ ] [Special Substrings](AdditionalProblems/2186.cpp)

- [ ] [Permutation Inversions](AdditionalProblems/2229.cpp)

- [ ] [Maximum Xor Subarray](AdditionalProblems/1655.cpp)

- [ ] [Movie Festival Queries](AdditionalProblems/1664.cpp)

- [ ] [Chess Tournament](AdditionalProblems/1697.cpp)

- [ ] [Tree Traversals](AdditionalProblems/1702.cpp)

- [ ] [Network Renovation](AdditionalProblems/1704.cpp)

- [ ] [Graph Girth](AdditionalProblems/1707.cpp)

- [ ] [Intersection Points](AdditionalProblems/1740.cpp)

- [ ] [Inverse Inversions](AdditionalProblems/2214.cpp)

- [ ] [Monotone Subsequences](AdditionalProblems/2215.cpp)

- [ ] [String Reorder](AdditionalProblems/1743.cpp)

- [ ] [Stack Weights](AdditionalProblems/2425.cpp)

- [ ] [Pyramid Array](AdditionalProblems/1747.cpp)

- [ ] [Increasing Subsequence II](AdditionalProblems/1748.cpp)

- [ ] [String Removals](AdditionalProblems/1149.cpp)

- [ ] [Bit Inversions](AdditionalProblems/1188.cpp)

- [ ] [Xor Pyramid](AdditionalProblems/2419.cpp)

- [ ] [Writing Numbers](AdditionalProblems/1086.cpp)

- [ ] [String Transform](AdditionalProblems/1113.cpp)

- [ ] [Letter Pair Move Game](AdditionalProblems/2427.cpp)

- [ ] [Maximum Building I](AdditionalProblems/1147.cpp)

- [ ] [Sorting Methods](AdditionalProblems/1162.cpp)

- [ ] [Cyclic Array](AdditionalProblems/1191.cpp)

- [ ] [List Of Sums](AdditionalProblems/2414.cpp)

- [ ] [Increasing Array II](AdditionalProblems/2132.cpp)

- [ ] [Food Division](AdditionalProblems/1189.cpp)

- [ ] [Bit Problem](AdditionalProblems/1654.cpp)

- [ ] [Swap Round Sorting](AdditionalProblems/1698.cpp)

- [ ] [Binary Subsequences](AdditionalProblems/2430.cpp)

- [ ] [Tree Isomorphism I](AdditionalProblems/1700.cpp)

- [ ] [Counting Sequences](AdditionalProblems/2228.cpp)

- [ ] [Critical Cities](AdditionalProblems/1703.cpp)

- [ ] [School Excursion](AdditionalProblems/1706.cpp)

- [ ] [Coin Grid](AdditionalProblems/1709.cpp)

- [ ] [Robot Path](AdditionalProblems/1742.cpp)

- [ ] [Programmers And Artists](AdditionalProblems/2426.cpp)

- [ ] [Course Schedule II](AdditionalProblems/1757.cpp)

- [ ] [Removing Digits II](AdditionalProblems/2174.cpp)

- [ ] [Coin Arrangement](AdditionalProblems/2180.cpp)

- [ ] [Counting Bishops](AdditionalProblems/2176.cpp)

- [ ] [Grid Puzzle I](AdditionalProblems/2432.cpp)

- [ ] [Grid Puzzle II](AdditionalProblems/2131.cpp)

- [ ] [Empty String](AdditionalProblems/1080.cpp)

- [ ] [Grid Paths](AdditionalProblems/1078.cpp)

- [ ] [Bit Substrings](AdditionalProblems/2115.cpp)

- [ ] [Reversal Sorting](AdditionalProblems/2075.cpp)

- [ ] [Counting Reorders](AdditionalProblems/2421.cpp)

- [ ] [Book Shop II](AdditionalProblems/1159.cpp)

- [ ] [Network Breakdown](AdditionalProblems/1677.cpp)

- [ ] [Visiting Cities](AdditionalProblems/1203.cpp)

- [ ] [Missing Coin Sum Queries](AdditionalProblems/2184.cpp)

- [ ] [Number Grid](AdditionalProblems/1157.cpp)

- [ ] [Maximum Building II](AdditionalProblems/1148.cpp)

- [ ] [Filing Trominos](AdditionalProblems/2423.cpp)

- [ ] [Stick Division](AdditionalProblems/1161.cpp)

- [ ] [Coding Company](AdditionalProblems/1165.cpp)

- [ ] [Flight Route Requests](AdditionalProblems/1699.cpp)

- [ ] [Two Stacks Sorting](AdditionalProblems/2402.cpp)

- [ ] [Tree Isomorphism II](AdditionalProblems/1701.cpp)

- [ ] [Forbidden Cities](AdditionalProblems/1705.cpp)

- [ ] [Area Of Rectangles](AdditionalProblems/1741.cpp)

- [ ] [Grid Completion](AdditionalProblems/2429.cpp)

- [ ] [Creating Offices](AdditionalProblems/1752.cpp)

- [ ] [Permutations II](AdditionalProblems/1075.cpp)

- [ ] [Functional Graph Distribution](AdditionalProblems/2415.cpp)

- [ ] [New Flight Routes](AdditionalProblems/1685.cpp)

- [ ] [Grid Path Construction](AdditionalProblems/2418.cpp)
