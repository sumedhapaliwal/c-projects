# 📚 **Tourist Handling System**

## 🚀 **Project Goals (as per the given assignment)**
This project implements a **Tourist Handling System** for managing trip bookings to Bali, Indonesia, using **Singly Linked Lists** in C. The system handles:
- **Booking** tourists based on the order of registration in March.
- **Accommodating** the first **N** tourists on the **TRIP** list.
- Managing a **WAITLIST** for additional bookings.
- **Cancelling** bookings and automatically shifting tourists from the waitlist when vacancies arise.

The system reads booking data from a file `EASYTRIP.txt` and supports operations like adding bookings, cancelling bookings, and displaying lists.

## ⚙️ **How to Run**

### 1. **Compile the Code**
gcc -o tourist_system main.c

### 2. **Prepare the Input File**
Ensure `EASYTRIP.txt` is present in the same directory with the required data.

### 3. **Run the Program**
./tourist_system

### 4. **Sample Input (`EASYTRIP.txt`) Format**
```
5  
1 vikas jain 3  
1 ram gupta 6  
1 alia sen 14  
1 ivaan shukla 9  
1 jyoti deka 11  
3  
1 mili patel 16  
2 ram gupta  
1 vidhu reddy 7  
1 zoya ahsan 12  
2 vikas jain  
4  
1 suraj lal 17  
8  
2 ivaan shukla  
2 alia sen  
4  
```

### 5. **Sample Output**
```
BOOKING 3 vikas jain 6 ram gupta 9 ivaan shukla 11 jyoti deka 14 alia sen  
TRIP 7 vidhu reddy 9 ivaan shukla 11 jyoti deka 12 zoya ahsan 14 alia sen  
WAITLIST 16 mili patel 17 suraj lal  
TRIP 7 vidhu reddy 11 jyoti deka 12 zoya ahsan 16 mili patel 17 suraj lal
```

---

## 📋 **Features**
- Dynamic management of bookings, cancellations, and waitlist.
- Efficient memory handling with linked list operations.
- Clear and organized output for easy tracking.
