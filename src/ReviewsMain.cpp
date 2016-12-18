/**
 *  ReviewsMain.cpp - This program provides an example on how to add and
 *                      delete entries from an STL linked list.
 * Programming Project
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 * Program: Collaboration of John David Stroud and Christopher Luke Graves.
 * The entire program was a collaboration between John David Stroud and Christopher Luke Graves. Every line of code has been
 * examined and tested by both parties. Denoting the specific pieces that came solely by one of the programmers would be not only time consuming and
 * difficult, but deminish the readibility and increase the difficulty of finding any errors that could exist without the programmers knowledge.
 * Resources: Our textbook along with "Starting out with C++: From Control Structures Through Objects, Eighth Edition by Tony Gaddis.
 */

#include <fstream>
#include <iostream>
#include <list>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "BusinessReview.h"

using namespace std;

//
// Prototype declarations
//
void menu();
void newreview();
void deleteReview();
void editreview();
void filterreview();
void searchreview();
void displayAllReviews();
string displayCategory(int category);
void savedata();
void loaddata();
void deleteFirst();

//
// Declare the review list as an STL linked list variable
//
list<BusinessReview> reviewsList; //formerly bookList

/*
 *Main program. Calls the function to load reviews from the .dat file if present, deletes the emtpy node at the beginning of the list
 * and calls the menu function.
 */
int main() {

	loaddata();
	deleteFirst();

	menu();

	return 0;
}

/*
 *  This function adds a review to the linked list.
 */
void newreview() {
	BusinessReview businessReview;
	string userInput;
	int userInteger;

	cout << endl << "** New Business Review **\n Please Enter the following: "
			<< endl << endl;

	// Generate random and store businessId.
	userInput = businessReview.genBusinessId();
	businessReview.setBusinessId(userInput);
	cout << "Business I.D.:        " << userInput << endl;

	//Get and store category with input validation
	cout
			<< "What Category is the business?\n1: Restaurant\n2: Bar\n3: Fitness\n4: Theater\n5: Shopping\n6: Deals\n7: Everything: ";
	while (!(cin >> userInteger) || userInteger < 1 || userInteger > 7) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invaild entry. Please enter a number from 1 to 7: ";
	}

	businessReview.setCategory(userInteger);

	cin.ignore();
	cout << "Business Name: ";
	getline(cin, userInput, '\n');
	businessReview.setBusinessName(userInput);

	cout << "Description of Business: ";
	getline(cin, userInput, '\n');
	businessReview.setDescription(userInput);

	cout << "Business City: ";
	getline(cin, userInput, '\n');
	businessReview.setBusinessCity(userInput);

	//get and store businessState, validating that it is 2 characters
	cout << "Business State: ";
	getline(cin, userInput, '\n');
	while (userInput.size() != 2) {
		cout << "Please Enter the two letter abreviation for the State.";
		getline(cin, userInput, '\n');
	}
	businessReview.setBusinessState(userInput);

	cout << "Reviewers Name: ";
	getline(cin, userInput, '\n');
	businessReview.setReviewersName(userInput);

	cout << "Reviewers City: ";
	getline(cin, userInput, '\n');
	businessReview.setMyCity(userInput);

	cout << "Reviewers State: ";
	getline(cin, userInput, '\n');
	businessReview.setMyState(userInput);

	cout << "Date of Review:\n ";
	businessReview.setDate(businessReview.inputDate());

	//get and store starRating, validating that it is a number from 1 to 5
	cout << "Star Rating, 1 being worst 5 being best: ";
	while (!(cin >> userInteger) || userInteger < 1 || userInteger > 5) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invaild entry. Please enter a number from 1 to 5: ";
	}
	businessReview.setStarRating(userInteger);

	cin.ignore();
	cout << "Reviewers Comments: ";
	getline(cin, userInput, '\n');
	businessReview.setReviewersComments(userInput);

	// Add to the linked list
	reviewsList.push_back(businessReview);

	return;
}

/*
 * This function will allow the user to edit a review in the list based on the given
 * bussinessId, displays a message if the businessId is invalid. This function uses the same input validation as the newreview function.
 */

void editreview() {
	string busId;
	bool foundEntry = false;

	cout << endl << "** EDIT REVIEW **" << endl << endl;
	cout << "Enter Business I.D.: ";

	getline(cin, busId, '\n');

	list<BusinessReview>::iterator i = reviewsList.begin();
	while (i != reviewsList.end()) {
		if (i->getBusinessId() == busId) {
			foundEntry = true;
			if (foundEntry) {
				int userInteger;
				string userInput;

				cout << "Editing data for Business I.D.: " << busId << endl;

				cout
						<< "What Category is the business?\n1: Restaurant\n2: Bar\n3: Fitness\n4: Theater\n5: Shopping\n6: Deals\n7: Everything: ";
				while (!(cin >> userInteger) || userInteger < 1
						|| userInteger > 7) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout
							<< "Invaild entry. Please enter a number from 1 to 7: ";
				}
				i->setCategory(userInteger);

				cin.ignore();
				cout << "Business Name: ";
				getline(cin, userInput, '\n');
				i->setBusinessName(userInput);

				cout << "Description of Business: ";
				getline(cin, userInput, '\n');
				i->setDescription(userInput);

				cout << "Business City: ";
				getline(cin, userInput, '\n');
				i->setBusinessCity(userInput);

				cout << "Business State: ";
				getline(cin, userInput, '\n');
				while (userInput.size() != 2) {
					cout
							<< "Please Enter the two letter abreviation for the State.";
					getline(cin, userInput, '\n');
				}
				i->setBusinessState(userInput);

				cout << "Reviewers Name: ";
				getline(cin, userInput, '\n');
				i->setReviewersName(userInput);

				cout << "Reviewers City: ";
				getline(cin, userInput, '\n');
				i->setMyCity(userInput);

				cout << "Reviewers State: ";
				getline(cin, userInput, '\n');
				i->setMyState(userInput);

				cout << "Date of Review: ";
				userInput = i->inputDate();
				i->setDate(userInput);

				cout << "Star Rating, 1 being worst 5 being best: ";
				while (!(cin >> userInteger) || userInteger < 1
						|| userInteger > 5) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout
							<< "Invaild entry. Please enter a number from 1 to 5: ";
				}
				i->setStarRating(userInteger);

				cin.ignore();
				cout << "Reviewers Comments: ";
				getline(cin, userInput, '\n');
				i->setReviewersComments(userInput);
				foundEntry = false;

			}
			++i;
		} else {
			++i;
		}
	}

	if (!foundEntry)
		cout << "Review with that business I.D. not found." << endl;

	return;
}

/*
 * This function filters the reviews within the list by category. The function steps through the list
 *checking every object against given user input, displaying the reviews that are within the proper category
 *and stating the total number of reviews in the given category at the end.
 */
void filterreview() {
	int userCategory;
	int counter = 0;

	cout << endl << "** FILTER REVIEWS BY CATEGORY **" << endl << endl;
	cout
			<< "What Category is the business?\n1: Restaurant\n2: Bar\n3: Fitness\n4: Theater\n5: Shopping\n6: Deals\n7: Everything: ";
	cin >> userCategory;
	while (userCategory < 1 || userCategory > 7) {
		cout << "Invailid Category. Please pick a Category 1-7: ";
		cin >> userCategory;
	}

	list<BusinessReview>::iterator businessReview;
	for (businessReview = reviewsList.begin();
			businessReview != reviewsList.end(); ++businessReview) {
		if (businessReview->getCategory() == userCategory) {
			cout << "Business I.D.:        " << businessReview->getBusinessId()
					<< endl;
			cout << "Category:      "
					<< displayCategory(businessReview->getCategory()) << endl;
			cout << "Business Name:       " << businessReview->getBusinessName()
					<< endl;
			cout << "Description:   " << businessReview->getDescription()
					<< endl;
			cout << "Business City:       " << businessReview->getBusinessCity()
					<< endl;
			cout << "Business State:       "
					<< businessReview->getBusinessState() << endl;
			cout << "Reviewer's Name:       "
					<< businessReview->getReviewersName() << endl;
			cout << "Reviewer's City:       " << businessReview->getMyCity()
					<< endl;
			cout << "Reviewer's State:       " << businessReview->getMyState()
					<< endl;
			cout << "Date:       " << businessReview->getDate() << endl;
			cout << "Star Rating:       " << businessReview->getStarRating()
					<< endl;
			cout << "Reviewer's Comments:       "
					<< businessReview->getReviewersComments() << endl;
			cout << "---------------------------------------------" << endl;
			++counter;
		}
	}
	cout << "There are " << counter
			<< " number of businesses in this Category.";
	cin.ignore();
	return;
}

/*
 * This function searchs for and displays the data for a business, given the businessId by user input. If no business is found with the user
 * input businessId, an error message is displayed.
 */
void searchreview() {

	string busId;
	bool foundEntry = false;

	cout << endl << "** SEARCH FOR BUSINESS **" << endl << endl;
	cout << "Enter Business I.D.: ";

	getline(cin, busId, '\n');

	list<BusinessReview>::iterator businessReview;
	for (businessReview = reviewsList.begin();
			businessReview != reviewsList.end(); ++businessReview) {
		if (businessReview->getBusinessId() == busId) {
			foundEntry = true;
			cout << "Business I.D.:        " << businessReview->getBusinessId()
					<< endl;
			cout << "Category:      "
					<< displayCategory(businessReview->getCategory()) << endl;
			cout << "Business Name:       " << businessReview->getBusinessName()
					<< endl;
			cout << "Description:   " << businessReview->getDescription()
					<< endl;
			cout << "Business City:       " << businessReview->getBusinessCity()
					<< endl;
			cout << "Business State:       "
					<< businessReview->getBusinessState() << endl;
			cout << "Reviewer's Name:       "
					<< businessReview->getReviewersName() << endl;
			cout << "Reviewer's City:       " << businessReview->getMyCity()
					<< endl;
			cout << "Reviewer's State:       " << businessReview->getMyState()
					<< endl;
			cout << "Date:       " << businessReview->getDate() << endl;
			cout << "Star Rating:       " << businessReview->getStarRating()
					<< endl;
			cout << "Reviewer's Commenets:       "
					<< businessReview->getReviewersComments() << endl;
			cout << "---------------------------------------------" << endl;
		}
	}

	if (!foundEntry)
		cout << "Review with that Business I.D. not found." << endl;

	return;
}
/*
 * This function deletes a review from the linked list based on the given
 * businessId, using the list::erase function to delete the element while maintaining vailidity of all other pointers in the list.
 */
void deleteReview() {
	string busId;
	bool found = false;
	cout << endl << "** DELETE REVIEW **" << endl << endl;
	cout << "Enter Business I.D.: ";

	getline(cin, busId, '\n');

	list<BusinessReview>::iterator i = reviewsList.begin();
	while (i != reviewsList.end()) {
		if (i->getBusinessId() == busId) {
			reviewsList.erase(i++);
			cout << "Review deleted." << endl;
			found = true;
		} else
			++i;
	}

	if (!found)
		cout << "Review with that business I.D. not found." << endl;

	return;
}

/* This function deletes the first review in the list. It is called once in main to delete an empty review that is created.
 */

void deleteFirst() {
	string busId = "";

	list<BusinessReview>::iterator i = reviewsList.begin();
	while (i != reviewsList.end()) {
		if (i->getBusinessId() == busId) {
			reviewsList.erase(i++);
		} else
			++i;
	}

	return;
}
/*
 * This function displays all of the businessReviews that are contained in the
 * linked list.
 */
void displayAllReviews() {
	cout << endl << "** DISPLAY REVIEWS **" << endl << endl;

	list<BusinessReview>::iterator businessReview;
	for (businessReview = reviewsList.begin();
			businessReview != reviewsList.end(); ++businessReview) {

		cout << "Business I.D.:        " << businessReview->getBusinessId()
				<< endl;
		cout << "Category:      "
				<< displayCategory(businessReview->getCategory()) << endl;
		cout << "Business Name:       " << businessReview->getBusinessName()
				<< endl;
		cout << "Description:   " << businessReview->getDescription() << endl;
		cout << "Business City:       " << businessReview->getBusinessCity()
				<< endl;
		cout << "Business State:       " << businessReview->getBusinessState()
				<< endl;
		cout << "Reviewer's Name:       " << businessReview->getReviewersName()
				<< endl;
		cout << "Reviewer's City:       " << businessReview->getMyCity()
				<< endl;
		cout << "Reviewer's State:       " << businessReview->getMyState()
				<< endl;
		cout << "Date:       " << businessReview->getDate() << endl;
		cout << "Star Rating:       " << businessReview->getStarRating()
				<< endl;
		cout << "Reviewer's Comments:       "
				<< businessReview->getReviewersComments() << endl;
		cout << "---------------------------------------------" << endl;
	}

	return;
}

/*
 * This function provides the main menu for the user, displays the
 * options and accepts user input.
 */
void menu() {
	string userOption;
	bool exitProgram = false;

	while (!exitProgram) {
		// Allow the user to select options to add, edit, delete, display all, filter reviews by category and
		// search for a business within the linked list.
		cout << endl << "** Shout.com Business Reviews **" << endl << endl;
		cout << "   1. Enter Review" << endl;
		cout << "   2. Edit Review" << endl;
		cout << "   3. Delete Review" << endl;
		cout << "   4. Display All Reviews" << endl;
		cout << "   5. Filter Reviews by Category" << endl;
		cout << "   6. Search for Business" << endl;
		cout << endl << "   99. Exit program" << endl << endl;

		cout << "Option> ";
		getline(cin, userOption, '\n');

		// Process user entry
		switch (atoi(userOption.c_str())) {
		case 1:
			newreview();
			break;

		case 2:
			editreview();
			break;

		case 3:
			deleteReview();
			break;

		case 4:
			displayAllReviews();
			break;

		case 5:
			filterreview();
			break;

		case 6:
			searchreview();
			break;

			// Save list and then exit program
		case 99:
			savedata();
			exitProgram = true;
			break;

		default:
			cerr << "Invalid selection. " << endl;
			break;
		}
	}

	return;
}

//Function to display Category text as a string rather than the integer that is stored for the category variable.
string displayCategory(int category) {
	switch (category) {
	case 1:
		return "1: Restaurant";
		break;

	case 2:
		return "2: Bar";
		break;

	case 3:
		return "3: Fitness";
		break;

	case 4:
		return "4: Theater";
		break;

	case 5:
		return "5: Shopping";
		break;

	case 6:
		return "6: Deals and Discounts";
		break;

	case 7:
		return "7: Everything";
		break;

	default:
		return "invalid";
	}
}

/*Truncates old file if it exists, creates a file if no file exists, saves the list into the file and closes the file*/
void savedata() {
	fstream saveFile;
	saveFile.open("reviews.dat", ios::out);

	if (saveFile) {
		list<BusinessReview>::iterator i;
		for (i = reviewsList.begin(); i != reviewsList.end(); ++i) {
			saveFile << i->getBusinessId() << endl;
			saveFile << i->getCategory() << endl;
			saveFile << i->getBusinessName() << endl;
			saveFile << i->getDescription() << endl;
			saveFile << i->getBusinessCity() << endl;
			saveFile << i->getBusinessState() << endl;
			saveFile << i->getReviewersName() << endl;
			saveFile << i->getMyCity() << endl;
			saveFile << i->getMyState() << endl;
			saveFile << i->getDate() << endl;
			saveFile << i->getStarRating() << endl;
			saveFile << i->getReviewersComments() << endl;

		}
		saveFile.close();
		cout << "Reviews saved in reviews.dat. " << endl;
	} else
		cout << "Error saving reviews. ";
	cout << "Press Enter to continue...";
	cin.get();
	return;
}

/*
 *This function reads all data from the reviews.dat file into the linked list, if it exists.
 */
void loaddata() {

	fstream dataFile;
	string data;

	// Open the data file for reading if it exists.
	dataFile.open("reviews.dat", ios::in);

	if (dataFile) {
		while (!dataFile.eof()) {
			BusinessReview businessReview;

			getline(dataFile, data);
			businessReview.setBusinessId(data);
			getline(dataFile, data);
			businessReview.setCategory(atoi(data.c_str()));
			getline(dataFile, data);
			businessReview.setBusinessName(data);
			getline(dataFile, data);
			businessReview.setDescription(data);
			getline(dataFile, data);
			businessReview.setBusinessCity(data);
			getline(dataFile, data);
			businessReview.setBusinessState(data);
			getline(dataFile, data);
			businessReview.setReviewersName(data);
			getline(dataFile, data);
			businessReview.setMyCity(data);
			getline(dataFile, data);
			businessReview.setMyState(data);
			getline(dataFile, data);
			businessReview.setDate(data);
			getline(dataFile, data);
			businessReview.setStarRating(atoi(data.c_str()));
			getline(dataFile, data);
			businessReview.setReviewersComments(data);
			reviewsList.push_back(businessReview);
		}

		dataFile.close();
	}
	return;
}
