#include "../include/file_search.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>
using namespace std;
namespace fs = filesystem;
mutex output_mutex;
void search_in_file(const string& file_path, const string& keyword){
    string ext = filesystem::path(file_path).extension().string();
     vector<string> textExtensions = {".txt", ".cpp", ".h", ".md", ".log", ".py", ".java", ".json"};
     if(find(textExtensions.begin(), textExtensions.end(), ext) == textExtensions.end()) {
        return;
     }

    ifstream file(file_path);
    if(!file.is_open()){
        return;
    }
    string line;
    int line_number = 0;
    while (getline(file,line)){
        line_number++;
        if(line.find(keyword) != string::npos){
            lock_guard<mutex> lock(output_mutex);
            cout<<"[Thread"<<this_thread::get_id()<<"]"<<file_path<<"Line number:"<<line_number<<":"<<line<<endl;
        }
    }    
}

void search_files(const string& rootDir,const string& keyword){
vector<thread> threads;
for(const auto& entry:fs::recursive_directory_iterator(rootDir)){
    if(entry.is_regular_file()){
        threads.emplace_back(search_in_file,entry.path().string(),keyword);
    }
    for(auto& t: threads){
        if(t.joinable()){
            t.join();
        }
    }
}
}