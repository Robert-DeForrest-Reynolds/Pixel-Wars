#include <stdio.h>
#include <stdlib.h>
#include "SourceFileRead.h"

int ReadFile(const char *FileName){
    printf("Reading file");
    FILE *File;
    char *ReadBuffer = NULL;
    size_t TotalBytesRead = 0;
    size_t BytesReadInOperation;

    File = fopen(FileName, "rb");
    if (File == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    ReadBuffer = malloc(CHUNK_SIZE);
    if (ReadBuffer == NULL) {
        perror("Error allocating memory");
        fclose(File);
        return EXIT_FAILURE;
    }

    while ((BytesReadInOperation = fread(ReadBuffer + TotalBytesRead, 1, CHUNK_SIZE, File)) > 0) {
        TotalBytesRead += BytesReadInOperation;

        if (TotalBytesRead % CHUNK_SIZE == 0) {
            char *NextBuffer = realloc(ReadBuffer, TotalBytesRead + CHUNK_SIZE);
            if (NextBuffer == NULL) {
                perror("Error reallocating memory");
                free(ReadBuffer);
                fclose(File);
                return EXIT_FAILURE;
            }
            ReadBuffer = NextBuffer;
        }
    }

    if (ferror(File)) {
        perror("Error reading from file");
    }

    printf("Read %zu bytes from file.\n", TotalBytesRead);
    fwrite(ReadBuffer, 1, TotalBytesRead, stdout);

    free(ReadBuffer);

    fclose(File);
    return EXIT_SUCCESS;
}