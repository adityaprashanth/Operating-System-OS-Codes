/*Write a C program to simulate
  segmentation. Compute the physical address
  Take as Input :
  1. Segment number
  2. Base address
  3. Segment limit*/

#include <stdio.h>

int main() 
{
    int segNo, baseAddr, segLim, offset;

    printf("Enter segment number: ");
    scanf("%d", &segNo);
    printf("Enter base address: ");
    scanf("%d", &baseAddr);
    printf("Enter segment limit: ");
    scanf("%d", &segLim);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if (offset>=0 && offset<segLim) 
    {
        int physicalAddr = baseAddr + offset;
        printf("Physical address: %d\n", physicalAddr);
    } 
    else 
    {
        printf("Error : Offset is outside of segment limit !! \n");
    }
    return 0;
}
