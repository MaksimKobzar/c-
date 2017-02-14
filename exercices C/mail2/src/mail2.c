/*
 ============================================================================
 Name        : mail2.c
 Author      : Maksim
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

char testArray[200][180];


void setPoint(int xCoord, int yCoord) {
	printf("setPoint: (%d, %d) \n", xCoord, yCoord);
	testArray[xCoord][yCoord] = 1;
}

int getYCoord(int xCurr, int xRad, int yRad) {
	
	float temp = ((float)(xCurr*xCurr) / (float)(xRad*xRad));

	printf("temp %2f, sqrt %2f, int*sqrt %2f \n", temp, sqrt(1 - temp), yRad*sqrt(1 -temp));
	printf("MY_DBG getYCoord: \t xCurr %d, xRad %d, yRad %d, Result %2f, Result %d \n",
				xCurr, xRad, yRad, yRad * sqrt(1 - temp), ((int)( yRad * sqrt(1 - temp) )));
	// round value
	return ((int)( yRad * sqrt(1 - temp)  + 0.5));
}

void drawEllipse(int xNumPoints, int yNumPoints, int xCen, int yCen, int xRad, int yRad) {
	int xCurr, yCurr, xCurrInv, yCurrInv;

	if((xNumPoints < xCen + xRad) || (yNumPoints < yCen + yRad) || (xCen < xRad) || (yCen < yRad)) {
		printf("The parameters are not consistent.\n");
		return;
	}

	// Initialization
	xCurr 		= xCen + xRad; 	// 26 
	yCurr 		= yCen; 				// 73
	xCurrInv 	= xCen - xRad; 	// 4
	yCurrInv 	= yCen; 				// 73

	printf("MY_DBG: Initial values (x0 %d, y0 %d, x1 %d, y1 %d) \n", xCurr, yCurr, xCurrInv, yCurrInv);

	while(xCurr != xCen) {
		
		if(yCurr != yCen) {
			setPoint(xCurr, yCurrInv);
		}
		if(xCurr != xCen) {
			setPoint(xCurrInv, 	yCurr);
		}
		setPoint(xCurrInv++, 			yCurrInv);
		setPoint(xCurr--, 				yCurr);
		yCurr = getYCoord(xCurr - xCen, xRad, yRad) + yCen;
		yCurrInv = 2*yCen - yCurr;
	}
}

int main(void) {
	int width = 200, height = 180, x0 = 55, y0 = 113, rX = 11, rY = 4; 

	int i = 0, j = 0;
	for(j = 0; j < height; j++) {
		for(i = 0; i < width; i++) {
			testArray[i][j] = 0;
		}
	}

	drawEllipse(width, height, x0, y0, rX, rY);


		for(i = 0; i < width; i++) {
	for(j = 0; j < height; j++) {
			printf("%c", testArray[i][j] ? 'x' : ' ' );
		}
		printf("\n");
	}
	return 0;
}
