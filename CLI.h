#ifndef _CLI_H_
#define _CLI_H_

/*

How do I want to use this class???

inside main() {
    commandHandler handler;
    registerCommands(&handler);

    // Now I can use handler later throughout the runtime
}

----

So I need the registerCommands() function

registerCommands(commandHandler* handler) {
    registerCommand(handler,
                    "help",
                    "Prints help text for all registered commands",
                    runHelp);
    
    registerCommand(handler,
                    "sysinfo",
                    "Displays diagnostic information",
                    runSysinfo);
}

Thus, registerCommands() needs to have access to all the ACTUAL command functions...

----

Now, how do we use each of these cli comand functions

// parse command line
// find the correct command based on argv[0]
// split up the remaining arguments and throw them in an array of strings
handler->commandList[i].action(argc, argv); // call the command with argc and argv
// check if the action was performed properly
// otherwise, print out the help text again

*/

#include <stdint.h>

#define MAX_COMMANDS            255
#define MIN_COMMANDS            7

//
//  Typedefs
//

typedef int (*CliAction)(int, char**);

typedef struct _CliCommand {
    const char* alias;
    const char* helpText;
    CliAction action;
} CliCommand;

typedef struct _CliCommandHandler {
    uint8_t numCommands;
    uint8_t maxCommands;
    CliCommand* commands;
} CliCommandHandler;

//
//  Command Handler Functions
//

void initCliCommandHandler(CliCommandHandler* handler);
void freeCliCommandHandler(CliCommandHandler* handler);
int registerCliCommand(CliCommandHandler* handler, const char* alias, const char* helpText, CliAction action);
void handleCommand(CliCommandHandler* handler, char* line);

#endif