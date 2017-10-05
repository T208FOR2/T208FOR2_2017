#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string NOHASHTAGFOUND = "No hashtag found";
const int NUM = 1000;

string getnexthashtag(string inputline, unsigned int& pos);
int indexofhashtag(string hashtags[], int n, string h);
string stringtolower(string s);

void insertorupdatehashtags(string hashtags[], int hashtags_counter[], int& used_n, string h);

void insertionSort(string sarray[], int iarray[], int length);

int main()
{
    unsigned int pos = 0;
    string inputline = "Something #One, #Two, #two, #TWO #Three#Four...#Five and something";
//    string inputline = "This is a line withouth hashtags.";
    string h;
    string hashtags[NUM];
    int hashtags_counter[NUM];
    int used_n = 0;

    h = getnexthashtag(inputline, pos);
    while (h != NOHASHTAGFOUND) {
        insertorupdatehashtags(hashtags, hashtags_counter, used_n, h);
        h = getnexthashtag(inputline, pos);
    }

    insertionSort(hashtags, hashtags_counter, used_n);

    for (int i = 0; i < used_n; i++) {
        cout << hashtags[i] << " - x" << hashtags_counter[i] << endl;
    }

    return 0;
}

void insertionSort(string sarray[], int iarray[], int length) {
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
    hashstart = inputline.find("#", pos);
    if (hashstart < inputline.length()) {
        pos = hashstart+1;
        hashend = inputline.find_first_not_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", hashstart+1);
        return inputline.substr(hashstart, hashend - hashstart);
    }
    else {
        return NOHASHTAGFOUND;
    }
}
