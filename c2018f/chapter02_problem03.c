/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.09.12 */
/* Purpose: 半徑求體積 */
/* Change History: 2018.12.9 modify pi to PI in main() */
/********************************************************************/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359f

int main() 
{
	float radius, volume;

	printf("Enter the radius: ");
	scanf("%f", &radius);			/* 輸入半徑 */

	volume = (4.0 / 3.0) * PI * pow(radius, 3);			/* 球體體積公式 */

	printf("The volume of the sphere: %f\n", volume);	/*輸出球體體積 */

	return 0;
}