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

void setPoint(int xCoord, int yCoord) {
	printf("setPoint: (%d, %d) \n", xCoord, yCoord);
}

int getNewY(int xCurr, int xRad, int yRad) {
	float temp = ((float)(xCurr*xCurr) / (float)(xRad*xRad));
	return ((int)( yRad * sqrt(1 - temp)  + 0.5));
}

void drawEllipse(int xNumPoints, int yNumPoints, int xCen, int yCen, int xRad, int yRad) {
	int xCurr, yCurr, xCurrInv, yCurrInv;

	if((xNumPoints < xCen + xRad) || (yNumPoints < yCen + yRad) || (xCen < xRad) || (yCen < yRad)) {
		printf("The parameters are not consistent.\n");
		return;
	}

	// Initialization
	xCurr 		= xCen + xRad; 
	yCurr 		= yCen; 			
	xCurrInv 	= xCen - xRad;
	yCurrInv 	= yCen;

	while(xCurr >= xCen) {
		
		if(yCurr != yCen) {
			setPoint(xCurr, yCurrInv);
		}
		if(xCurr != xCen) {
			setPoint(xCurrInv, 	yCurr);
		}
		setPoint(xCurrInv++, 			yCurrInv);
		setPoint(xCurr--, 				yCurr);
		yCurr = getNewY(xCurr - xCen, xRad, yRad) + yCen;
		yCurrInv = 2*yCen - yCurr;
	}
}

int main(void) {
	int width = 200, height = 180, x0 = 55, y0 = 113, rX = 11, rY = 4; 

	drawEllipse(width, height, x0, y0, rX, rY);
	return 0;
}
