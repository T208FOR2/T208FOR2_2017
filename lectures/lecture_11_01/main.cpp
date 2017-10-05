#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

// This program takes as input a textfile with some twitterfeed
// The program finds all hashtags, counts them and prints out the
// most popular hashtags used (in decreasing order).

// Constants (the filename for the input file and maximum number of unique hashtags)
const string THEFILENAME = "twitterfeed.txt";
const int NUM = 1000;Ê // maximum number of unique hashtags
const string NOHASHTAG = "no hashtag";Ê // string constant if we don't find a hashtag
const int WHITESPACE = 40;Ê // how far to the right the counter appears
const int TOPCOUNT = 30;Ê // how many hashtags should we print

// Open the input file and check if it is ok
void openinputfile(ifstream& inputfile, string thefilename);

// Get the next hashtag from a string (starting from pos + updating pos)
string getnexthashtag(string texti, unsigned int& pos);

// Returns the index of newelement in the array tags, -1 if it is not there
int indexofelement(string tags[], int n, string newelement);

// Adds newelement to tags and increases counts and numberofelements if newelement is not in tags
// otherwise it just increases the counts for that tag
void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements);

// Sorting, two functions, one sorts on the int array, the other on the string array
void insertionSort_int_dec(int array[], string tags[], int length);
void insertionSort_str_asc(int array[], string tags[], int length);

// Takes a string and turns it into lowercase, used for comparing two hashtags
string stringtolower(string s);


int main() {
Ê Ê // Define variables
Ê Ê ifstream inputfile;
Ê Ê string tag, t, hashtags[NUM];
Ê Ê int hashcount[NUM], numberofelements = 0;
Ê Ê unsigned int pos;

Ê Ê // Initialize arrays
Ê Ê for (int i = 0; i < NUM; i++) {
Ê Ê Ê Ê hashtags[i] = "";
Ê Ê Ê Ê hashcount[i] = 0;
Ê Ê }

Ê Ê openinputfile(inputfile, THEFILENAME);

Ê Ê // Read through the input file
Ê Ê while (!inputfile.eof()) {
Ê Ê Ê Ê getline(inputfile, t);Ê // get one line at a time from the file

Ê Ê Ê Ê pos = 0; // initialize the position for the current line
Ê Ê Ê Ê tag = getnexthashtag(t, pos);Ê // find the first hashtag in the line
Ê Ê Ê Ê while (tag != NOHASHTAG) Ê Ê // while we have some hashtags...
Ê Ê Ê Ê {
Ê Ê Ê Ê Ê Ê // Add to array if tag is new, otherwise update counter
Ê Ê Ê Ê Ê Ê insertorupdatearrays(hashtags, hashcount, tag, numberofelements);

Ê Ê Ê Ê Ê Ê tag = getnexthashtag(t, pos);Ê // get the next hashtag in the current line
Ê Ê Ê Ê }
Ê Ê }

Ê Ê // If we first sort the two arrays by the hashtags (alphabetically) and
Ê Ê // then by count (decreasing) we get all tags with the same count in
Ê Ê // alphabetical order.
Ê Ê insertionSort_str_asc(hashcount, hashtags, numberofelements);Ê // Sort by tags (alphabetically)
Ê Ê insertionSort_int_dec(hashcount, hashtags, numberofelements);Ê // Sort by count (decreasing)

Ê Ê for (int i = 0; i < TOPCOUNT; i++) Ê // Print out the top tags
Ê Ê {
Ê Ê Ê Ê cout << hashtags[i];Ê // Print the hashtag

Ê Ê Ê Ê // Print whitespace so that the counters line up
Ê Ê Ê Ê for (unsigned int j = 0; j < WHITESPACE - hashtags[i].length(); j++) {
Ê Ê Ê Ê Ê Ê cout << " ";
Ê Ê Ê Ê }
Ê Ê Ê Ê cout << " x " << hashcount[i] << endl;Ê // print the counter
Ê Ê }

Ê Ê inputfile.close();

Ê Ê return 0;
}


void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements)
{
Ê Ê // get the index of newelement (-1 if it is not in the array tags)
Ê Ê int index = indexofelement(tags, numberofelements, newelement);

Ê Ê if (index >= 0) { // Hashtag exists -> increase counter
Ê Ê Ê Ê counts[index]++;
Ê Ê }
Ê Ê else if (numberofelements < NUM) { Ê // Add new hashtag (if there is space)
Ê Ê Ê Ê tags[numberofelements] = newelement;
Ê Ê Ê Ê counts[numberofelements] = 1;
Ê Ê Ê Ê numberofelements++;
Ê Ê }
Ê Ê else {Ê // Running out of space - can't add new hashtag
Ê Ê Ê Ê cout << "The number of unique hashtags is more than the limit of " << NUM << endl;
Ê Ê }
}

// Return the next hashtag in the string texti, starting at position pos
string getnexthashtag(string texti, unsigned int& pos)
{
Ê Ê unsigned int hashstart = texti.find("#",pos);Ê // hashtags start with #
Ê Ê if (hashstart < texti.length()) {
Ê Ê Ê Ê // We've found the start of a hashtag, let's find where it ends
Ê Ê Ê Ê unsigned int hashend = texti.find_first_of(" .,\n\"#;?!:'", hashstart+1);
Ê Ê Ê Ê pos = hashend; // Update the call-by-reference variable pos (to be ready for next iteration)
Ê Ê Ê Ê return texti.substr(hashstart, hashend - hashstart);Ê // return the hashtag
Ê Ê }
Ê Ê else {
Ê Ê Ê Ê return NOHASHTAG;Ê // Return something to indicate that there are no more hashtags in this string
Ê Ê }
}

// Find the index of an element in an array, return -1 if not found
int indexofelement(string tags[], int n, string newelement) {
Ê Ê for (int i = 0; i < n; i++) {
Ê Ê Ê Ê // compare hashtags using lowercase, to eliminate duplications
Ê Ê Ê Ê if (stringtolower(tags[i]) == stringtolower(newelement)) {
Ê Ê Ê Ê Ê Ê return i;Ê // return the correct index
Ê Ê Ê Ê }
Ê Ê }
Ê Ê return -1;Ê // if not found, return -1
}




// Classic insertion sort, here sorting two arrays
void insertionSort_int_dec(int counts[], string tags[], int length) {
Ê Ê int i, j, tmp_int;
Ê Ê string tmp_str;

Ê Ê for (i = 1; i < length; i++)
Ê Ê {
Ê Ê Ê Ê tmp_int = counts[i];
Ê Ê Ê Ê tmp_str = tags[i];

Ê Ê Ê Ê j = i;
Ê Ê Ê Ê while (j > 0 && counts[j - 1] < tmp_int)
Ê Ê Ê Ê {
Ê Ê Ê Ê Ê Ê counts[j] = counts[j - 1];
Ê Ê Ê Ê Ê Ê tags[j] = tags[j - 1];
Ê Ê Ê Ê Ê Ê j--;
Ê Ê Ê Ê }
Ê Ê Ê Ê counts[j] = tmp_int;
Ê Ê Ê Ê tags[j] = tmp_str;
Ê Ê }
}

// And again sorting, here on the string array
void insertionSort_str_asc(int counts[], string tags[], int length) {
Ê Ê int i, j, tmp_int;
Ê Ê string tmp_str;

Ê Ê for (i = 1; i < length; i++)
Ê Ê {
Ê Ê Ê Ê tmp_int = counts[i];
Ê Ê Ê Ê tmp_str = tags[i];

Ê Ê Ê Ê j = i;
Ê Ê Ê Ê while (j > 0 && tags[j - 1] > tmp_str)
Ê Ê Ê Ê {
Ê Ê Ê Ê Ê Ê counts[j] = counts[j - 1];
Ê Ê Ê Ê Ê Ê tags[j] = tags[j - 1];
Ê Ê Ê Ê Ê Ê j--;
Ê Ê Ê Ê }
Ê Ê Ê Ê counts[j] = tmp_int;
Ê Ê Ê Ê tags[j] = tmp_str;
Ê Ê }
}


// Open the inputfile and check if it opened ok
void openinputfile(ifstream& inputfile, string thefilename)
{
Ê Ê inputfile.open(thefilename.c_str());

Ê Ê if (inputfile.fail())
Ê Ê {
Ê Ê Ê Ê cout << "Can't open " << thefilename << endl;
Ê Ê Ê Ê exit(1);
Ê Ê }
}

// Take a string variable (call-by-value) and return a lowercase copy of it.
string stringtolower(string s)
{
Ê Ê for (int i = 0; i < s.length(); i++)
Ê Ê {
Ê Ê Ê Ê s[i] = tolower(s[i]);
Ê Ê }
Ê Ê return s;
}



