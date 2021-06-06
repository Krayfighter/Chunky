#pragma once

#include <exception>

using namespace std;

class String_Parameter_Too_Long: public exception {
	public: const char *what() const throw() {return "string parameter too long";}};

class String_Parameter_Too_Short: public exception {
	public: const char *what() const throw() {return "string parameter too short";}};