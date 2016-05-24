// Jake Stocker
// pageReplacement Algorithm
// 3/7/2016
// Program emulates the On Demand Page Replacement Algorithm used by Operating Systems
// Input is recieved from requests.txt


#include <iostream>
#include <fstream>
#include <stdlib.h>


int IncrementIterator(int&);

using namespace std;

int main()
{
	
// DECLARATIONS ------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	int Pagein = 0;  // requests.txt Page Request 
	bool PageHit = false;  // Page hit per circular array iteration				  
	int PageTable[10];   // Pages in memory
	int SecondChanceBit[10];  // bits set to rather or not second chance given
	int Iterator = 0;  // current page pointed to
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	
// FILE INPUT ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	ifstream requests;
	requests.open("requests.txt");  // open file for read in
	if (!requests.is_open())
	{
		cout << "Error Opening file for input";
		exit(1);
	}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		// initalize SecondChanceBit to 0(none) and PageTable to -1
		for (int i = 0; i < 10; ++i)
		{
			PageTable[i] = -1;
			SecondChanceBit[i] = 0;
		}
		while (!requests.eof())
		{
			requests >> Pagein;
			// ensure requests is within proper bounds
			if (Pagein < 0 || Pagein > 99)
			{
				cout << "Invalid Page Request outside the possible range (0 - 100)";
				exit(1);
			}
			// search each of the 10 frames for a match
			for (int i = 0; i < 10; ++i)
			{

				if (PageTable[Iterator] == Pagein)
				{
					// page hit prepare the Rbit 
					SecondChanceBit[Iterator] = 1;
					cout << Pagein << ":" << " page hit, page " << Pagein << " is in Frame " << Iterator << endl;
					PageHit = true;
					//system("pause");
					//cin.get();
					IncrementIterator(Iterator);
					break;  // exit from searching frames
				}
				// increment and Keep circular queue
				IncrementIterator(Iterator);
			}
			if (!PageHit)
			{
				// Keep looping through second chance until we find a frame without one
				while (SecondChanceBit[Iterator] == 1)  // Is R bit set for second Chance?
				{
					SecondChanceBit[Iterator] = 0;     // reset the bit as second chance is granted
					cout << "Second Chance granted to Frame " << Iterator << endl;

					//system("pause");
					//cin.get();
					IncrementIterator(Iterator);

				}
				if (PageTable[Iterator] == -1) // Page is empty
				{
					cout << Pagein << ":" << " page miss, page " << Pagein << " replaces empty page in frame " << Iterator << endl;
					PageTable[Iterator] = Pagein;
					IncrementIterator(Iterator);
					//system("pause");
					//cin.get();
				}
				else // page isn't empty
				{

					// no page hit so page miss replace
					cout << Pagein << ":" << " page miss, page " << Pagein << " replaces page " << PageTable[Iterator] << " is in frame " << Iterator << endl;
					PageTable[Iterator] = Pagein;

					// move to next frame 
					IncrementIterator(Iterator);
					//system("pause");
					//cin.get();
				}

			}
				// set to false for next page request check for one in circular array
				PageHit = false;
		}
	return 0;
}



// increment in a circular array
int IncrementIterator(int& Iterator)
{
	if (Iterator == 9)
	{
		return Iterator = 0;
	}
	else
	{
		return ++Iterator;
	}
}