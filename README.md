# Leetcode-3123.-Find-Edges-in-Shortest-Paths
# 🚀 Dijkstra Path Edge Checker

This repository contains a C++ implementation to **identify edges that lie on any shortest path** from the source node `0` to the destination node `n-1` in an undirected, weighted graph.

---

## 🧩 Problem Statement
Given a graph with `n` nodes and weighted edges, determine for each edge if it lies on **any shortest path** from node `0` to node `n-1`.

---

## ✅ Example
### Input:
```cpp
n = 5
edges = {{0,1,1}, {1,2,1}, {0,2,2}, {2,3,1}, {3,4,1}, {2,4,2}}
```
### Output:
```cpp
[true, true, true, true, true, true]
```

---

## ⚙️ Approach
We apply **Dijkstra's algorithm** twice:
1. From the **source (0)** to all nodes
2. From the **destination (n-1)** to all nodes

Then, for each edge `(u, v, cost)`:
- Check if going from `0 -> u -> v -> n-1` or `0 -> v -> u -> n-1` gives the total shortest path cost.

If either case holds, the edge lies on some shortest path and is marked `true`.

---

## 💡 Key Concepts
- **Dijkstra's Algorithm** with a Min-Heap (Priority Queue)
- **Edge validation by reconstructing total cost** of path from both ends

---

## ⏱️ Time & Space Complexity
- **Time Complexity:** O(E * log V)
- **Space Complexity:** O(V + E)

Where:
- `V` = number of vertices
- `E` = number of edges

---

## 📁 File Structure
```
├── DijkstraPathCheck.cpp      # Complete implementation with comments
├── README.md                  # Problem overview and explanation
```

---

## 🛠️ How to Run
Use a C++ compiler like `g++`:
```bash
g++ DijkstraPathCheck.cpp -o solution
./solution
```

You may include your input in a `main()` function or use it in online judges.

---

## 👨‍💻 Author - Ridham Garg [Irythmgarg]
Made with precision to analyze shortest paths efficiently 🚀

