# Dead Man's Draw++ – C++ Console Card Game

**Student Name:** Dev Patel    
**Email:** patdy074@mymail.unisa.edu.au  
**Assignment:** Design Patterns with C++ – Assignment 1  

---

## 🛠️ How to Compile and Run

### Using Visual Studio 2022

1. Open the project `.sln` or CMake workspace.
2. Ensure CMake has configured all source files.
3. Build the project:  
   - Go to **Build > Build All** or press `Ctrl + Shift + B`
4. Run the program:  
   - Use `Ctrl + F5` (Start Without Debugging)  
   - OR click **Run > Start Without Debugging**

### Output File

- The executable `.exe` will be found inside:  
  `cmake-build-debug/` or `cmake-build-release/`  
- Copy this `.exe` into your submission ZIP.

---

## 📦 What's Implemented

- Full **object-oriented game logic** following the spec
- 9 card subclasses with correct `play()` effects:
  - Sword, Cannon, Chest, Key, Hook, Kraken, Oracle, Map, Mermaid
- Proper **scoring system** (highest value per suit)
- **Bust detection**, **Chest + Key bonus**, and **Map discard choices**
- Fully working **turn system**, **banking**, and **deck handling**
- **Smart pointer usage** with `std::shared_ptr<Card>`
- Uses **DeckFactory** to create and shuffle 54 cards
- **CMake build system** for cross-platform compiling
- **UML Class Diagram** and **Design Document** included in `/docs/`

---

## 📂 Folder Structure

