#include <sstream>
#include "file.h"

file::file() {
	this->name = "";
	this->bits = 0;
	this->attr = NONE;
	this->creation_date = "0000-00-00";
	this->creation_time = "00-00-00";
}

file::file(std::string name, int bits, Attribute attribute, std::string cdate, std::string ctime) {
	this->name = name;
	this->bits = bits;
	this->attr = attribute;
	this->creation_date = cdate;
	this->creation_time = ctime;
}

float file::to_byte() {
	return this->bits / 8;
}

std::string file::toString() {
	std::ostringstream oss;
	oss << "File: " << name
		<< "\n\tSize (bits): " << bits
		<< "\n\tSize (bytes): " << to_byte()
		<< "\n\tAttributes: "
		<< (attr == READ ? "Read" :
			attr == WRITE ? "Write" :
			attr == HIDDEN ? "Hidden" : 
			"No attributes")
		<< "\n\tCreation date: " << creation_date
		<< "\n\tCreation time: " << creation_time;
	return oss.str();
}

file::~file() {}