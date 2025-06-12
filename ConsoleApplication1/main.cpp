#include "file.h"
using namespace std;

int main() {
	file f1("Homework", 2024, WRITE, "2020-11-11", "14-04-49");
	cout << f1.toString() << endl;
	return 0;
}