🎯 Features
✅ Uses real Hyderabad Metro stations.
✅ Uses real distances in kilometers.
✅ Implements Dijkstra’s algorithm for shortest path.
✅ Modularized with separate header and source files.
✅ Uses Makefile for easy compilation.

✨ Features
✔ Shortest Path & Distance
✔ Real Hyderabad Metro Data
✔ Dijkstra's Algorithm
✔ Modular Code & Makefile


complie without make 
  g++ -std=c++17 -Wall -Wextra -Iinclude src/stations.cpp src/connections.cpp src/main.cpp -o metro
run command
  ./metro.exe



# Hyderabad Metro Shortest Path Finder

This project implements the **Hyderabad Metro Shortest Path Finder** using **Dijkstra’s algorithm** to calculate the shortest distance between metro stations. It is written in **C++** and follows a modular approach for better maintainability.

---

![Hyderabad Metro Map](image.png)

---

## 🎯 Features
✅ Uses real Hyderabad Metro stations.  
✅ Uses real distances in kilometers.  
✅ Implements Dijkstra’s algorithm for shortest path.  
✅ Modularized with separate header and source files.  
✅ Uses Makefile for easy compilation.  

## ✨ Additional Highlights
✔ Shortest Path & Distance Calculation  
✔ Real Hyderabad Metro Data  
✔ Efficient Dijkstra's Algorithm  
✔ Well-Structured Modular Code  
✔ Simple Compilation & Execution  

---

## 🚀 Installation & Usage

### 1️⃣ Compilation Without Makefile
To compile the project without using `make`, run:
```sh
 g++ -std=c++17 -Wall -Wextra -Iinclude src/stations.cpp src/connections.cpp src/main.cpp -o metro
```

### 2️⃣ Run the Program
Once compiled, execute the program:
```sh
 ./metro.exe
```

---

## 🛠 Technologies Used
- **C++ (C++17 Standard)**
- **Dijkstra’s Algorithm** for shortest path calculation
- **Makefile** for easy compilation (optional)


---

## 💡 How It Works
- The program loads **real Hyderabad Metro station data**.
- It constructs a **graph representation** of metro stations and distances.
- **Dijkstra's algorithm** is used to find the **shortest path** between stations.
- The program displays the **shortest route** along with the **total distance**.

---

## 📌 Contributing
Feel free to contribute by improving the code, adding new features, or fixing bugs!

---

## 📄 License
This project is open-source and available under the **MIT License**.

---

🚆 **Enjoy finding the shortest routes in Hyderabad Metro!**

## Author   
Nenaavath Yugender   
**IIT Madras**
