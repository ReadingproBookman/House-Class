#include <iostream>
#include <cmath>
#include <iomanip>
#include "house.h"

using namespace std;

// Constructor
House::House(int s, char b, char f) : size (s), borderChar (b), fillChar (f) {
    if (size < 3) {
        size = 3;
    } else if (size > 37) {
        size = 37;
    } else {
        size = size;
    }

    // Set border character
    if (isValidChar(borderChar)) {
        borderChar = borderChar;
    } else {
        borderChar = 'X'; // Default
    }

    // Set fill character
    if (isValidChar(fillChar)) {
        fillChar = fillChar;
    } else {
        fillChar = '*'; // Default
    }
}

// Check if character is valid
bool House::isValidChar(char ch) const {
    return (ch >= 33 && ch <= 126);
}

// Accessor functions
int House::GetSize() const {
    return size;
}

int House::Perimeter() const {
    return 4 * size + 3 * (size + 2); // Square base + triangular roof
}

double House::Area() const {
    double baseArea = size * size; // Area of square base
    double roofArea = (sqrt(3) / 4) * pow(size + 2, 2); // Area of triangle roof
    return baseArea + roofArea;
}

// Grow the house size
void House::Grow() {
    if (size < 37) {
        size++;
    }
}

// Shrink the house size
void House::Shrink() {
    if (size > 3) {
        size--;
    }
}

// Set new border character
void House::SetBorder(char newBorderChar) {
    if (isValidChar(newBorderChar)) {
        borderChar = newBorderChar;
    } else {
        borderChar = 'X'; // Reset to default
    }
}

// Set new fill character
void House::SetFill(char newFillChar) {
    if (isValidChar(newFillChar)) {
        fillChar = newFillChar;
    } else {
        fillChar = '*'; // Reset to default
    }
}

// Draw the house
void House::Draw() const {
    // Draw roof
    int height = size + 2;

    // loop for roof
    // loop for no. of lines
    for (int i = 1; i < height; i++) {

        // loop for spaces
        for (int j = height-i; j >= 1; j--)
            cout<<" ";

        // left side border
        cout<<borderChar<<" ";

        // loop for fill
        for (int j = 1; j <= i-2; j++)
            cout<<fillChar<<" ";

        //right side border
        if (i!=1)
            cout<<borderChar;

        cout<<endl;
    }

//    // loop for square
    for (int i=1;i<=size;i++) {

        // first line
        if (i==1) {
            cout<<borderChar<<" "<<borderChar<<" ";
            for (int j=1; j<=size-2;j++)
                cout<<fillChar<<" ";
            cout<<borderChar<<" "<<borderChar;
        }

        // last line (border)
        else if (i==size) {
            cout<<"  ";
            for (int j=1; j<=size; j++)
                cout<<borderChar<<" ";
        }

        // middle part
        else {
            cout<<"  "<<borderChar<<" ";
            for (int j=1; j<=size-2;j++)
                cout<<fillChar<<" ";
            cout<<borderChar<<" ";
        }

        cout<<endl;
    }
}

// Summary function to display information about the house
void House::Summary() const {
    cout << "Base Size: " << size << endl;
    cout << "Perimeter: " << Perimeter() << endl;
    cout << "Area: " << fixed << setprecision(2) << Area() << endl;
    Draw();
}

