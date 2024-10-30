#ifndef HOUSE_H
#define HOUSE_H

class House {
private:
    int size;              // Base size of the house
    char borderChar;      // Character for the border
    char fillChar;        // Character for the fill

    // Private functions to validate characters
    bool isValidChar(char ch) const;

public:
    // Constructor
    House(int size, char borderChar = 'X', char fillChar = '*');

    // Accessor functions
    int GetSize() const;
    int Perimeter() const;
    double Area() const;

    // Functions to grow and shrink the house
    void Grow();
    void Shrink();

    // Functions to set border and fill characters
    void SetBorder(char newBorderChar);
    void SetFill(char newFillChar);

    // Function to draw the house
    void Draw() const;

    // Function to display a summary of the house
    void Summary() const;
};

#endif
