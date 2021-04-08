/*  Ryan Dickman
    CSCE 3110.002
    Programming Assignment 4 - Heap Sort
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;


int main(){
	
	// Variables	
	ifstream file;
	ofstream out;
	string line;
	istringstream s;
	double arr[100];
	double num;

	// Opening input file "data1.txt" and output file "out1.txt"
	file.open("data1.txt");
	out.open("out1.txt");
	
	// Next 2 commands check to make sure both files are open
	if(file.is_open()){
		
		if(!out.is_open()){
			cout << "Output file failed to open.\n";
			return 2;
		}
		
		// Repeats loop while there is information left in the input file
		while(file.good()){
			
			// Initializes count of numbers per line in .txt file, getline retrives the line and the stringstream s allows individual numbers to be plucked from the string
			int count = 0;
			getline(file, line);
			s.str(line);	
			
			// Repeats while there are numbers in the string and assigns them to the array
			while(s >> num){
				arr[count] = num;
				count++;
			}
					
			
			
			
			// Outputs sorted array to the out1.txt file
			for(int i = 0; i < count; i++){
				out << arr[i] << " ";
			}
			out << endl;

			// clears the stringstream for the next loop
			s.clear();
		}

	}
	else {
		cout << "File failed to open.\n";
		cin.get();
	}

	// Close both files
	file.close();
	out.close();

	return 0;
