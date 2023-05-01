#include "util.h"

int main(int argc, char **argv) {
    /* Initialize command-line options and arguments. */
    struct arguments arguments;
    arg_init(&arguments);
    /* Parse command-line arguments. Quit if needed. */
    arg_parse(argc, argv, &arguments);
    
	return 0;
}
