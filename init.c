/*
 * C program to split lines of text according to gender and age
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function declarations */
int isMale(char gender, int age);
int isFemale(char gender, int age);

/* Returns true (1) if the character in the last field is M and age is 4-18 */
int isMale(char gender, int age)
{
        if (gender == 'M' && age<=18 && age>=5)
        {
                printf("Male %i \n", age);
                return 1;
        }
        return 0;
}

/* Returns true (1) if the character in the last field is F and age is 4-18 */
int isFemale(char gender, int age)
{
        if (gender == 'F' && age<=18 && age>=5)
        {
                printf("Female %i \n", age);
                return 1;
        }
        return 0;
}


int main()
{
    /* File pointer to hold reference to different files */
    FILE * fPtrIn,              // Input file
         * fPtrMale,    // Males of school age
         * fPtrFemale,  // Females of school age
         * fPtrMisc;    // Data not within the given parameters

    // Open all files to perform read/write.
    fPtrIn       = fopen("data/potential-pupils.txt", "r");
    fPtrMale     = fopen("data/males.txt" , "w");
    fPtrFemale   = fopen("data/females.txt"  , "w");
    fPtrMisc     = fopen("data/erroneuos.txt", "w");

    // fopen() return NULL if unable to open file in given mode
    if(fPtrIn == NULL || fPtrMale == NULL || fPtrFemale == NULL || fPtrMisc == N                                                                                                                                                                                                ULL)
    {
        // Unable to open file, exit program print err msg
        printf("Unable to open file.\n");
        printf("Check file exists and permissions are correct.\n");
        exit(EXIT_FAILURE);
    }

    // File open success message
    printf("File opened successfully. \n\n");

        // current_char is the current character being read
        char current_char;

        // the line array is used to store each line
        // line_parse is used to copy the data of line into, so the original cop                                                                                                                                                                                                y
        // isn't changed by the strtok() function.

        char line[100], line_parse[100];

        // Last field is where gender is stored, ret is the token used for strto                                                                                                                                                                                                k()
    char *last_field, *ret;

    /*  age stores the 3rd field of each line, then passes it through to the
        isMale and isFemale functions. It's used to store the age of each
        applicant, and changes every time a newline is read into the program.
                field_count stores the position of the field on the current line                                                                                                                                                                                                .

                field 0 = first name
                field 1 = second name
                field 2 = age
                field 3 = gender
     */
    int age = 0;
    int field_count = 0;

        // Read an integer and store read status in success.
        while (fgets(line, sizeof(line), fPtrIn) != NULL)
        {
            // Copy the line for parsing
            strcpy(line_parse, line);

            // Separate the line into tokens
            last_field = ret = strtok(line_parse, " ");
            while (ret != NULL)
            {
                last_field = ret;

                if (field_count == 2)
                {
                        age = atoi(ret);
                }
                if (field_count == 4)
                {
                        field_count = 0;
                }

                field_count++;
                ret = strtok(NULL, " ");
            }

            // Get the first character of the last field
            if (last_field == NULL) current_char = '\0';
            else current_char = last_field[0];

            // Write each line to a separate file
            if (isMale(current_char, age))
                fputs(line, fPtrMale);
            else if (isFemale(current_char, age))
                fputs(line, fPtrFemale);
            else
                fputs(line, fPtrMisc);
        }

    // Close each file
    fclose(fPtrIn);
    fclose(fPtrMale);
    fclose(fPtrFemale);
    fclose(fPtrMisc);
    printf("Data written to files successfully. \n");

    return(0);
}
