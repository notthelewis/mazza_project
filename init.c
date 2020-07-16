#include <stdio.h>
#include <string.h>

/*  To compile on Linux: 
      gcc init.c -Wall 
      
      Run with:
      ./a.out
*/

int main(void) {
  // Used to open the text file as read only
    FILE *fp = fopen("example.txt", "r");

    // If file pointer (fp) is null, return 0 and print err msg
    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    // Creates a line buffer of 512 characters (0.5G)
    char buf[512];

    // Stores the number of rows in the file
    int row_count = 0;

    // Stores the number of 'fields', i.e. f-name s-name age gender
    int field_count = 0;

    while (fgets(buf, 1024, fp)) {
        field_count = 0;
        row_count++;

    // Skips the header
        if (row_count == 1) {
            continue;
      }

  // Pointer to the broken down string, delimeted with a blank space " "
        char *field = strtok(buf, " ");

    // Whilst there is still content to read (or whilst field != null)
        while (field) {
          if (field_count == 0) {
             printf("First Name:\t ");
            }
            if (field_count == 1) {
              printf("Last Name:\t");
            }
            if (field_count == 2) {
              printf("Age:\t\t");
            }
            if (field_count == 3) {
              printf("Gender:\t\t");
            }

            printf("%s\n", field);

          // Resets the pointer for next loop
            field = strtok(NULL, " ");

            field_count++;
        }
        printf("\n");
    }

    // Close file and terminate application, to prevent mem leaks
    fclose(fp);
    return 0;
}
