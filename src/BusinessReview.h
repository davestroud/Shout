/**
 *  BusinessReview.h - Class definition for a business review.  This class will be
 *                 a single node in the linked list.
 * Programming Project
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 * Program: Collaboration of John David Stroud and Christopher Luke Graves.
 * The entire program was a collaboration between John David Stroud and Christopher Luke Graves. Every line of code has been
 * examined and tested by both parties. Denoting the specific pieces that came solely by one of the programmers would be not only time consuming and
 * difficult, but deminish the readibility and increase the difficulty of finding any errors that could exist without the programmers knowledge.
 * Resources: Our textbook along with "Starting out with C++: From Control Structures Through Objects, Eighth Edition by Tony Gaddis.
 */

#ifndef _BUSINESS_REVIEW_H_
#define _BUSINESS_REVIEW_H_

#include <iostream>
#include <string>

using namespace std;

class BusinessReview {
public:
	BusinessReview();
	BusinessReview(const BusinessReview &businessReview);
	~BusinessReview();

	void setBusinessId(const string businessId);
	string getBusinessId() const;
	string genBusinessId() const;

	void setCategory(const int category);
	int getCategory() const;

	void setBusinessName(const string businessName);
	string getBusinessName() const;

	void setDescription(const string description);
	string getDescription() const;

	void setBusinessCity(const string businessCity);
	string getBusinessCity() const;

	void setBusinessState(const string businessState);
	string getBusinessState() const;

	void setReviewersName(const string reviewersName);
	string getReviewersName() const;

	void setMyCity(const string myCity);
	string getMyCity() const;

	void setMyState(const string myState);
	string getMyState() const;

	void setDate(const string date);
	string getDate() const;
	string inputDate();

	void setStarRating(const int starRating);
	int getStarRating() const;

	void setReviewersComments(const string reviewersComments);
	string getReviewersComments() const;

private:
	string businessId;
	int category;
	string businessName;
	string description;
	string businessCity;
	string businessState;
	string reviewersName;
	string myCity;
	string myState;
	string date;
	int starRating;
	string reviewersComments;
};

#endif

