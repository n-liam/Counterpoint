#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <map>
#include <stdio.h>
#include <stdlib.h>


#include"headers\ABCFileInfo.h"
#include "headers\otherOtherFunctions.h"
#include"headers\notes.h"
#include"headers\otherFunctions.h"

int main()
{
	using namespace std;
	
	ABCFileInfo::TimeSignature meter;
	ABCFileInfo::Key key;

    ofstream outf("counterpoint.abc");
	ifstream inf("cantusFirmus.abc");
 


	
 
    if (!outf)
    {
        cerr << "counterpoint.abc could not be opened for writing!" << endl;
        exit(1);
    }
	if (!inf)
    {
        cerr << "cantusFirmus.abc could not be opened for reading!" << endl;
        exit(1);
    }
	
    while (inf)
	{

		string strInput;
		getline(inf,strInput);
		if(strInput[0]==77) // 77 -> M for meter
		{
			meter = getTimeSignature(strInput);
		}
		if(strInput[0]==75) // 75 -> K for Key
		{
			key = getKey(strInput);
		}
		outf<<"\n"<< strInput;
	}
	outf<<"V:2 name=\"counterpoint\" \n";
	inf.clear();
	inf.seekg(0, inf.beg);
	char singleCharacter = ' ';
	
	while(singleCharacter != 'V')
	{
		
		inf.get(singleCharacter);
	}
	inf.seekg(2,ios::cur);
	inf.get(singleCharacter);
	
	while(singleCharacter != 'V')
	{
		inf.get(singleCharacter);
	}
	inf.seekg(4,ios::cur);
	
	while(singleCharacter != '#')
	{
		inf.get(singleCharacter);
		//outf<<singleCharacter;//<<"->";
		if( isVerbatimChar(singleCharacter) )
			{ outf<< singleCharacter;}
		else
		{
			outf<<getNote(singleCharacter);
		}
		
	}
 
    return 0;
}