
/* This program encrypts a file using an encryption factor "EF" 
- By: Ximena Morales 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	int line_num = 1;
	string line;
	fstream file;
	ofstream coded;

	int EF = (line_num - 1) % 6 + 1;

	file.open("plain.txt", ios::in);
	coded.open("coded.txt", ios::out);

	while (!file.eof()) {

		while (getline(file, line)) {

			line_num++;

			for (int i = 0; i < line.length(); i++) {

					line[i] = line[i] + EF;
					coded << line[i];
			}
			coded << endl;

		  EF = (line_num - 1) % 6 + 1;
		}

			
	}

	file.close();
	coded.close();

	return 0; 
}




