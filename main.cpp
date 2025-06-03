#include <iostream>
#include <string>
#include <map>

using namespace std;

// Define valid data types
const string DataTypes[] = {"int", "float", "real"};

int main() {
    int numVariables;
    cout << "Enter the number of variables: ";
    cin >> numVariables;

    map<string, int> variableTypes;
    string varName, varType;

    // Collect variable names and types
    for (int i = 0; i < numVariables; ++i) {
        cout << "Enter variable name and type (e.g., a int): ";
        cin >> varName >> varType;

        bool isValidType = false;
        for (int j = 0; j < 3; ++j) {
            if (varType == DataTypes[j]) {
                variableTypes[varName] = j;
                isValidType = true;
                break;
            }
        }

        if (!isValidType) {
            cout << "Error: Invalid type '" << varType << "' entered. Please try again.\n";
            --i; // Repeat this iteration
        }
    }

    // Clear input buffer before reading expression
    cin.ignore();
    string expression;
    cout << "\nEnter the expression: ";
    getline(cin, expression);

    // Extract LHS variable
    string lhs = "";
    int equalSignPos = 0;
    while (expression[equalSignPos] != '=') {
        if (expression[equalSignPos] != ' ') {
            lhs += expression[equalSignPos];
        }
        equalSignPos++;
    }

    // Process RHS
    equalSignPos++;
    string rhs = "";
    bool isCompatible = true;

    for (int i = equalSignPos; i < expression.length(); ++i) {
        char ch = expression[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (!rhs.empty() && variableTypes[rhs] > variableTypes[lhs]) {
                cout << lhs << " should be of type " << DataTypes[variableTypes[rhs]] << "\n";
                isCompatible = false;
                break;
            }
            rhs = "";
        } else if (ch != ' ') {
            rhs += ch;
        }
    }

    // Final check for last token
    if (isCompatible && !rhs.empty() && variableTypes[rhs] > variableTypes[lhs]) {
        cout << lhs << " should be of type " << DataTypes[variableTypes[rhs]] << "\n";
        isCompatible = false;
    }

    if (isCompatible) {
        cout << "Correct\n";
    }

    return 0;
}
