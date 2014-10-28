/* short OOP demonstrating features of a vehicle base class and inheritance to a truck class. Just for practice
an object operator was defined and used. Virtual functions and
constructors are also used */

#include <iostream> // the standard c++ library for basic I/O 
using namespace std; // makes everything in the standard c++ library avaliable in the global scope of the file
// so can write 'cout<<' as oppose to 'std::cout<<' for example

class vehicle{ // base class
	int seats, mpg, fuelcap; //initialise variables used in the constructor, they're private variables by default
public:
	vehicle(int i, int j, int k){ //constructor within class assigns argument variables to class variables
		seats = i;
		mpg = j;
		fuelcap = k;
	}
	// virtual function to quantify how useful the vehicle is at moving supplies (demonstrates virtual functions)
	int usefulness_rating(){
		int rating;
		cout << "used base virtual function" << endl; // output to show the user when this function has been used and not the derived one
		return rating = 5;
	}
	int range(){ // range of vehicle function within the class
		return mpg * fuelcap;
	}
	~vehicle(); //prototype to deconstructor, function at bottom of file
	int get_seats() { return seats; } // these three are accessor functions, so main can access the variables that are private to vehicle
	int get_mpg(){ return mpg; }
	int get_fuelcap(){ return fuelcap; }
	vehicle operator +(vehicle op); //prototype for overload operator
	friend ostream &operator << (ostream &stream, vehicle object);
	friend istream &operator >> (istream &stream, vehicle &object);
};

class truck : public vehicle{ // a class called truck that inherits from the vehicle class
	int capacity;
public:
	truck(int c, int i, int j, int k) : vehicle(i, j, k){ // the base class constructor is initialised first then this one adds a capacity
		capacity = c;
	}
	~truck(); // prototype to deconstructor for truck 
	int usefulness_rating(int x){ // the virtual function acts differently for the truck class, here it outputs the argument's value.
		//  unlike the base one which returns 5 always
		int rating = x;
		cout << "used derived virtual function " << endl;
		return rating;
	}
	int get_capacity(){ return capacity; } // accessor function so main can get the value of capacity
};

// operator overload '+'
vehicle vehicle::operator+(vehicle op){
	vehicle temp(0, 0, 0); // object initialised within scope of operator definition
	// "this" is the pointer to thing on LHS of operator, this is by default
	temp.fuelcap = this->fuelcap + op.fuelcap;
	temp.mpg = mpg + op.mpg; // mpg is the miles per galleon of the LHS object and op.mpg is the miles per galleon of RHS object
	temp.seats = seats + op.seats;
	return temp; // returns a new object so the originals are unaltered by the operation, like an actual addition operation
}

// output stream
ostream &operator << (ostream &stream, vehicle object){ //&stream (for example cout)
	cout << "vehicle output " << endl;
	stream << object.fuelcap << endl;
	return stream;
}

// input stream
istream &operator >> (istream &stream, vehicle &object){ //pass reference so object is changed after this operator has finished 
	cout << "input fuelcap for a vehicle " << endl;
	stream >> object.fuelcap;
	return stream;
}

int main()
{
	int range1, mpg, fuel, seats, cap; //initialise variables needed

	vehicle car(5, 21, 60); //an object of the class vehicle
	vehicle bus = vehicle(20, 15, 100); //different way of defining an object
	truck van = truck(1, 2, 3, 4); //truck inherits characteristics from vehicle

	// all the following outputs and calculations are used just for testing the code

	range1 = car.range(); // use the range function using the values for the variables in the car object
	cout << range1 << endl; // print to screen range1
	cout << car.get_fuelcap() << endl; //use same . operator to get_fuelcap() for car
	vehicle car_and_bus = car + bus; // define a new object that adds car and bus using the operator overload 
	cout << car_and_bus.get_fuelcap() << endl; // test the addition operator has worked correctly
	cout << car_and_bus.get_mpg() << endl;
	cout << car_and_bus.get_seats() << endl;
	cout << "trying inheritance now " << endl; // 
	cout << van.get_capacity() << endl << van.get_fuelcap() << endl; // check the values have been inherited and the capacity feature of truck works
	cout << "try virtual function now" << endl;
	cout << van.usefulness_rating(68) << endl; // derived
	cout << car.usefulness_rating(); // base
	cout << endl << "new outputter ";
	cout << car << endl;
	cin >> car;
	cout << car;
	cout << van + van;

	// could use something like system("PAUSE"), but just made this but of code to keep the terminal open for viewing purposes  

	int pausess;
	cout << endl << "program now paused " << endl << "input a number to finish program and press enter ";
	cin >> pausess;
	return 0;
}

vehicle::~vehicle(){
	cout << "deconstructing vehicle..." << endl; //this destroys the object
	// can see message when an object is destroyed
}

truck::~truck(){
	cout << "deconstructing truck..." << endl;
}
