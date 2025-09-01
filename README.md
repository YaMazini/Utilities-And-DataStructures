# 🛠️ Utilities-And-DataStructures

> A comprehensive collection of reusable C++ class libraries featuring custom data structures built from scratch, advanced utility frameworks, and specialized tools for real-world applications.

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C++-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B11)
[![Purpose](https://img.shields.io/badge/purpose-Educational%20%26%20Production-green.svg)]()
[![Architecture](https://img.shields.io/badge/design-OOP%20%26%20Templates-orange.svg)]()

## 🏗️ Multi-Library Architecture

Built from scratch to master **OOP concepts**, improve **programming logic**, and create **production-ready libraries** that extend C++'s capabilities. This phase represents a crucial part of **foundation building** in software development. These libraries serve both **educational purposes** and **real-world applications**, demonstrating enterprise-grade software engineering principles with emphasis on **reusability concepts**, **logic improvement**, **pointer manipulation and memory management** including dynamic memory allocation, and **hands-on practice with data structures** to understand how to build your own custom implementations from the ground up.

## 📁 File Organization

```
Utilities-And-DataStructures/
├── 📊 D.S Libs/
│   ├── Doubly Linked List Lib/
│   ├── Dynamic Array Lib/
│   ├── Queue Arr Lib/
│   ├── Queue Lib/
│   ├── Stack Arr Lib/
│   ├── Stack Lib/
│   ├── Ticket System/
│   └── Undo-Redo Lib/
├── 📅 Date Lib/
│   ├── Date Library Project.cpp
│   ├── clsDate.h
│   └── clsString.h
├── 🔍 Input & Validation Lib/
│   ├── Input & Validation Library.cpp
│   ├── clsDate.h
│   ├── clsInputValidate.h
│   └── clsString.h
├── 📊 Period Lib/
│   ├── PeriodClass.cpp
│   ├── clsDate.h
│   ├── clsPeriod.h
│   └── clsString.h
├── 🔤 String Lib/
│   ├── String Library Project.cpp
│   └── clsString.h
├── 🛠️ Utility Lib/
│   ├── Utility Library.cpp
│   ├── clsDate.h
│   ├── clsString.h
│   └── clsUtil.h
└── README.md
```

**File Structure Pattern:**
- Each library folder contains its **header file** (.h) and **demonstration file** (.cpp)
- **Cross-library dependencies**: Date, String, and Utility classes are shared across libraries
- **Modular design**: Each folder represents a self-contained library with examples

## 🏗️ Data Structures Collection

> **Note**: All data structures are implemented **from scratch** to understand underlying mechanisms and improve algorithmic thinking.

### 📋 Core Data Structures

#### `clsDblLinkedList<T>`
- **Purpose**: Template-based doubly linked list with bidirectional traversal
- **Key Features**: O(1) head operations, comprehensive manipulation methods
- **Time Complexity**: O(1) insertion/deletion at head, O(n) search/access

#### `clsDynamicArray<T>`
```cpp
clsDynamicArray<int> arr(10);
arr.InsertAtEnd(42);
arr.Resize(20);
bool found = arr.DeleteItem(42);
```
- **Purpose**: Resizable array with dynamic memory management  
- **Key Features**: Random access, automatic resizing, bounds checking
- **Time Complexity**: O(1) access, O(n) insertion/deletion

#### `clsMyQueue<T>` (Linked List-based)
```cpp
clsMyQueue<string> queue;
queue.push("Customer 1");
queue.push("Customer 2");
string next = queue.front();  // "Customer 1"
queue.pop();
```
- **Purpose**: FIFO queue built on doubly linked list
- **Key Features**: O(1) push/pop, indexing, reversal capabilities
- **Time Complexity**: O(1) enqueue/dequeue operations

#### `clsMyQueueArr<T>` (Array-based)
```cpp
clsMyQueueArr<int> arrQueue;
arrQueue.push(100);
int front = arrQueue.front();
arrQueue.UpdateItem(0, 200);
```
- **Purpose**: FIFO queue with array-based storage
- **Key Features**: Cache-friendly, random access, memory locality
- **Time Complexity**: O(1) access, O(n) queue operations

#### `clsMyStack<T>` & `clsMyStackArr<T>`
```cpp
clsMyStack<double> stack;
stack.push(3.14);
stack.push(2.71);
double top = stack.Top();     // 2.71
double bottom = stack.Bottom(); // 3.14
```
- **Purpose**: LIFO stack with dual implementation strategies
- **Key Features**: Top/bottom access, inherits queue functionality  
- **Time Complexity**: O(1) push/pop operations

## 🌟 Framework-Level Utility Libraries

### `clsString` - Advanced String Framework
```cpp
string text = "Hello, World!";
clsString::CountVowels(text);           // 3
clsString::ReverseWordsInString(text);  // "olleH, !dlroW"
string encrypted = clsString::EncryptText(text, 3);
vector<string> words = clsString::SplitString(text, ",");
```

**Enterprise Features:**
- 🔤 **Text Processing**: Case conversion, trimming, word manipulation
- 🔢 **Analytics**: Vowel counting, character frequency, word statistics  
- 🔐 **Security**: Text encryption/decryption capabilities
- 📝 **Parsing**: Advanced splitting, tokenization, validation

### `clsDate` - Complete Calendar System
```cpp
clsDate today;
clsDate future = clsDate::AddDaysToDate(today, 30);
bool isBusinessDay = clsDate::IsBusinessDay(today);
int vacationDays = clsDate::CalculateVacationDays(start, end);
```

**Business Logic Integration:**
- 📅 **Calendar Operations**: Date arithmetic, leap year handling
- 💼 **Business Logic**: Business day calculations, vacation planning
- 🎯 **Validation**: Date range validation, format verification
- 📊 **Analytics**: Period comparisons, duration calculations

### `clsInputValidate<T>` - Robust Validation Framework
```cpp
int number = clsInputValidate::ReadIntNumberBetween(1, 100, "Enter age: ");
string email = clsInputValidate::ReadString("Enter email: ");
clsDate date = clsInputValidate::ReadDate("Enter birthdate: ");
```

**Template-Based Safety:**
- ✅ **Type Safety**: Template-based numeric validation
- 🛡️ **Range Checking**: Boundary validation with error recovery
- 🔍 **Input Sanitization**: Clean user input handling
- 💬 **User Feedback**: Clear error messaging and prompts

## 🎫 Business Application: Ticket Management System

Real-world queue management for service industries:

```cpp
clsQueueLine bankQueue("BNK");
clsTicket ticket = bankQueue.IssueTicket();
cout << "Your ticket: " << ticket.Number() << endl;
cout << "Estimated wait: " << ticket.ExpectedServeTime() << " minutes" << endl;

bankQueue.ServeNextClient();  // Process next customer
```

**Industry Applications:**
- 🏦 Banking and financial services
- 🏥 Medical facilities and clinics  
- 🍽️ Restaurants and food service
- 🏢 Government offices and DMV

## ⚡ Performance & Architecture Strengths

### 🎯 Big O Complexity Analysis
| Data Structure | Access | Search | Insertion | Deletion | Space |
|----------------|--------|--------|-----------|----------|-------|
| **Doubly Linked List** | O(n) | O(n) | O(1)* | O(1)* | O(n) |
| **Dynamic Array** | O(1) | O(n) | O(n) | O(n) | O(n) |
| **Queue (List-based)** | - | - | O(1) | O(1) | O(n) |
| **Queue (Array-based)** | O(1) | - | O(n) | O(n) | O(n) |
| **Stack (Both)** | - | - | O(1) | O(1) | O(n) |

*\* At head/known position*

### 🏗️ Enterprise Architecture Principles

#### **Separation of Concerns** 🎯
- Each class has a **single, well-defined responsibility**
- Clear abstraction layers: `Data Structures → Containers → Business Logic`
- Interface segregation following **SOLID principles**

#### **Template-Based Generics** 🔧
- **Type-safe** implementations for any data type
- **Zero runtime overhead** from template specialization
- **Compile-time polymorphism** for optimal performance

#### **Composition Over Inheritance** 🧩
- Queue classes **compose** base data structures
- Stack classes **extend** queue functionality appropriately
- Clean dependency chain: `Stack → Queue → DataStructure`

## 🚀 Advanced Implementation Features

### **Memory Management Excellence** 💾
- **RAII principles** with proper destructors
- **Manual memory management** in linked structures
- **No memory leaks** with structured allocation/deallocation
- **Dynamic resizing** with efficient memory usage

### **Error Handling & Safety** 🛡️
- **Bounds checking** with `IsValid()` methods
- **Null pointer protection** before operations
- **Graceful degradation** with meaningful error messages
- **Edge case handling** (empty containers, invalid indices)

### **Debugging & Introspection** 🔍
- **Multiple print methods** for different visualization needs
- **Node detail printing** for linked structure analysis  
- **Clear visual representation** of data relationships
- **Comprehensive testing** capabilities

## 🎓 Educational & Production Value

### **Learning Outcomes** 📚
- ✅ **Data Structure Fundamentals**: Implementation from scratch
- ✅ **Memory Management**: Manual allocation and RAII patterns  
- ✅ **Template Programming**: Generic, type-safe implementations
- ✅ **OOP Mastery**: Inheritance, composition, encapsulation
- ✅ **Algorithm Analysis**: Big O complexity understanding
- ✅ **Software Architecture**: SOLID principles and design patterns

### **Real-World Applications** 🌍
- 💰 **Banking Systems**: Used in actual bank management project
- 🎫 **Service Industries**: Queue management for customer service
- 📊 **Business Logic**: Date/time processing, validation frameworks
- 🔧 **Utility Libraries**: Foundation for larger applications

## 🛠️ Getting Started

### Prerequisites
```bash
# Requirements
- C++11 or later
- Compatible compiler (GCC, Clang, MSVC)
- Basic understanding of templates and OOP
```

### Quick Integration
```cpp
// Include the libraries you need
#include "DataStructures/clsDynamicArray.h"
#include "StringLib/clsString.h"
#include "DateLib/clsDate.h"
#include "ValidationLib/clsInputValidate.h"

// Start using immediately
clsDynamicArray<int> numbers;
numbers.InsertAtEnd(42);
cout << "Array size: " << numbers.Size() << endl;
```

### Build and Use
```bash
# Clone the repository
git clone https://github.com/YaMazini/Utilities-And-DataStructures.git
cd Utilities-And-DataStructures

# Compile with your project (header-only libraries)
g++ -std=c++11 your_project.cpp -I./include -o your_project

# Each folder contains its own class library + .cpp example file
```

## 🌟 What Makes This Collection Unique

### **Framework-Level Libraries** 🎯
- **clsString** and **clsDate** provide framework-level functionality
- **Comprehensive feature sets** beyond standard library offerings
- **Business logic integration** for real-world applications
- **Professional-grade** implementations suitable for production

### **Educational Focus** 📚
- **Built from scratch** to understand underlying mechanisms
- **Clear implementations** demonstrating fundamental concepts
- **Progressive complexity** from basic structures to business applications
- **Commented code** explaining design decisions

### **Production Ready** 🚀
- **Enterprise-grade architecture** following industry standards
- **Robust error handling** and edge case management
- **Performance optimization** with appropriate algorithm choices
- **Memory safety** and resource management

## 💡 Usage Examples

### Data Structure Chaining
```cpp
// Create a queue of custom objects
struct Customer {
    string name;
    int priority;
};

clsMyQueue<Customer> customerQueue;
customerQueue.push({"Alice", 1});
customerQueue.push({"Bob", 2});

Customer next = customerQueue.front();
customerQueue.pop();
```

### Business Logic Integration
```cpp
// Real-world date processing
clsDate projectStart(15, 3, 2024);
clsDate deadline = clsDate::AddBusinessDays(projectStart, 30);

if (clsDate::IsDateInPeriod(clsDate::GetSystemDate(), projectStart, deadline)) {
    cout << "Project is active!" << endl;
}
```

### String Processing Pipeline
```cpp
string userInput = "  Hello, WORLD! How are you?  ";
userInput = clsString::Trim(userInput);
userInput = clsString::UpperFirstLetterOfEachWord(userInput);
int wordCount = clsString::CountWords(userInput);
```

## 🤝 Contributing

This is primarily an **educational project** for learning C++ and data structures. However, suggestions and improvements are welcome!

### Development Philosophy
- **Learn by building** - implement from scratch when possible
- **Understand the 'why'** - not just the 'how'
- **Real-world applicability** - create useful, practical libraries
- **Clean, readable code** - prioritize maintainability

## 👤 Author

**YaMazini** - *Software Engineering Student*
- 🎯 **Focus**: Mastering data structures, OOP, and practical C++ development
- 📚 **Goal**: Building reusable libraries while learning fundamental concepts
- 💼 **Application**: Using these libraries in real projects (Bank System)

GitHub: [@YaMazini](https://github.com/YaMazini)

---

## 🙏 Acknowledgments

**Problems curated and adapted from [ProgrammingAdvices](https://programmingadvices.com/)** - an excellent resource for systematic programming education.

---

## 🎓 Project Status & Future

**Current Status**: ✅ **Active Development**
- 📊 **Data Structures**: Core implementations complete *(except Doubly Linked List - being reconstructed)*
- 🌟 **Framework Libraries**: String and Date libraries feature-complete
- 🎫 **Business Applications**: Ticket system operational
- 💼 **Real-World Testing**: Successfully used in Bank System project

**Educational Achievements**: 🏆
- ✅ Deep understanding of memory management
- ✅ Mastery of template programming
- ✅ Implementation of fundamental algorithms
- ✅ Application of OOP and design patterns
- ✅ Creation of production-ready code

**Future Enhancements**:
- 🔄 Reconstruct Doubly Linked List implementation
- 🆕 Add more specialized data structures (Trees, Graphs)
- 🎯 Expand business logic libraries
- 📚 Create comprehensive documentation
- 🧪 Add unit testing framework

---

⭐ **If you find this educational project valuable for learning C++ and data structures, please consider giving it a star!**

*Built with passion for learning and creating practical, reusable code* 💙
