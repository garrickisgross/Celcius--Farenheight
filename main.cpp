#include <iostream>
#include <fstream>

using namespace std;

// function for formatting output
void write(ostream& outFS, string city, double temp)
{
	outFS << city << " " << temp << endl;
}

// function for converting to C
double convert_to_celcius(int temp)
{
	double cel;

	temp = temp * 1.0;

	cel = temp - 32;

	// was running into some issues here, not sure why, but static casting to a double fixed.
	cel = cel * (static_cast<double>(5) / 9);

	return cel;
}

int main()
{
	//declare vars
	ifstream inFS;
	ofstream outFS;
	string city;
	int temp;
	double celcius;

	//open files and check that they are open
	inFS.open("farenheight_temperature.txt");
	outFS.open("celcius_temperature.txt");

	if (!outFS.is_open()) 
	{
		cout << "Could not open file outfile" << endl;
		return 1;
	}

	if (!inFS.is_open())
	{
		cout << "Could Not Open File" << endl;
		return 1;
	}

	// if the input stream has not failed, then read the next two values
	// and convert temp to C, then pass stream, city, C to the write function.
	while (!inFS.fail())
	{
		inFS >> city >> temp;

		celcius = convert_to_celcius(temp);

		write(outFS, city, celcius);
	}

	//close output file.
	outFS.close();
	return 0;
};