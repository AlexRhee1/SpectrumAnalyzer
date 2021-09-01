#include "CLI.h"

#include <stdlib.h>

void intiCliCommandHandler(CliCommandHandler* handler) {
    handler->numCommands = 0;
    handler->maxCommands = MAX_COMMANDS;
    handler->commands = calloc(handler->maxCommands, sizeof(CliCommand));
}

void freeCliCommandHandler(CliCommandHandler* handler) {
    free(handler->commands);
}

// Helper Function for registerCliCommand
int checkHandlerSize(CliCommandHandler* handler) {
    // Check if the size cannot get any larger
    if( handler->numCommands >= MAX_COMMANDS )
        return 0;
    // Check if we need to increase the size of the background array
    if( handler->numCommands + 1 >= handler->maxCommands ) {
        handler->maxCommands = (handler->maxCommands * 2) - 1;
        CliCommand* newCommandList = calloc(handler->maxCommands, sizeof(CliCommand));
        for( int i = 0; i < handler->numCommands; i++ ) {
            newCommandList[i].alias = handler->commands[i].alias;
            newCommandList[i].helpText = handler->commands[i].helpText;
            newCommandList[i].action = handler->commands[i].action;
        }
        free(handler->commands);
        handler->commands = newCommandList;
    }
    return 1;
}

int registerCliCommand(CliCommandHandler* handler, const char* alias, const char* helpText, CliAction action) {
    if( !checkHandlerSize(handler) )
        return 0;
    handler->numCommands++;
    handler->commands[handler->numCommands].alias = alias;
    handler->commands[handler->numCommands].helpText = helpText;
    handler->commands[handler->numCommands].action = action;
}

void handleCommand(CliCommandHandler* handler, char* line) {
    // TODO: I am here
}