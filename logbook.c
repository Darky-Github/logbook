#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LOGBOOK_FILE "~/.logbook_history"
#define BLOCKED_FILE "~/.logbook_blocked"

void list_history() {
    char command[256];
    snprintf(command, sizeof(command), "cat %s", LOGBOOK_FILE);
    system(command);
}

void search_history(const char *keyword) {
    char command[512];
    snprintf(command, sizeof(command), "grep '%s' %s", keyword, LOGBOOK_FILE);
    system(command);
}

void undo_last_command() {
    printf("Undo feature is under development.\n");
}

void clear_history() {
    printf("Are you sure you want to delete all history? [y/n]: ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
        system("rm -f " LOGBOOK_FILE);
        printf("History cleared.\n");
    } else {
        printf("Operation canceled.\n");
    }
}

void remove_command(const char *cmd) {
    char command[512];
    snprintf(command, sizeof(command), "grep -v '%s' %s > %s.tmp && mv %s.tmp %s", cmd, LOGBOOK_FILE, LOGBOOK_FILE, LOGBOOK_FILE, LOGBOOK_FILE);
    system(command);
}

void block_command(const char *cmd) {
    char command[512];
    snprintf(command, sizeof(command), "echo '%s' >> %s", cmd, BLOCKED_FILE);
    system(command);
    printf("Command '%s' is now blocked.\n", cmd);
}

void unblock_command(const char *cmd) {
    char command[512];
    snprintf(command, sizeof(command), "grep -v '%s' %s > %s.tmp && mv %s.tmp %s", cmd, BLOCKED_FILE, BLOCKED_FILE, BLOCKED_FILE, BLOCKED_FILE);
    system(command);
    printf("Command '%s' is now unblocked.\n", cmd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: logbook [option] [arguments]\n");
        return 1;
    }
    
    if (strcmp(argv[1], "list") == 0) {
        list_history();
    } else if (strcmp(argv[1], "search") == 0 && argc == 3) {
        search_history(argv[2]);
    } else if (strcmp(argv[1], "undo") == 0) {
        undo_last_command();
    } else if (strcmp(argv[1], "clear") == 0) {
        clear_history();
    } else if (strcmp(argv[1], "remove") == 0 && argc == 3) {
        remove_command(argv[2]);
    } else if (strcmp(argv[1], "block") == 0 && argc == 3) {
        block_command(argv[2]);
    } else if (strcmp(argv[1], "unblock") == 0 && argc == 3) {
        unblock_command(argv[2]);
    } else {
        printf("Invalid command.\n");
    }
    
    return 0;
}
