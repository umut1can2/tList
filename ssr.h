/*
 * Adding..
 * _Change Data
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class List
{
public:
	List(string f,string c);
	string filePathJobs;
        string filePathCheck;
	string getfPath();
	void writeNewJob(string job,bool check);
        void getDatas();
        void changeJob(string newJob,int jobsLine);
};

List::List(string f,string c)
{
this->filePathJobs=f;
this->filePathCheck=c;
}

string List::getfPath()
{
        string allPaths = this->filePathJobs + "\n" + this->filePathCheck;
	return allPaths;
}

void List::writeNewJob(string job,bool check)
{
	fstream j,c;
        
        const char* chrJ = filePathJobs.c_str(); //String to const char * conversion for filePathJobs
        const char* chrC = filePathCheck.c_str(); //String to const char * conversion for filePathJobs
        
	j.open(chrJ, ios::app);
	c.open(chrC, ios::app);

	j << job << "\n";
	c << check << "\n";

	j.close();
	c.close();

}

void List::getDatas()
{
    string line;
    vector<string>jobS;
    vector<string>check;
    
    const char* chrJ = filePathJobs.c_str();
    const char* chrC = filePathCheck.c_str();
    
    fstream jobStream,checkStream;
    jobStream.open( chrJ );
    checkStream.open( chrC );
        
    while (!jobStream.eof())
    {
        getline(jobStream,line);
        jobS.push_back(line);
    }
    jobS.pop_back();
    jobStream.close();
        
    while (!checkStream.eof())
    {
        getline(checkStream,line);
        check.push_back(line);
    }
    check.pop_back();
    checkStream.close();

        cout << "T0D0 List" << endl;
        
        for(int var=0; var < jobS.size(); ++var){
            cout  << jobS.at(var) << "  |  " << check.at(var) << endl;
        }
}

void List::changeJob(string newJob,int jobsLine){
    /*
     * Ne yapacağız burada
     * _dosyadan verilerimizi aldıktan sonra, aldığımız yeni işi eski işin yerine yazdırıp dosyaya yazdıracağız.
     */
    string line;
    vector<string>jobS;
    
    const char* chrJ = filePathJobs.c_str();

    fstream jobStream;
    jobStream.open( chrJ );
        
    while (!jobStream.eof())
    {
        getline(jobStream,line);
        jobS.push_back(line);
    }
    jobS.pop_back();
    jobStream.close();    
    
    jobS.at(jobsLine)=newJob;//eski işi yenisi ile değiştir.
    
    fstream deleteandCreateFileDesc;
    deleteandCreateFileDesc.open(chrJ);
    
    for(int var = 0; var < jobS.size(); ++var)
    {
        deleteandCreateFileDesc << jobS.at(var) << endl;
    }
    
}
