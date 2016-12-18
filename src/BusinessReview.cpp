/**
 *  BusinessReview.cpp - Class implementation for a business review.  This class
 *                 will be a single node in the linked list.
 * Programming Project
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 * Program: Collaboration of John Stroud and Christopher Graves
 * The entire program was a collaboration between John David Stroud and Christopher Luke Graves. Every line of code has been
 * examined and tested by both parties. Denoting the specific pieces that came solely by one of the programmers would be not only time consuming and
 * difficult, but deminish the readibility and increase the difficulty of finding any errors that could exist without the programmers knowledge.
 * Resources: Our textbook along with "Starting out with C++: From Control Structures Through Objects, Eighth Edition by Tony Gaddis.
 */

#include "BusinessReview.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

BusinessReview::BusinessReview() {
	// Currently does nothing ...
}

// Copy constructor
BusinessReview::BusinessReview(const BusinessReview &businessReview) {
	this->businessId = businessReview.businessId;
	this->category = businessReview.category;
	this->businessName = businessReview.businessName;
	this->description = businessReview.description;
	this->businessCity = businessReview.businessCity;
	this->businessState = businessReview.businessState;
	this->reviewersName = businessReview.reviewersName;
	this->myCity = businessReview.myCity;
	this->myState = businessReview.myState;
	this->date = businessReview.date;
	this->starRating = businessReview.starRating;
	this->reviewersComments = businessReview.reviewersComments;
}

BusinessReview::~BusinessReview() {
	// Currently does nothing ...
}

//Stores businessId in list.
void BusinessReview::setBusinessId(const string businessId) {
	this->businessId = businessId;
}

//Generates random businessId
string BusinessReview::genBusinessId() const {

	int randomNumber(int maxNumber);
	char getCharByNumber(int number, const int START_ASCII_LETTERS);
	string getRandomString(int lengthOfString, const int NUM_LETTERS,
			const int START_ASCII_LETTERS);
	string businessId;
	int numbers1;
	int numbers2;

	const int START_ASCII_LETTERS = 65;
	const int NUM_LETTERS = 26;
	const int MIN_VALUE = 10;
	const int MAX_VALUE = 99;

	unsigned seed = time(0);

	// See the random number generator.
	srand(seed);
	numbers1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	numbers2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	// Initialize the random number generator
	srand(time(NULL));

	businessId = to_string(numbers1) + '-'
			+ getRandomString(3, NUM_LETTERS, START_ASCII_LETTERS) + '-'
			+ to_string(numbers2);

	return businessId;
}

/*
 * Get a random number between 1 and maxNumber
 */
int randomNumber(int maxNumber) {
	return (rand() % maxNumber + 1);
}

/*
 * Convert a given number between 1 and 26 to the equivolent character.
 * For example, 1 is A, 2 is B, etc.
 */
char getCharByNumber(int number, const int START_ASCII_LETTERS) {
	return number + START_ASCII_LETTERS - 1;
}

/*
 * Generate a random string of specified length lengthOfString.
 */
string getRandomString(int lengthOfString, const int NUM_LETTERS,
		const int START_ASCII_LETTERS) {
	string randomString = "";

	for (int i = 0; i < lengthOfString; i++) {
		randomString += getCharByNumber(randomNumber(NUM_LETTERS),
				START_ASCII_LETTERS);
	}

	return randomString;
}

//Returns businessId
string BusinessReview::getBusinessId() const {
	return businessId;
}

//Stores Category
void BusinessReview::setCategory(const int category) {
	this->category = category;
}

//Returns Category
int BusinessReview::getCategory() const {
	return category;
}

//Stores businessName
void BusinessReview::setBusinessName(const string businessName) {
	this->businessName = businessName;
}

//Returns businessName
string BusinessReview::getBusinessName() const {
	return businessName;
}

//Stores description
void BusinessReview::setDescription(const string description) {
	this->description = description;
}

//Returns description
string BusinessReview::getDescription() const {
	return description;
}

//Stores businessCity
void BusinessReview::setBusinessCity(string businessCity) {
	this->businessCity = businessCity;
}

//Returns businessCity
string BusinessReview::getBusinessCity() const {
	return businessCity;
}

//Stores businessState
void BusinessReview::setBusinessState(string businessState) {
	this->businessState = businessState;
}

//Returns businessState
string BusinessReview::getBusinessState() const {
	return businessState;
}

//Stores reviewersName
void BusinessReview::setReviewersName(string reviewersName) {
	this->reviewersName = reviewersName;
}

//Returns reviewersName
string BusinessReview::getReviewersName() const {
	return reviewersName;
}

//Stores myCity
void BusinessReview::setMyCity(string myCity) {
	this->myCity = myCity;
}

//Returns myCity
string BusinessReview::getMyCity() const {
	return myCity;
}

//Stores myState
void BusinessReview::setMyState(string myState) {
	this->myState = myState;
}

//Returns myState
string BusinessReview::getMyState() const {
	return myState;
}

//Stores date
void BusinessReview::setDate(string date) {
	this->date = date;
}

//Returns date
string BusinessReview::getDate() const {
	return date;
}

/* This function gets the month, day and year from the user as integers, validates each
 *  entry and stores them as a string in the proper mm/dd/yyyy format.
 */
string BusinessReview::inputDate() {
	int mm, dd, yyyy;
	string date, sm, sd, sy;
	string zero = "0";

	cout << "Please enter month in digits mm: ";

	while (!(cin >> mm) || mm < 1 || mm > 12) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invaild entry. Please enter month in digits mm: ";
	}

	sm = to_string(mm);
	if (mm < 10) {
		sm = zero + to_string(mm);
	}

	cout << "Please enter day in digits dd: ";

	while (!(cin >> dd) || dd < 1 || dd > 31) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invaild entry. Please enter day in digits dd: ";
	}

	sd = to_string(dd);
	if (dd < 10) {
		sd = zero + to_string(dd);
	}

	cout << "Please enter year in digits yyyy: ";

	while (!(cin >> yyyy) || yyyy < 1000 || yyyy > 9999) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invaild entry. Please enter year in digits yyyy: ";
	}

	date = sm + '/' + sd + '/' + to_string(yyyy);

	return date;

}

//Stores starRating
void BusinessReview::setStarRating(int starRating) {
	this->starRating = starRating;
}

//Returns starRating
int BusinessReview::getStarRating() const {
	return starRating;
}

//Stores reviewersComments
void BusinessReview::setReviewersComments(string reviewersComments) {
	this->reviewersComments = reviewersComments;
}

//Returns reviewersComments
string BusinessReview::getReviewersComments() const {
	return reviewersComments;
}

