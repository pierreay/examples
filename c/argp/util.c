#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

#include "util.h"

/* * Variables: */

/** Maintainers' address. Used in the output of "-?" and "--help". */
const char *argp_program_bug_address = "<pierre.ayoub@irisa.fr>";
/** Program's version. Used in the output of "-V" and "--version". */
const char *argp_program_version = "Spectre v0.1";
/** Program's documentation. Used in the output of "-?" and "--help". Can be
 * long if needed. */
static char doc[] = "Spectre -- A Spectre implementation useful for research";

/* * Functions: */

/**
 * \brief Parse a single option.
 *
 * \param key An integer specifying which option this is (taken from the KEY
 *            field in each struct argp_option), or a special key specifying
 *            something else. The only special keys we use here are
 *            ARGP_KEY_ARG, meaning a non-option argument, and ARGP_KEY_END,
 *            meaning that all arguments have been parsed.
 * \param arg For an option KEY, the string value of its argument, or NULL if
 *            it has none.
 * \param state A pointer to a struct argp_state, containing various useful
 *              information about the parsing state. Used here are the INPUT
 *              field, which reflects the INPUT argument to argp_parse, and the
 *              ARG_NUM field, which is the number of the current non-option
 *              argument being parsed.
 * \return error_t It should return either 0, meaning success,
 *                 ARGP_ERR_UNKNOWN, meaning the given KEY wasn’t recognized,
 *                 or an errno value indicating some other error.
 */
static error_t arg_parse_opt (int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    /* Test the passed option or argument. */
    switch (key)
        {
        /* Options. */
        case 'q': case 's':
            arguments->quiet = 1;
            break;
        case 'v':
            arguments->verbose = 1;
            break;
        case 'm':
            arguments->meta = atoi(arg);
            if (arguments->meta <= 0) {
                fprintf(stderr, "Specified number must be superior to 0.\n");
                argp_usage(state);
            }
            break;
        case 't':
            arguments->tries = atoi(arg);
            if (arguments->tries <= 0) {
                fprintf(stderr, "Specified number must be superior to 0.\n");
                argp_usage(state);
            }
            break;

        /* End of parsing. */
        case ARGP_KEY_END:
            break;
        default:
            return ARGP_ERR_UNKNOWN;
        }
    return 0;
}

void arg_init(struct arguments *args)
{
    args->quiet   = 0;
    args->verbose = 0;
    args->meta    = 1;
    args->tries   = 999;
}

void arg_parse(int argc, char **argv, struct arguments *arguments)
{
    /**
     * Options of the program. Here is the description of the fields:
     * NAME   – The name of this option's long option (may be zero).
     * KEY    – The KEY to pass to the PARSER function when parsing this
     *          option, and the name of this option’s short option, if it is a
     *          printable ASCII character.
     * ARG    – The name of this option’s argument, if any.
     * FLAGS  – Flags describing this option, some of them are:
     * - OPTION_ARG_OPTIONAL The argument to this option is optional,
     * - OPTION_ALIAS        This option is an alias for the previous option,
     * - OPTION_HIDDEN       Don’t show this option in "-–help" output.
     * DOC    – A documentation string for this option, shown in "–-help"
     *          output.
     */
    static struct argp_option options[] =
        {
         {"verbose",  'v', 0,        0,  "Produce verbose output" },
         {"quiet",    'q', 0,        0,  "Don't produce any output" },
         {"silent",   's', 0,        OPTION_ALIAS },
         {"meta",     'm', "NUMBER", 0, "Number of meta-repetition of Spectre" },
         {"tries",    't', "NUMBER", 0, "Number of attempts to guess a secret byte" },
         { 0 }
        };

    /** Our argument parser. */
    static struct argp argp = {options, arg_parse_opt, 0, doc};
    /* Use it to parse the command-line. */
    argp_parse(&argp, argc, argv, 0, 0, arguments);
}
