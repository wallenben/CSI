#include <string>;
#include <iostream>;
using namespace std;

int main() {
	string unfiltered = "randomtexttodemonstratereplacement";
	unfiltered.replace(10, 4, "****");
	//test to make sure it was replaced
	cout << unfiltered;
}