# Logistics-Delivery-App
# 🚚 Logistics Delivery App – Route Optimization using Graph (CRUD)

## 👥 Team Members
- B. Meganadh Reddy
- R. Koushik Sriram

---

## 🎯 Project Title
Route Optimization System for Logistics Delivery using Graph Data Structure in C

---

## ❓ Problem Statement
In logistics and delivery systems, finding the most efficient route between locations is crucial for reducing time, cost, and fuel consumption. This project implements a graph-based system in C to manage delivery routes and perform CRUD operations on locations and connections.

---

## 🌍 Real-World Application
This system simulates real-world delivery services such as:
- Amazon Delivery Network  
- Swiggy/Zomato Delivery Routing  
- Courier and Transport Systems  

It helps in:
- Optimizing delivery paths  
- Managing dynamic routes  
- Efficient data handling of locations  

---

## 🧱 Data Structure Used
- **Graph (Adjacency List Representation)**
- Each node represents a location
- Each edge represents a route between locations

---

## ⚙️ Features (CRUD Operations)

### ✅ Create
- Add a new location (node)
- Add a route between locations (edge)

### 📖 Read
- Display all locations and routes
- Show adjacency list representation

### ✏️ Update
- Modify location details
- Update route distance/weight

### ❌ Delete
- Remove a location
- Remove a route

### 🔍 Search
- Find a specific location
- Check if a route exists

---

## 🧠 Algorithm Explanation

### ➤ Add Location
1. Allocate memory using `malloc`
2. Create a new node
3. Insert into graph

### ➤ Add Route
1. Select source and destination
2. Create edge
3. Add to adjacency list

### ➤ Delete Location
1. Find node
2. Remove all connected edges
3. Free memory using `free`

### ➤ Display Graph
1. Traverse all nodes
2. Print connected edges

### ➤ Route Optimization (Optional if implemented)
- Shortest path using Dijkstra’s Algorithm / BFS

---

## 🏗️ System Design
- Menu-driven program
- Modular functions
- Graph using adjacency list
- Dynamic memory allocation (`malloc`, `free`)
- Structured programming using `struct`

---

## 💻 Technologies Used
- Programming Language: C
- Compiler: GCC
- Platform: Windows/Linux

---

## ▶️ Compilation & Execution

```bash
gcc main.c -o project
./project
