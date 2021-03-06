// Name: Ali Fenton
// Date: October 23,2015
// Programming Practice - File IO  B


#include <iostream> // cin, cout
#include <fstream> // files
#include <cstdlib> //exit(1)
#include <string> // string
#include <iomanip> // setw()

using namespace std;

int main(){
    
    ifstream fin;
    ofstream fout;
    char userFile[12];
    string firstName, lastName, maxStudent;
    double score1, score2, score3, score4, score5, score6, average, maxAverage;
    
    cout << "Enter a file name you would like to get." << endl;
    cin >> userFile;
    
    fin.open(userFile);
    fout.open("result.txt");
    
    //seeing if the input or output will fail
    if(fin.fail()){
        cout << "Error opening for the input file." << endl;
        exit(1);
    }
    
    if(fout.fail()){
        cout << "Error opening for the output file." << endl;
        exit(1);
    }
    
    while(fin >> firstName >> lastName >> score1 >> score2 >> score3 >> score4 >> score5 >> score6){
        average = (score1 + score2 + score3 + score4 + score5 + score6) / 6; //Fidning the average of points
    
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        fout.setf(ios::left);
        
        fout << setw(15) << firstName << setw(15) << lastName << setw(8) << score1 << setw(8) << score2 << setw(8) << score3 
             << setw(8) << score4 << setw(8) << score5<< setw(8) << score6 << setw(8) << average << endl;
             
       //Finding the highest score
       if(average > maxAverage){
            maxStudent = firstName + " " + lastName;
            maxAverage = average;
       }else{
            maxAverage;
       }
    }
    
    fout << "\nHighest score: " << maxStudent << endl;
    
    fin.close();
    fout.close();
    
    return 0;
}
