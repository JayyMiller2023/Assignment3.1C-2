//Libraries
#include <iostream>
#include <String>
#include <windows.h>

//name space to define "std"
using namespace std;

// class that shows the dialogue in program
class sellPaper
{
public:
	//constructer for sellPaper class
	sellPaper(int amount) : items(amount)
	{
		cout << "Papers being constructed: " << items << " ... \n";
		Sleep(3000);
	}
	//deconstructer for sellPaper class
	~sellPaper()
	{
		cout << "Shipping a total of " << items << " items now. \n";
	}
	//Method for sellPaper class
	void display() const
	{
		cout << "Paper made: " << items << "! \n";
	}
private:
	// variable to connect the user's input with the class
	int items;
};

//Main Integer
int main()
{
	//defining variable for the amount of paper needed
	int amount;

	//Greetings message
	cout << "Hello! How much paper would you like to input? \n";
	//user's input
	cin >> amount;

	//try block for detecting errors
	try
	{
		//condition if the amount is less than 1...
		if (amount < 1)
		{
			// then throw the error below.
			throw "Invalid number. Please try again.";
		}
	}
	catch (const char* msg) // Catch block to display the message.
	{
		cerr << msg << "\n";
	}

	//calls the class and makes a variable for it, while getting the users input with it.
	unique_ptr<sellPaper> uniquePointer = make_unique<sellPaper>(amount);
	//Display the amount produced
	uniquePointer->display();

	return 0; // return 0
}