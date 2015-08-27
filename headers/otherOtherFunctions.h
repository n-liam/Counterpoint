
#ifndef OTHEROTHERFUNCTIONS_H
#define OTHEROTHERFUNCTIONS_H

////////////////////////////////////////////
// swap elements of an array with seven elements
//////////////////////////////////////////
void swap13(int index1, int index2, int array13[13])
{

	assert( index1<13 && index1>=0); // 0,1,2,3,4,5,6,7,8,9,10,11,12
	assert(index2<13 && index2>=0);
	
	int temp1= array13[index1];
	int temp2 = array13[index2];
	
	array13[index1]= temp2;
	array13[index2] = temp1;
}

////////////////////////////////////////////
// move element to end of array with 7 elements
///////////////////////////////////////
void moveToEnd13(int index, int array13[13])
{
	assert(index<13 && index>=0);
	
	for( int iii = 12; iii>index; iii-=1)
	{
		swap13(iii, index, array13);
	}
}


/////////////////////////////////////
// swaps elements in a list
///////////////////////////////////////

void swapElements( int length, int array[], int index1, int index2)
{
	assert( index1<length && index1>=0); 
	assert(index2<length && index2>=0);
	
	int temp1= array[index1];
	int temp2 = array[index2];
	
	array[index1]= temp2;
	array[index2] = temp1;

}

void moveToEnd(int length, int array[], int index)
{
	assert(index<length && index>=0);
	
	for( int iii = length-1; iii>index; iii-=1)
	{
		swapElements(length, array, iii, index);
	}
}

#endif