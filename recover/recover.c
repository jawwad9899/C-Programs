#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BLOCK_SIZE 512
// Function to check if the block indicates the start of a new JPEG file
bool isJpegStart(unsigned char block[])
{
    return (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0);
}

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("Usage: recover.exe FILENAME\n");
        return 1;
    }

    FILE* f = fopen(argv[1],"r");
    if(f == NULL){
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];
    int jpegCount = 0;
    FILE* jpegFile = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        if(isJpegStart(buffer)){
            if (jpegFile != NULL)
            {
                fclose(jpegFile);
            }
             char jpegFilename[8];
            sprintf(jpegFilename, "%03i.jpg", jpegCount);
            jpegCount++;

            jpegFile = fopen(jpegFilename, "w");
            if (jpegFile == NULL)
            {
                fprintf(stderr, "Could not create JPEG file: %s\n", jpegFilename);
                fclose(f);
                return 1;
            }
        }
        if (jpegFile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpegFile);
        }


    }
     fclose(f);
        if (jpegFile != NULL)
            {
                fclose(jpegFile);
            }

}