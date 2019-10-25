#include "arq.h"
#include <math.h> 

// https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
//=======================================================

// Driver Program
int main()
{
    // Input: number of disks
    unsigned num_of_disks=-1;

    struct pilha *src, *dest, *aux;
	
	printf("Entre com o numero de discos:");
	scanf("%i",&num_of_disks);
    // Create three stacks of size 'num_of_disks'
    // to hold the disks
    src = cria();
    aux = cria();
    dest = cria();

    tohIterative(num_of_disks, src, aux, dest);
    return 0;
}

// Function to implement legal movement between
// two poles
void moveDisksBetweenTwoPoles(struct pilha *src,
            struct pilha *dest, char s, char d)
{ 	
	info pole1TopDisk, pole2TopDisk;
	int numDsk;


    // When pole 1 is empty
    if (desempilha(&pole1TopDisk,src)==FRACASSO) 
    {
        empilha(&pole2TopDisk, src);
        moveDisk(d, s, pole2TopDisk.x);
    }

    // When pole2 pole is empty
    else if (desempilha(&pole2TopDisk,dest)==FRACASSO)  
    {
        empilha(&pole1TopDisk, dest);
        moveDisk(s, d, pole1TopDisk.x);
    }

    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk.x > pole2TopDisk.x)
    {
        empilha(&pole1TopDisk, src);
        empilha(&pole2TopDisk, src);
        moveDisk(d, s, pole2TopDisk.x);
    }

    // When top disk of pole1 < top disk of pole2
    else
    {
        empilha(&pole2TopDisk, dest);
        empilha(&pole1TopDisk, dest);
        moveDisk(s, d, pole1TopDisk.x);
    }
}

//Function to show the movement of disks
void moveDisk(char fromPeg, char toPeg, int disk)
{
    printf("Move the disk %d from \'%c\' to \'%c\'\n",
           disk, fromPeg, toPeg);
}

//Function to implement TOH puzzle
void tohIterative(int num_of_disks, struct pilha
             *src, struct pilha *aux,
             struct pilha *dest)
{   info dsk;
    int i, total_num_of_moves;
    char s = 'S', d = 'D', a = 'A';

    //If number of disks is even, then interchange
    //destination pole and auxiliary pole
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a  = temp;
    }
    total_num_of_moves = pow_(2, num_of_disks) - 1;

    //Larger disks will be pushed first
    for (i = num_of_disks; i >= 1; i--)
	{	dsk.x= i;
		dsk.y= 0;
        	empilha(&dsk, src);
	}

    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
          moveDisksBetweenTwoPoles(src, dest, s, d);

        else if (i % 3 == 2)
          moveDisksBetweenTwoPoles(src, aux, s, a);

        else if (i % 3 == 0)
          moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

long int pow_(long int b, long int e)
{   long int r=b;
	 for(int i =1;i<e;i++)
		r=r*b;
	 return r; 	
}
