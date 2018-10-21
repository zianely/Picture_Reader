#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <time.h>
#include <time.h>

double sigmoide(double x)
{
	return (1 / (1 + exp(-x)) );
}

int main(void)
{
	printf("Hello world!\n");
	srand(time(NULL));
	//creation of the network
	//inpute
	double a = 0;
	double b = 0;
	double randome = (rand()/(double)RAND_MAX)*(-2)+1;
	//matrix of tow neurone
	double hidenlayer[2][2] = {{1,1},{1,1}};
	//biases of the hiden layer
	double Hbias[2] ={1,1};
	// juste one neurone
	double outpout[2] = {1,1};
	// bias of the outpout
	double Obias = 1;
	// initialisation of weight
	 for(int i=0;i<2;i++)
	 {
		for(int j=0;j<2;j++)
	  	 {
	  		 hidenlayer[i][j]=randome;
			 outpout[i]=randome;
	  	 }
	 }
	//forward propagation
	//step one inpute to hiden layer
	printf("Hello world!\n");
	double x = sigmoide(a*hidenlayer[0][0]+b*hidenlayer[0][1]+Hbias[0]);
	double y = sigmoide(a*hidenlayer[1][0]+b*hidenlayer[1][1]+Hbias[1]);
	//last step hiden layer to outpoute layer
	printf("Hello world!\n");
	double z = sigmoide(x*outpout[0]+y*outpout[1]+Obias);
//	printf("for a=%f,b=%f, xor result = %f\n",a,b,z);




	//now we learn XOR:
	double xorinpute[4][2]={{0,0},{0,1},{1,0},{1,1}};
	double theoriqueresult[4]={0,1,1,0};
	for(int traine = 0; traine<2000000;traine++)
	{
		for(int i = 0; i < 4; i++)
		{
			a = xorinpute[i][0];
			b = xorinpute[i][1]; 
			x = sigmoide((a*hidenlayer[0][0])+(b*hidenlayer[0][1])+Hbias[0]);
			y = sigmoide((a*hidenlayer[1][0])+(b*hidenlayer[1][1])+Hbias[1]);
			z = sigmoide((x*outpout[0])+(y*outpout[1])+Obias);
			
		//	double delta_out = 2*(z*(1-z))*(theoriqueresult[i] - z);
		//	printf("%f\n",delta_out);
			double delta_out = (theoriqueresult[i] - z)
				;
			double delta_hiden[2] = {0,0};
			
			//delta_hiden1
			double sum;
		//	sum = (hidenlayer[0][0]+hidenlayer[0][1])*delta_out;
			sum = outpout[0]*delta_out; 
			delta_hiden[0] = x*(1-x)*sum;

			//delta_hiden2
		//	sum = (hidenlayer[1][0]+hidenlayer[1][1])*delta_out;
			sum = outpout[1]*delta_out; 
			delta_hiden[1] = y*(1-y)*sum;

			double acc = 0.2;

			hidenlayer[0][0]+= a*delta_hiden[0]*acc;
			hidenlayer[0][1]+= b*delta_hiden[0]*acc;
			hidenlayer[1][0]+= a*delta_hiden[1]*acc;
			hidenlayer[1][1]+= b*delta_hiden[1]*acc;

			outpout[0]+= x*delta_out*acc;
			outpout[1]+= y*delta_out*acc;

			Obias += delta_out;
			Hbias[0]+= delta_hiden[0];
			Hbias[1]+= delta_hiden[1];
		}
	}


	// PRINT RESULT
	for(int i = 0; i < 4; i++)
	{
		a = xorinpute[i][0];
		b = xorinpute[i][1];
		x = sigmoide((a*hidenlayer[0][0])+(b*hidenlayer[0][1])+Hbias[0]);
		y = sigmoide((a*hidenlayer[1][0])+(b*hidenlayer[1][1])+Hbias[1]);
		z = sigmoide((x*outpout[0])+(y*outpout[1])+Obias);

		printf("for a=%f,b=%f, xor result = %f\n",a,b,z);
	}

	return 0;
}
