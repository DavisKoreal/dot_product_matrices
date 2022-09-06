// Adding and outputting matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

//initialize the range
const int range = 10000;
//initialize the string namme
const std::string filename = "TESTING_MATRICES2.txt";
//initializing the file as a global variable
std::ofstream myfile(filename, std::ios::out | std::ios::trunc);


double returnvalue(const std::vector<double>& rowvector, const std::vector<double>& collumnvector) {
	double result = 0;
	for (int i = 0; i < rowvector.size(); i++) {
		result += (rowvector[i] * collumnvector[i]);
	}
	return result;
}

void getdotproduct(int row, int col, int rowtwo, int coltwo) {
		
			myfile << "Inputting the number of rows of first matrix as : "<< row << std::endl;
			myfile << "Inputting the number of collumns of first matrix as : " << col<< std::endl;
			myfile << "Inputting the number of rows of second matrix as : " << rowtwo << std::endl;
			myfile << "Inputting the number of collumns of second matrix as : " << coltwo << std::endl;

			if (col != rowtwo) {
				std::cout << "We cannot multiply this matrice. The collumns of the first matrice do not match the rows of the second matrice" << std::endl;
				return;
			}
			else {
				myfile << "MATRICES ENTERED CAN HAVE A DOT PRODUCT " << std::endl;
			}
		//initialize the max width of a value
		int maxwidth(5);

		std::vector<std::vector<double>> firstvector(row, std::vector<double>(col, 0)); //holds values for first vector
		std::vector<std::vector<double>> secondvector(rowtwo, std::vector<double>(coltwo, 0)); //
		std::vector<std::vector<double>> secondvec(coltwo, std::vector<double>(rowtwo, 0));
		std::vector<std::vector<double>> dotproduct(row, std::vector<double>(coltwo, 0));

		//inputting data to the first matrice
		std::cout << "inputting the data to your first matrice " << std::endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int b = i;
				int c = j;
				double a = rand() % range;
				firstvector[i][j] = (a / 10000);
				std::cout << "Input value for row " << ++b << " and collumn " << ++c << " of your first matrice: " << (a/10000) << std::endl;

				while (a >= (pow(10, maxwidth))) {
					maxwidth++;
				}
				
			}
		}

		myfile << "INPUT TO MATRIX ONE SUCCESSFULL" << std::endl;

		myfile << "FIRST MATRICE : " << std::endl << std::endl;
		for (int i = 0; i < firstvector.size(); i++) {
			std::cout << "| ";
			myfile << " |";
			for (auto j : firstvector[i]) {
				std::cout << std::setw(maxwidth) << std::left << j;
				myfile << std::setw(maxwidth) << std::left << j;
			}
			std::cout << " |" << std::endl;
			myfile << " |" << std::endl;
		}
		myfile << " " << std::endl << std::endl;

		//inputting data to the second matrice
		std::cout << "Inputting the data to your second matrice " << std::endl;
		for (int i = 0; i < rowtwo; i++) {
			for (int j = 0; j < coltwo; j++) {
				int b = i;
				int c = j;

				double a = rand() % range;

				secondvector[i][j] = (a / 10000);

				std::cout << "Input value for row " << ++b << " and collumn " << ++c << " of your second matrice :" << (a/10000) << std::endl;
				while (a >= (pow(10, maxwidth))) {
					maxwidth++;
				}
			}
		}

		myfile << "INPUT TO MATRIX TWO SUCCESFUL" << std::endl;
		myfile << "SECOND MATRICE : " << std::endl << std::endl;
		for (int i = 0; i < secondvector.size(); i++) {
			std::cout << "| ";
			myfile << " |";
			for (auto j : secondvector[i]) {
				std::cout << std::setw(maxwidth) << std::left << j;
				myfile << std::setw(maxwidth) << std::left << j;
			}
			std::cout << " |" << std::endl;
			myfile << " |" << std::endl;
		}
		myfile << " " << std::endl << std::endl;


		if (col != rowtwo) {

			std::cout << "We cannot multiply this matrice. The collumns of the first matrice do not match the rows of the second matrice" << std::endl;
		}
		else {

			for (int roww = 0; roww < secondvector.size(); roww++) {
				for (int colll = 0; colll < secondvector[0].size(); colll++) {
					secondvec[colll][roww] = secondvector[roww][colll];
				}
			}

			myfile << "GENERATING TRANSPOSE TO MATRIX TWO SUCCESFULL" << std::endl;
			myfile << "SECOND MATRICE TRANSPOSE : " << std::endl;
			for (int i = 0; i < secondvec.size(); i++) {
				std::cout << "| ";
				myfile << " |";
				for (auto j : secondvec[i]) {
					std::cout << std::setw(maxwidth) << std::left << j;
					myfile << std::setw(maxwidth) << std::left << j;
				}
				std::cout << " |" << std::endl;
				myfile << " |" << std::endl;
			}

			myfile << " " << std::endl << std::endl;


			for (int i = 0; i < firstvector.size(); i++) {
				for (int j = 0; j < secondvector[0].size(); j++) {
					dotproduct[i][j] = returnvalue(firstvector[i], secondvec[j]);

					while (dotproduct[i][j] >= (pow(10, maxwidth))) {
						maxwidth++;
					}
				}
			}
		}

		myfile << "DOT MULTIPLICATION SUCCESFULL" << std::endl;
		myfile << "DOT PRODUCT : " << std::endl;
		for (int i = 0; i < dotproduct.size(); i++) {
			std::cout << "| ";
			myfile << " |";
			for (auto j : dotproduct[i]) {
				myfile << std::setw(maxwidth) << std::left << j;
			}
			std::cout << " |" << std::endl;
			myfile << " |" << std::endl;
		}

		myfile << " " << std::endl << std::endl;
}


int main()
{
	getdotproduct(50, 50, 50, 1);
	myfile.close();
}





