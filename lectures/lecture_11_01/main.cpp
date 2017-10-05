#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <fstream>

using namespace std;

const string NOHASHTAGFOUND = "No hashtag found";
const int NUM = 1000;
const int WHITESPACE = 40;
const int TOPLIMIT = 20;

string getnexthashtag(string inputline, unsigned int& pos);
int indexofhashtag(string hashtags[], int n, string h);
string stringtolower(string s);

void insertorupdatehashtags(string hashtags[], int hashtags_counter[], int& used_n, string h);

void insertionSort_string_asc(string sarray[], int iarray[], int length);
void insertionSort_int_dec(string sarray[], int iarray[], int length);

int main()
{
    unsigned int pos = 0;
    string inputline;
    string h;
    string hashtags[NUM];
    int hashtags_counter[NUM];
    int used_n = 0;

    ifstream inputfile;
    inputfile.open("/Users/Eyjo/Documents/Kennsla/Forritun/T208FOR2_03_2017/trump_twitter.txt");
    if (inputfile.fail()) {
        cout << "FAIL!" << endl;
        exit(1);
    }

    while (!inputfile.eof()) {
        getline(inputfile, inputline);
        pos = 0;

        h = getnexthashtag(inputline, pos);
        while (h != NOHASHTAGFOUND) {
            insertorupdatehashtags(hashtags, hashtags_counter, used_n, h);
            h = getnexthashtag(inputline, pos);
        }
    }

    inputfile.close();


    insertionSort_string_asc(hashtags, hashtags_counter, used_n);
    insertionSort_int_dec(hashtags, hashtags_counter, used_n);

    for (int i = 0; i < TOPLIMIT; i++) {

        cout << hashtags[i];
        for (unsigned int j = 0; j < WHITESPACE - hashtags[i].length(); j++) {
            cout << " ";
        }
        cout << " x " << hashtags_counter[i] << endl;
    }

    return 0;
}

void insertionSort_int_dec(string sarray[], int iarray[], int length) {
  int i, j;
  string stmp;
  int itmp;

  for (i = 1; i < length; i++) {
    stmp = sarray[i];
    itmp = iarray[i];
    j = i;
    while (j > 0 && iarray[j - 1] < itmp) {
      sarray[j] = sarray[j - 1];
      iarray[j] = iarray[j - 1];
      j--;
    }
    sarray[j] = stmp;
    iarray[j] = itmp;
  }
}

void insertionSort_string_asc(string sarray[], int iarray[], int length) {
  int i, j;
  string stmp;
  int itmp;

  for (i = 1; i < length; i++) {
    stmp = sarray[i];
    itmp = iarray[i];
    j = i;
    while (j > 0 && sarray[j - 1] > stmp) {
      sarray[j] = sarray[j - 1];
      iarray[j] = iarray[j - 1];
      j--;
    }
    sarray[j] = stmp;
    iarray[j] = itmp;
  }
}

void insertorupdatehashtags(string hashtags[], int hashtags_counter[], int& used_n, string h) {
    int index = indexofhashtag(hashtags, used_n, h);
    if (index == -1) {
        hashtags[used_n] = h;
        hashtags_counter[used_n] = 1;
        used_n = used_n + 1;
    }
    else {
        hashtags_counter[index] += 1;
    }
}

int indexofhashtag(string hashtags[], int n, string h) {
    for (int i = 0; i < n; i++) {
        if (stringtolower(hashtags[i]) == stringtolower(h)) {
            return i;
        }
    }
    return -1;
}

string stringtolower(string s) {
    for (unsigned int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}



string getnexthashtag(string inputline, unsigned int& pos) {
    unsigned int hashstart, hashend;
    hashstart = inputline.find("@", pos);
    if (hashstart < inputline.length()) {
        pos = hashstart+1;
        hashend = inputline.find_first_not_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", hashstart+1);
        return inputline.substr(hashstart, hashend - hashstart);
    }
    else {
        return NOHASHTAGFOUND;
    }
}
