#include "../include/file_search.hpp"
#include <iostream>
using namespace std;
int main(){
    string rootDir;
    string keyword;

    cout << "Enter the root directory to search in: ";
    cin >> rootDir;
    cout << "Enter the keyword to search for: ";
    cin >> keyword;
    search_files(rootDir,keyword);
    return 0 ;
}