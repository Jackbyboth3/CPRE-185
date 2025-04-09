// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000
int time, Button_T, Button_C, Button_X, Button_S;
double g_x, g_y, g_z;

double avg_x = 0.0, avg_y = 0.0, avg_z = 0.0;
// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items) {
	int i;
	double totalBuffer = 0.0;
	for(i = 0; i < num_items; i++) {
		totalBuffer += buffer[i];
	}
	return totalBuffer/num_items;
}
//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min) {
	int i;
	
	*max = array[0];
	*min = array[0];

	for(i = 0;i < num_items; i++) {

		if (array[i] < *min) {
			*min = array[i];
		}
		else if(array[i] > *max) {
			*max = array[i];
		}


	}
}
//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item){
int i;
	for(i = length - 1; i > 0; i--) {
		buffer[i] = buffer[i-1]; 
	}
	
	
	buffer[0] = new_item;
}



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	/* PUT YOUR CODE HERE */
	int terminate = 1;
	while(terminate){
		
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &Button_T, &Button_C, &Button_X, &Button_S);
	  
		if(Button_S == 1){
			terminate = 0;
			break;
		}
		updatebuffer(x, lengthofavg, g_x);
		updatebuffer(y, lengthofavg, g_y);
		updatebuffer(z, lengthofavg, g_z);
		
		double max_x, min_x, max_y, min_y, max_z, min_z;
		maxmin(x, lengthofavg, &max_x, &min_x); 
		maxmin(y, lengthofavg, &max_y, &min_y); 
		maxmin(z, lengthofavg, &max_z, &min_z); 



		avg_x = avg(x, lengthofavg);
		avg_y = avg(y, lengthofavg);
		avg_z = avg(z, lengthofavg);
		printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", g_x, g_y, g_z, avg_x, avg_y, avg_z, min_x, max_x, min_y, max_y, min_z, max_z);

		fflush(stdout);
	}
	
}


