#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

//not finished, need to continue developing, and then testing


//Implementation of a basic FS consisting of names of {files, directories, subdirectories}
//and supports ls, rm, mkdir
// Rules:
// mkdir - if file already exists, can't mkdir it again
// ls - alphabetical order of names, include timestmp as well (assume print to stdout for simplicity)
//    - also include -R flag for recursive printing of subdirectories and subfiles

class File{
public:
	File(string n): name(n){ }
	string GetName(){return name;}
protected:
	string name;


};


class Dir : public File{

public:
	Dir(string n) : File(n){}
	void mkdir(string n){
		//if already exists, exit
		AddDir(n);
	}
	void ls(){
		//do a DFS on each subdirectory, print all files
		for (int i = 0; i < dirs.size(); ++i){
			Dir cur_dir = dirs[i];
			for (int j = 0; j < cur_dir.files.size(); ++j){
				cout << cur_dir.files[j].GetName() << endl;
			}
			for (int j = 0; j < cur_dir.dirs.size(); ++j){
				cout << cur_dir.dirs[j].GetName() << endl;
				cur_dir = cur_dir.dirs[j];
				ls();
			}
		}


	}

private:
	void AddFile(string newFileName){
		File newFile(newFileName);
		files.push_back(newFile);
	}
	void AddDir(string newDirName){
		Dir newDir(newDirName);
		dirs.push_back(newDirName);
	}
	vector<Dir> dirs;
	vector<File> files;

};






class FileSystem : public Dir{

public:
	FileSystem() : Dir("root") {

	}

	~FileSystem(){}
	
private:
	

};






