#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

int main(void) {
    sqlite3 *db;
    char *err_message;
    int rc;

    int choice = 0;

    while (choice != 3) {
        printf("1 to Register\n");
        printf("2: Your Account\n");
        printf("3: Exit\n");

        // Prompt for user input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                printf("Register new Student\n");
                
                // Opening the database and error handling
                rc = sqlite3_open("registration.db", &db);

                if (rc != SQLITE_OK) {
                    fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
                    sqlite3_close(db);
                    return 1;
                }

                // SQL statement to create the "students" table
                const char *create_table_sql = "CREATE TABLE IF NOT EXISTS students ("
                                              "id TEXT PRIMARY KEY,"
                                              "name TEXT NOT NULL,"
                                              "major TEXT NOT NULL,"
                                              "yos INTEGER NOT NULL"
                                              ");";

                // Execute the SQL statement to create the table
                rc = sqlite3_exec(db, create_table_sql, 0, 0, &err_message);

                if (rc != SQLITE_OK) {
                    fprintf(stderr, "SQL error: %s\n", err_message);
                    sqlite3_free(err_message);
                    sqlite3_close(db);
                    return 1;
                }

                /*
                Prompting the user to enter their details,
                where students will have to write their registration number, major (i.e., BIT), and year of study
                */

                char id[15];
                char name[50];
                char major[4];
                int yos;

                printf("Enter your registration number: ");
                scanf("%s", id);
                getchar(); // Remove the newline character from the input buffer

                printf("Enter your full name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove the newline character

                printf("Enter your major (i.e., BCS/BTX/BAC/BIT): ");
                fgets(major, sizeof(major), stdin);
                major[strcspn(major, "\n")] = '\0'; // Remove the newline character

                printf("Enter your year of study: ");
                scanf("%d", &yos);

                // SQL statement to insert the user details into the "students" table
                char *insert_sql = sqlite3_mprintf("INSERT INTO students (id, name, major, yos) "
                                                  "VALUES ('%s', '%s', '%s', '%d');",
                                                  id, name, major, yos);

                // Execute the SQL statement to insert the user details
                rc = sqlite3_exec(db, insert_sql, 0, 0, &err_message);

                if (rc != SQLITE_OK) {
                    fprintf(stderr, "SQL error: %s\n", err_message);
                    sqlite3_free(err_message);
                    sqlite3_close(db);
                    return 1;
                }

                printf("Registration done successfully.\n");

                sqlite3_close(db);
                break;
            case 2:
                printf("Your Account Details.\n");
                printf("Enter your student ID: ");
                char search_id[15];
                scanf("%s", search_id);

                // Opening the database and error handling
                rc = sqlite3_open("registration.db", &db);

                if (rc != SQLITE_OK) {
                    fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
                    sqlite3_close(db);
                    return 1;
                }

                // SQL statement to retrieve student details based on ID
                char *select_sql = sqlite3_mprintf("SELECT * FROM students WHERE id = '%s';", search_id);

                // Prepare the SQL statement
                sqlite3_stmt *stmt;
                rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, NULL);

                if (rc != SQLITE_OK) {
                    fprintf(stderr, "Failed to prepare SQL statement: %s\n", sqlite3_errmsg(db));
                    sqlite3_finalize(stmt);
                    sqlite3_close(db);
                    return 1;
                }

                // Execute the SQL statement
                rc = sqlite3_step(stmt);

                if (rc == SQLITE_ROW) {
                    // Fetch and display student details
                    const unsigned char *id = sqlite3_column_text(stmt, 0);
                    const unsigned char *name = sqlite3_column_text(stmt, 1);
                    const unsigned char *major = sqlite3_column_text(stmt, 2);
                    int yos = sqlite3_column_int(stmt, 3);

                    printf("Student Details:\n");
                    printf("ID: %s\n", id);
                    printf("Name: %s\n", name);
                    printf("Major: %s\n", major);
                    printf("Year of Study: %d\n", yos);
                } else if (rc == SQLITE_DONE) {
                    printf("Student not found.\n");
                } else {
                    fprintf(stderr, "Failed to execute SQL statement: %s\n", sqlite3_errmsg(db));
                }

                // Finalize the statement and close the database
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
