#ifndef _UTIL_H_
#define _UTIL_H_

/* * Structures: */

/**
 * \brief Program's arguments.
 *
 * \details Instantiate and initialized at the beginning of the program, used
 * to hold and dispatch program's options and arguments across the program.
 * 
 * \note Description of fields can be found in the function that parse
 * arguments \sa {arg_parse()}. They are initialized into the \sa {arg_init()}
 * function.
 */
struct arguments
{
    int quiet;
    int verbose;
    int meta;
    int tries;
};

/* * Prototypes: */

/**
 * \brief Initialize the command-line arguments with default values.
 *
 * \param args Structure that will hold user's supplied options and arguments.
 */
void arg_init(struct arguments *args);

/**
 * \brief Parse the given command-line arguments.
 *
 * \param argc Number of arguments.
 * \param argv Array of arguments.
 * \param arguments Structure holding initialized arguments that will reflect
 *                  command-line arguments.
 */
void arg_parse(int argc, char **argv, struct arguments *arguments);

#endif
