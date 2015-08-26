#include <map>
#include <string>



#ifndef NOTES_H
#define NOTES_H
	
class Note
{
	public:
		int m_unison;
		
		int m_second;
		int m_third;
		int m_fourth;
		int m_fifth;
		int m_sixth;
		int m_seventh;
		
		int m_Dsecond;
		int m_Dthird;
		int m_Dfourth;
		int m_Dfifth;
		int m_Dsixth;
		int m_Dseventh;
		
		
		
		
		
		int m_octave; //octave number
		
		bool m_valid1;//valid intervals for output note
		bool m_valid2;
		bool m_valid3;
		bool m_valid4;
		bool m_valid5;
		bool m_valid6;
		bool m_valid7;
		
		// DOWN intervals
		bool m_Dvalid2;
		bool m_Dvalid3;
		bool m_Dvalid4;
		bool m_Dvalid5;
		bool m_Dvalid6;
		bool m_Dvalid7;
		
		bool m_listOfBools[13];
		
		int m_validIntervalList[13];
		int m_remainingIntervalsIndex;
		
		
		int m_timeValue;
		
		static int s_prevCantusValue; 
		static int s_prevCantusOctave;
		static int s_cantusDirection;
		
		static int s_prevCounterpointValue;
		static int s_prevCounterpointOctave;
		

		
		
		
		

		Note(int noteNumber,int octave, int timeValue=1)
		{
			
			m_valid1=true;
			m_valid2=true;
			m_valid3=true;
			m_valid4=true;
			m_valid5=true;
			m_valid6=true;
			m_valid7=true;
			
			m_Dvalid2=true;
			m_Dvalid3=true;
			m_Dvalid4=true;
			m_Dvalid5=true;
			m_Dvalid6=true;
			m_Dvalid7=true;
			
			for(int iii =0; iii<13; iii++)
			{
				m_validIntervalList[iii] = iii;
			}
			m_remainingIntervalsIndex = 12;
			
			
		
			m_timeValue = timeValue;
			m_unison = noteNumber; // 1,2,3,4,5,6,7,8
			m_second = (m_unison +1)%7;
			m_third = (noteNumber+2)%7;
			m_fourth = (noteNumber +3)%7;
			m_fifth = (noteNumber +4)%7;
			m_sixth = (noteNumber+5)%7;
			m_seventh = (noteNumber+6)%7;
			
			m_octave = octave;
			
			if (m_second==0){m_second=7;}
			if (m_third==0){m_third=7;}
			if (m_fourth==0){m_fourth=7;}
			if (m_fifth==0){m_fifth=7;}
			if (m_sixth==0){m_sixth=7;}
			if (m_seventh==0){m_seventh=7;}
			
			m_Dsecond = (m_unison -1)%7;
			m_Dthird = (noteNumber-2)%7;
			m_Dfourth = (noteNumber -3)%7;
			m_Dfifth = (noteNumber -4)%7;
			m_Dsixth = (noteNumber-5)%7;
			m_Dseventh = (noteNumber-6)%7;
			
			if (m_Dsecond==0){m_second=7;}
			if (m_Dthird==0){m_third=7;}
			if (m_Dfourth==0){m_fourth=7;}
			if (m_Dfifth==0){m_fifth=7;}
			if (m_Dsixth==0){m_sixth=7;}
			if (m_Dseventh==0){m_seventh=7;}
			
		}
	
		void listCheck();
		
	
};

int Note::s_prevCantusValue= 1;
int Note::s_prevCantusOctave =1;
int Note::s_cantusDirection = 0;

int Note::s_prevCounterpointValue =1;
int Note::s_prevCounterpointOctave = 1;




void Note::listCheck()
{	
	
	if (m_valid1 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 0)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}
	
	if (m_valid2 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 1)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}
	
	if (m_valid3 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 2)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_valid4 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 3)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_valid5 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 4)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_valid6 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 5)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_valid7 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 6)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_Dvalid2 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 7)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_Dvalid3 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 8)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_Dvalid4 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 9)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_Dvalid5 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 10)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_Dvalid6 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 11)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}

	if (m_Dvalid7 == false )
	{
		for(int iii =0; iii<13; iii++)
		{
			if(m_validIntervalList[iii] == 12)
			{
				moveToEnd13( iii, m_validIntervalList);
				m_remainingIntervalsIndex -= 1;
				break;
			}
		}	
	}
	
}































#endif