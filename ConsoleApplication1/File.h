#pragma once
#include <iostream>
#include <string>

enum Attribute {
	NONE, READ, WRITE, HIDDEN
};

class file {
	std::string name;
	int bits;
	Attribute attr;
	std::string creation_date;
	std::string creation_time;

public:
	file();
	file(std::string name, int bits, Attribute attribute, std::string cdate, std::string ctime);
	
	float to_byte();
	std::string toString();

	~file();
};

