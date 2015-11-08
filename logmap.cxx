#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	ofstream out("output.dat");

	for(double r=0; r <= 4; r += 0.001){
	   x=x0;

	double p[Nend-Nskip];

	   for(int i=1; i <= Nskip; i++) {
		  	x = r*x*(1.0-x);
	   }	//iteration steps skipped
	   for(int i=Nskip+1; i <= Nend; i++) {
	   		x = r*x*(1.0-x);	//those we actually want
			cout << r << "\t" << x << endl;
			p[i-Nskip-1] = x;	//x stored into array
   	   }
		for(int i = 0; i<=(Nend-Nskip-1); i++)
		out << r << "\t" << p[i] << endl;
		//for each r, array into output file
	}

	out.close();
	return 0;
}
