#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

#include"ABCFileInfo.h"

/////////////////////////////////////////////////////////
// TIME SIGNATURE
///////////////////////////////////////////////////////
ABCFileInfo::TimeSignature getTimeSignature(std::string strInput)
{
	assert(strInput[0]==77); // M
	assert(strInput[1]==58); // :
	assert(strInput[3]==47); // /
	switch (strInput[2])
	{
		
		case 50: //2
			switch (strInput[4])
			{
				case 52: //4
					return ABCFileInfo::TWO_FOUR;
					break;
				default:
					return ABCFileInfo::UNKNOWN_METER;
					break;
			}
			break;
			
		case 51: //3
			switch (strInput[4])
			{
				case 52: //4
					return ABCFileInfo::THREE_FOUR;
					break;
				case 56: //8
					return ABCFileInfo::THREE_EIGHT;
					break;
				default:
					return ABCFileInfo::UNKNOWN_METER;
					break;
			}
			break;
			
		case 52: //4
			switch (strInput[4])
			{
				case 52: //4
					return ABCFileInfo::FOUR_FOUR;
					break;
				default:
					return ABCFileInfo::UNKNOWN_METER;
					break;
			}
			break;
			
		default:
			return ABCFileInfo::UNKNOWN_METER;
			break;
		
	}
	
	}

	
//////////////////////////////////////////////////////////////
//// KEY SIGNATURE
/////////////////////////////////////////////////
ABCFileInfo::Key getKey(std::string strInput)
{
	assert(strInput[0] == 75); // K
	assert(strInput[1] == 58); // :

	switch (strInput.size() )
	{
		case 3:
			switch (strInput[2])
			{
				case 65: //A
					return ABCFileInfo::A;
					break;
					
				case 66: //B
					return ABCFileInfo::B;
					break;
				
				case 67: //C
					return ABCFileInfo::C;
					break;
					
				case 68: //D
					return ABCFileInfo::D;
					break;
					
				case 69: //E
					return ABCFileInfo::E;
					break;
					
				case 70: //F
					return ABCFileInfo::F;
					break;
					
				case 71: //G
					return ABCFileInfo::G;
					break;
				
				default:	
					std::cout<<"E3";
					return ABCFileInfo::UNKNOWN_KEY;
					break;
			}
		case 4:
			switch (strInput[2])
			{
				case 65: //A
					return ABCFileInfo::Am;
					break;
					
				case 66: //B
					return ABCFileInfo::Bm;
					break;
				
				case 67: //C
					return ABCFileInfo::Cm;
					break;
					
				case 68: //D
					return ABCFileInfo::Dm;
					break;
					
				case 69: //E
					return ABCFileInfo::Em;
					break;
					
				case 70: //F
					return ABCFileInfo::Fm;
					break;
					
				case 71: //G
					return ABCFileInfo::Gm;
					break;
				
				default:
					std::cout<<"E2";
					return ABCFileInfo::UNKNOWN_KEY;
					break;
			}
		default:
			std::cout<<"ERROR: Check length of the \"K\" line in the .abc file.";
			return ABCFileInfo::UNKNOWN_KEY;
	}
}

/////////////////////////////////////////
// octave and noteValue to character
////////////////////////////////////////

char octAndValueToChar( int octave, int value)
{
	if ( value >=8)
	{
		octave -=1;
		value = value%7;
		

	}
	if(value ==0){ value =7;}
	std::cout<<value; //Getting -1 input
	if(octave == 1)
	{
		switch (value)
		{
			case 1:
				return 'C';
				break;
			case 2:
				return 'D';
				break;
			case 3:
				return 'E';
				break;
			case 4: 
				return 'F';
				break;
			case 5:
				return 'G';
				break;
			case 6:
				return 'A';
				break;
			case 7:
				return 'B';
				break;
			default:
				std::cout<<"Error";
				return '#';
			
		}
		
	}
	else if(octave == 2)
	{
		switch (value)
		{
			case 1:
				return 'c';
				break;
			case 2:
				return 'd';
				break;
			case 3:
				return 'e';
				break;
			case 4: 
				return 'f';
				break;
			case 5:
				return 'g';
				break;
			case 6:
				return 'a';
				break;
			case 7:
				return 'b';
				break;
			default:
				std::cout<<"Error";
				return '#';
			
		}
	}
	else
	{
		std::cout<<"ERROR INVALID OCTAVE (octave!= 1,2)";
		return '#';
	}
	
	
	
	
	
}


/////////////////////////////////////////
// is "verbatim" char
////////////////////////////
bool isVerbatimChar(char ichar)
{
	if( ichar == ' '){ return true;}
	else if( ichar<=57 && ichar >= 48){return true;}
	else if(ichar==124){return true;}
	else if(ichar==10){return true;}
	else if(ichar=='='){return true;}
	else if(ichar ==']'){return true;}
	else if(ichar =='%'){return true;}
	else if(ichar =='#'){return true;}
	else {return false;}

}


/////////////////////////
//is "note" char
//////////////////////////////////
bool isNoteChar(char ichar)
{
	if (ichar>=65 && ichar<=90){return true;}
	else if (ichar>=97 && ichar<=122){return true;}
	else {return false;}
	
}



/////////////////////////////////////////
// CHAR TO NOTE
////////////////////////////////////////
Note charToNote(char ichar)
{
	Note currentNote = Note(-1,1);
	switch (ichar)
	{
		case 'a':
			currentNote = Note(6,2);
			break;
		case 'b':
			currentNote =  Note(8,2);
			break;
		case 'c':
			currentNote =  Note(1,2);
			break;
		case 'd':
			currentNote =  Note(2,2);
			break;
		case 'e':
			currentNote =  Note(3,2);
			break;
		case 'f':
			currentNote =  Note(4,2);
			break;
		case 'g':
			currentNote =  Note(5,2);
		case 'A':
			currentNote =  Note(6,1);
			break;
		case 'B':
			currentNote =  Note(7,1);
			break;
		case 'C':
			currentNote =  Note(1,1);
			break;
		case 'D':
			currentNote =  Note(2,1);
			break;
		case 'E':
			currentNote =  Note(3,1);
			break;
		case 'F':
			currentNote =  Note(4,1);
			break;
		case 'G':
			currentNote =  Note(5,1);
			break;
		default:
			std::cout<< "\n"<<ichar<<"\n";
			currentNote =  Note(-1,1);
			break;
	}
	if(currentNote.m_octave > Note::s_prevCantusOctave){ Note::s_cantusDirection =1;}
	else if(currentNote.m_octave < Note::s_prevCantusOctave){ Note::s_cantusDirection =-1;}
	else
	{
		if(currentNote.m_unison > Note::s_prevCantusValue){ Note::s_cantusDirection = 1;}
		else if(currentNote.m_unison < Note::s_prevCantusValue){ Note::s_cantusDirection = -1;}
		else
			{Note::s_cantusDirection = 0;}
	}
	Note::s_prevCantusValue = currentNote.m_unison;
	Note::s_prevCantusOctave = currentNote.m_octave;
	//std::cout<<Note::s_cantusDirection;
	return currentNote;
}


//////////////////////////////////////////
// NOTE TO CHAR
/////////////////////////////////////////
char noteToChar(Note inote, int interval=1, int direction =1)
{
	bool octaveIncrease = false;
	bool octaveDecrease = false;
	if(inote.m_unison == -1){std::cout<<"GARBAGENOTE\n"; return '%';}
	switch(direction)
	{
		case 1:
			if(inote.m_unison +interval-1 >7){octaveIncrease = true;}
			break;
		case -1:
			if(inote.m_unison -(interval-1) <= 0){ octaveDecrease = true;}
			break;
		case 0:
			break;
		default:
			std::cout << "Direction not 1,-1,or0";
			break;
	}
	int noteValue = -1;

	int octave = inote.m_octave;
	if (octaveIncrease && octaveDecrease)
	{
		std::cout<<"\n[["<<inote.m_unison<<","<< interval<<"]]\n"<<"ERROR this is stupid, should never happen, try harder\n";
	}
	else if(octaveIncrease)
	{
		octave += octave;
	}
	else if(octaveDecrease)
	{
		octave -= octave;
	}

	
	
	
	switch (interval)
	{
		case 1:
			noteValue = inote.m_unison;
			break;
		case 2:
			noteValue = inote.m_second;
			break;
		case 3:
			noteValue = inote.m_third;
			break;
		case 4:
			noteValue = inote.m_fourth;
			break;
		case 5:
			noteValue = inote.m_fifth;
			break;
		case 6:
			noteValue = inote.m_sixth;
			break;
		case 7:
			noteValue = inote.m_seventh;
			break;
		default:
			noteValue = -1;
			break;
	}
	return octAndValueToChar(octave, noteValue);

}


///////////////////////////////////////////////
// GET NOTE
//////////////////////////////////////////////

char getNote( char ichar)
{

	Note inote = charToNote(ichar);
	
	
	int stepwiseMotion = rand() % 5; // 0,1,2,3,4
	if(stepwiseMotion <4)
	{
		inote.m_valid3 = false;
		inote.m_valid4 = false;
		inote.m_valid5 = false;
		inote.m_valid6 = false;
		inote.m_valid7 = false;
		
		inote.m_Dvalid3 = false;
		inote.m_Dvalid4 = false;
		inote.m_Dvalid5 = false;
		inote.m_Dvalid6 = false;
		inote.m_Dvalid7 = false;
	}
	
	int useContraryMotion = rand() % 5; // 0,1,2,3,4
	int counterpointDirection =0;
	if (useContraryMotion <4)
	{
		counterpointDirection = - Note::s_cantusDirection;
	}
	else
	{
		counterpointDirection = Note::s_cantusDirection;
	}
	if (counterpointDirection ==1)
	{
		inote.m_Dvalid2 = false;
		inote.m_Dvalid3 = false;
		inote.m_Dvalid4 = false;
		inote.m_Dvalid5 = false;
		inote.m_Dvalid6 = false;
		inote.m_Dvalid7 = false;
	}
	else if (counterpointDirection == -1)
	{
		inote.m_valid2 = false;
		inote.m_valid3 = false;
		inote.m_valid4 = false;
		inote.m_valid5 = false;
		inote.m_valid6 = false;
		inote.m_valid7 = false;
		
	}
	inote.listCheck();
	
	int randomNumber = rand() % inote.m_remainingIntervalsIndex;
	//std::cout << randomNumber;
	char ochar = noteToChar(inote, randomNumber, counterpointDirection);
	
	/*
	switch(randomNumber)
	{
		case 0:
			ochar = noteToChar(inote, 1, direction );
			break;
		case 1:
			ochar = noteToChar(inote, 3);
			break;
		case 2:
			ochar = noteToChar(inote, 4);
			break;
		case 3:
			ochar = noteToChar(inote, 3);
			break;
		default:
			std::cout << "DEFAULT";
			ochar = noteToChar(inote, 1);
			break;
		
	}*/
	
	
	if( isNoteChar(ochar) )
	{
		return ochar;
	}
	else
		{return 37;}
}




#endif