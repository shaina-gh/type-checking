## 🧠 AIM

To implement **type checking** for variable declarations and arithmetic expressions using C++, ensuring compatibility of data types in assignments.

---

## 📘 EXPLANATION

In the semantic analysis phase of a compiler, type checking ensures that operations are semantically valid — particularly that data types match across expressions. This project replicates a simplified version of that:

- Users declare variables along with their types (`int`, `float`, `real`).
- An expression is provided in the form of an assignment.
- The program checks that the data type of the LHS variable is not of lower precision than any variables on the RHS.

It flags mismatches or confirms correctness accordingly.

---

## 🔍 LOGIC

1. **Input Stage**:
   - Prompt for the number of variables.
   - For each, get a variable name and its type (validated against `int`, `float`, `real`).

2. **Store Types**:
   - Map variable names to an integer representing their type precedence (e.g., `int` = 0, `float` = 1, `real` = 2).

3. **Parse Expression**:
   - Extract LHS and RHS of the expression.
   - Tokenize RHS and check that no variable on RHS has higher precedence than LHS.

4. **Type Validation**:
   - If an incompatibility is found, report the expected type.
   - Otherwise, print "Correct".

---

## 💡 SAMPLE INPUT/OUTPUT

### ✅ Valid Case

**Input:**
```cpp
Enter the number of variables: 2
Enter variable name and type (e.g., a int): x float
Enter variable name and type (e.g., a int): y int
Enter the expression: x = y
```
**Output:**
```cpp
Correct
```

---

### ❌ Invalid Case

**Input:**
```cpp
Enter the number of variables: 3
Enter variable name and type (e.g., a int): a int
Enter variable name and type (e.g., a int): b float
Enter variable name and type (e.g., a int): c int
Enter the expression: a = b + c
```
**Output:**
```cpp
a should be of type float
```

---

## 🌍 REAL-WORLD APPLICATIONS

- **Compiler Design**: Helps detect semantic type errors at compile-time.
- **Integrated Development Environments (IDEs)**: Underpins type hints and warnings.
- **Data Transformation Pipelines**: Prevents operations on mismatched types in ETL systems.
- **Embedded Systems Development**: Ensures type safety to avoid low-level errors in constrained environments.

---
