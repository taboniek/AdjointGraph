#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

int n;
bool adjoint;
bool tempo;
vector<vector<int> >wektor;
vector<vector<int> >original;

void write() {

	string line;
	ifstream sample;
	int number = 0;
	int i = 0;
	int j = 0;
	sample.open("halko.txt", std::ios::in);
	if (sample.good() == false)
		cout << "Unable to open file!" << endl;
	else
	{
		getline(sample, line);
		n = atoi(line.c_str());

		while (sample.good()) {

			vector<int>temp;
			sample >> number;
			while (number != 0) {

				temp.push_back(number);
				sample >> number;
				if (number == 0) break;

			}
			sort(temp.begin() + 1, temp.end());
			wektor.push_back(temp);


		}

		cout << " File successfully loaded: " << endl;
		sample.close();
	}
}

void one_graph() {

	adjoint = 1; 
	for(int i=0; i<n && adjoint == 1; i++)
		for(int j=1; j<wektor[i].size() && adjoint == 1; j++)
			for (int k = j + 1; k < wektor[i].size() && adjoint == 1; k++)
			{
				if (wektor[i][j] == wektor[i][k])
					adjoint = 0;
			}
}

void adjont_graph() {

	int counter = 0;
	adjoint = 1;
	for (int i = 0; i < n && adjoint == 1; i++)
		for (int m = 0; m < n && adjoint == 1; m++)
		{
			if (wektor[i].size() == wektor[m].size()) {
				counter = 0;
				for (int j = 1; j < wektor[i].size() && adjoint == 1; j++) {
					if (wektor[i][j] == wektor[m][j])
						counter += 1;
				}
				if (counter == wektor[i].size()-1 || counter == 0)
					adjoint = 1;
				else adjoint = 0; 
			}
			else {
				for (int j = 1; j < wektor[i].size() && adjoint == 1; j++) {
					for (int k = 1; k < wektor[m].size() && adjoint == 1; k++) {
						if (wektor[i][j] != wektor[m][k])
							adjoint = 1;

						else adjoint = 0;
					}
				}

			}
		}
	if (adjoint == 1)
		cout << endl << "Graph is adjoint graph" << endl;
	else
		cout << "Graph in not adjoint graph" << endl;

}

void first_structure() {

	int t, p;
	int a;
	for (int i = 0; i < n && tempo==1; i++) {
		for (int j = 1; j < wektor[i].size() && wektor[i][0]!=wektor[i][j] && tempo==1; j++) {
			for (int k = j + 1; k < wektor[i].size() && tempo == 1; k++) {
				a = 0;
				for (int h = 0; h < n; h++) {
					if (wektor[h][0] == wektor[i][j]) {
						t = h;
						a++;
					}
					if (wektor[h][0] == wektor[i][k]) {
						p = h;
						a++;
					}
					if (a == 2)
						break;
				}
				if (a == 2) {
					for (int m = 1; m < wektor[t].size() && tempo == 1; m++)
						for (int r = 1; r < wektor[p].size() && tempo == 1; r++)
							if (wektor[t][m] == wektor[p][r] && wektor[t][m] != wektor[i][0])
								tempo = 0;
				}
			}
		}
	}
}

void second_structure() {

	int t, p;
	int a;
	for (int i = 0; i < n && tempo==1; i++)
		for (int j = 1; j < wektor[i].size() && wektor[i][0] != wektor[i][j] && tempo==1; j++)
			for (int k = j + 1; k < wektor[i].size() && tempo == 1; k++) {
				a = 0;
				for (int x = 0; x < n; x++) {
					if (wektor[x][0] == wektor[i][j]) {
						t = x;
						a++;
					}
					if (wektor[x][0] == wektor[i][k]) {
						p = x;
						a++;
					}
					if (a == 2)
						break;
				}
				if (a == 2) {
					for (int x = 1; x < wektor[t].size() && tempo == 1; x++)
						for (int y = 1; y < wektor[p].size() && tempo == 1; y++)
							if (wektor[t][x] == wektor[i][0] && wektor[p][y] == wektor[i][0])
								tempo = 0;
				}	
			}
}

void third_structure() {

	
	int a=0;
	int m;
	bool r = 0;
	for(int i = 0; i < n; i++) 
		for (int j = 1; j < wektor[i].size(); j++)
		{
			if (wektor[i][0] == wektor[i][j]) {
				for (int x = 1; x < wektor[i].size() ; x++) {
					if (wektor[i][0] == wektor[i][x])
						continue;

					a = 0;
					for (int k = 0; k < n; k++)
						if (wektor[k][0] == wektor[i][x]) {
							m = k;
							r = 1;
						}
					if (r == 1) {
						for (int p = 1; p < wektor[m].size(); p++) {
							if (wektor[m][p] == wektor[m][0])
								a++;
							if (wektor[m][p] == wektor[i][x])
								a++;
							if (a == 2)
								tempo = 0;
						}
					}
				}
			}
		}
}

void original_graph() {

	int a = 1;
	bool temp = 0;
	int stored_values = 0;
	int **tab = new int*[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[3];
	}
	
	for (int i = 0; i < n; i++) {
		tab[i][0] = wektor[i][0]; 
		tab[i][1] = a;
		a++;
		tab[i][2] = a;
		a++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < wektor[i].size(); j++) {
			stored_values = 0;
			if (wektor[i][j] != wektor[i][0]) {
				for (int m = 0; m < n; m++) {
					if (tab[m][0] == wektor[i][j])
					{
						stored_values = tab[m][1];
						tab[m][1] = tab[i][2];
						for (int k = 0; k < n; k++) {
							if (tab[k][1] == stored_values)
								tab[k][1] = tab[m][1];
							if (tab[k][2] == stored_values)
								tab[k][2] = tab[i][2];
						}
					}
				}
			}
			else {
				for (int m = 0; m < n ; m++) {
					if (tab[m][0] == wektor[i][j]) {
						stored_values = tab[m][1];
						tab[m][1] = tab[m][2];
						for (int k = 0; k < n; k++) {
							if (tab[k][1] == stored_values)
								tab[k][1] = tab[m][1];
							if (tab[k][2] == stored_values)
								tab[k][2] = tab[i][2];
						}
					}
				}
			}
		}
	}
	cout << "Original graph table edge " << endl; //TABELA KRAWEDZI GRAFU ORYGINALNEGO
	for (int j = 0; j < n; j++) {
		cout << tab[j][0] << "\t" << tab[j][1] << "\t" << tab[j][2] << endl;
	}

	for (int i = 0; i < n; i++) {
		if (tab[i][0] != 0) {
			vector<int> pompom;
			pompom.push_back(tab[i][1]);
			tab[i][0] = 0;
			for (int i = 0; i < n; i++) {
				if (tab[i][1] == tab[i][1]) {
					pompom.push_back(tab[i][2]);
					tab[i][0] = 0;
				}
			}
			original.push_back(pompom);
		}
	}
	for (int t = 0; t < n; t++) {
		temp = 0;
		for (int r = 0; r < original.size(); r++) {
			if (tab[t][2] == original[r][0])
				temp = 1;
		}
		if (temp == 0) {
			vector<int>pompom;
			pompom.push_back(tab[t][2]);
			original.push_back(pompom);
		}
	}
	cout << endl<<"List of successors to the original graph: " << endl; //Lista nastepnikow grafu oryginalnego:
	for (int i = 0; i < original.size(); i++) {
		cout << endl;
		for (int j = 0; j < original[i].size(); j++)
			cout << original[i][j] << "\t";
	}
}

void zapis() {

	ofstream plik; 
	string file_name; 
	cout << endl <<  "Enter the file name: \t" << endl;
	cin >> file_name; 
	file_name += ".txt";
	plik.open(file_name.c_str());
	if (plik.good() == true) {
		plik << original.size();
		for (int i = 0; i < original.size(); i++) {
			plik << "\n";
			for (int j = 0; j < original[i].size(); j++) {
				plik << original[i][j] << "\t";
			}
			plik << "0";
		}
	}
	else cout << "Error file! " << endl;
}

int main()
{
	int menu;
	
	

		write();
		for (int i = 0; i < wektor.size(); i++)
		{
			cout << endl;
			for (int j = 0; j < wektor[i].size(); j++)
			{
				cout << wektor[i][j] << "   ";
			}
		}
		cout << endl << endl;
		
		one_graph();
		
		if (adjoint == 1) {
			adjont_graph();
		}
		else cout << "Graph is not one-graph" << endl; 
		
		if (adjoint == 1) {
			tempo = 1;
			third_structure(); 
			first_structure(); 
			second_structure();
			if (tempo == 0)
				cout << endl << "Graph is not linear graph" << endl << endl;
			else cout << endl << "Graph is linear" << endl << endl;
			original_graph();
			zapis();
		}
		system("pause");

		//  return 0;
}
