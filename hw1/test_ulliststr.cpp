#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

ULListStr * makeList(std::vector<std::string> const & values, bool pushBack)
{
	// circular list is not copyable so we have to pass it by pointer
	ULListStr * list = new ULListStr();

	if(pushBack)
	{
		for(std::vector<std::string>::const_iterator valuesIter = values.cbegin(); valuesIter != values.cend(); ++valuesIter)
		{
			list->push_back(*valuesIter);
		}
	}
	else
	{
		// push values in reverse from the front
		for(std::vector<std::string>::const_reverse_iterator valuesIter = values.crbegin(); valuesIter != values.crend(); ++valuesIter)
		{
			list->push_front(*valuesIter);
			cout<<"The size of the list is : "<<list->size()<<endl;
			cout<<"The front of the list is : "<<list->front()<<endl;
		}
	}

	return list;
}

bool checkListContent(ULListStr *const list, std::vector<std::string> const &expectedValues)
{
	if(list->size() != expectedValues.size())
	{
		 cout<< "Size mismatch! Expected " << expectedValues.size() << " elements, got " << list->size() << " elements.";
		 return false;
	}

	// aggregate all mismatches into one failure message
	std::stringstream failureMessage;
	failureMessage << "List content mismatch: ";
	bool contentMismatch = false;

	for(size_t index = 0; index < list->size(); ++index)
	{
		if(list->get(index) != expectedValues[index])
		{
			failureMessage << "Expected value at index " << index << " was " << expectedValues[index] << ", but element was actually " << list->get(index) << std::endl;
			contentMismatch = true;
		}
	}

	if(contentMismatch)
	{
		 cout<< failureMessage.str();
		 return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
		// first we create a vector to hold our data
	std::vector<std::string> contents{"768", "1024", "1536"};

	// then we create a new list with that data
	ULListStr * populatedList = makeList(contents, false);

		for(int i = 0;i<populatedList->size();i++)
		{
			cout<<populatedList->get(i)<<"  "<<endl;
		}
	// then we assert that the list contains that data
	if(checkListContent(populatedList, contents))
	cout<<"Test success"<<endl;
	else
	cout<<"Test failed"<<endl;

	delete populatedList;
}
