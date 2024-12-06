#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    char dob[20];
    char blood_group[5];
    char location[50];
    char quota[20];
    int ranking;
    char branch[20];
    char phone[15];
};


void saveStudentInfo(struct Student students[], int num_students) {
    FILE *file = fopen("student_info.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Name,Date of Birth,Blood Group,Location,Quota,Ranking,Branch,Phone\n");
    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%d,%s,%s\n", students[i].name, students[i].dob, students[i].blood_group, students[i].location, students[i].quota, students[i].ranking, students[i].branch, students[i].phone);
    }

    fclose(file);
}

int main() {
    
    struct Student students[100];
    int num_students = 0;
    int choice;

   
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Faculty Information\n");
        printf("3. Campus Information\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Input student information
                printf("\nEnter details for student %d:\n", num_students + 1);
                printf("Name: ");
                scanf("%s", students[num_students].name);
                
                printf("Date of Birth (DD/MM/YYYY): ");
                scanf("%s", students[num_students].dob);
                
                printf("Blood Group: ");
                scanf("%s", students[num_students].blood_group);
                
                printf("Location: ");
                scanf("%s", students[num_students].location);
                
                printf("Quota: ");
                scanf("%s", students[num_students].quota);
                
                printf("Ranking: ");
                scanf("%d", &students[num_students].ranking);
                
                printf("Branch: ");
                scanf("%s", students[num_students].branch);
                
                printf("Phone: ");
                scanf("%s", students[num_students].phone);

                num_students++;
                
               
                saveStudentInfo(students, num_students);
                printf("Student information saved to student_info.csv\n");
                break;
            case 2:
                printf("\nFaculty Information\n");
    printf("Name              Faculty ID  Department             Domain                   Staff Room  Phone\n");
    printf("\n");
    printf("Arjun Sharma      101         CS                     Artificial Intelligence  C-301      +91 98765 43210\n");
    printf("Priya Desai       102         CS                     Data Science             C-302      +91 98765 67890\n");
    printf("Rahul Singhania   201         ECE                    Wireless Communication  E-201      +91 87654 32109\n");
    printf("Nisha Patel       202         ECE                    Signal Processing        E-202      +91 87654 56789\n");
    printf("Sanjay Reddy      301         BT                     Genetic Engineering      B-101      +91 76543 21098\n");
    printf("Aishwarya Gupta   302         BT                     Bioinformatics           B-102      +91 76543 56789\n");


                break;

            case 3:
                 printf("\nCampus Information\n");
    printf("\n");
    printf("Parking for 2 or 4 wheelers - Left side from the main entrance and back gate for two wheelers, opposite to be block for 4 wheelers\n");
    printf("Canteen info - Cantina, Halli Mane, PES Canteen, 13th floor canteen\n");
    printf("Stationary and xerox - Near BE block\n");
    printf("Rooms for 1st year - F block\n");
    printf("Rooms for higher semesters - BE block\n");
    printf("Library - Silent reflections, GJBC Library\n");
    printf("Playground - Cricket ground, Football turf, Basketball courts\n");
    printf("ATM - Towards back gate side\n");
    printf("\n");
                break;

            
            case 4:
                
                printf("\n\nStudent Information:\n");
                for (int i = 0; i < num_students; i++) {
                    printf("\nStudent %d:\n", i + 1);
                    printf("Name: %s\n", students[i].name);
                    printf("Date of Birth: %s\n", students[i].dob);
                    printf("Blood Group: %s\n", students[i].blood_group);
                    printf("Location: %s\n", students[i].location);
                    printf("Quota: %s\n", students[i].quota);
                    printf("Ranking: %d\n", students[i].ranking);
                    printf("Branch: %s\n", students[i].branch);
                    printf("Phone: %s\n", students[i].phone);
                }
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 5);

    return 0;
}