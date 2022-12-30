#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int totalPages;     // total number of pages there are
    cin >> totalPages;
    int currentPage;    // the current page on
    cin >> currentPage;
    int numPagesDisplayed;  // how many pages are displayed on each side of the current page
    cin >> numPagesDisplayed;

    int firstPageDisplayed = currentPage - numPagesDisplayed;   // the first page displayed
    if(firstPageDisplayed > 1) {    // if the first page isn't displayed, print "<<"
        cout << "<< ";
    } else if(firstPageDisplayed < 1) { // if the first page is calculated to be below 1, then set it to 1
        firstPageDisplayed = 1;
    }

    int pageIndex;  // iterator variable
    for(pageIndex = firstPageDisplayed; pageIndex < currentPage; ++pageIndex) { // print out all the pages before the current page
        cout << pageIndex << " ";
    }

    cout << "(" << currentPage << ") ";  // print the current page

    int lastPageDisplayed = currentPage + numPagesDisplayed;    // the last page displayed
    lastPageDisplayed = min(lastPageDisplayed, totalPages);
    for(pageIndex = currentPage + 1; pageIndex <= lastPageDisplayed; ++pageIndex) {
        cout << pageIndex << " ";
    }

    if(lastPageDisplayed < totalPages) {
        cout << ">>" << endl;
    }
    return 0;
}
