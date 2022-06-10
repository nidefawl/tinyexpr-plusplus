#include "tinyexpr.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: example2 \"expression\"\n");
        return 0;
    }

    const char* expression = argv[1];
    printf("Evaluating:\n\t%s\n", expression);

    /* This shows an example where the variables
     * x and y are bound at eval-time. */
    double x{ 0 }, y{ 0 };
    // Store variable names and pointers.
    te_parser tep;
    tep.set_vars({ {"x", &x}, {"y", &y} });

    /* This will compile the expression and check for errors. */
    if (tep.compile(expression)) {
#ifndef NDEBUG
        te_parser::te_print(tep.get_compiled_expression(), 0);
#endif
        /* The variables can be changed here, and eval can be called as many
         * times as you like. This is fairly efficient because the parsing has
         * already been done. */
        x = 3; y = 4;
        const double r = tep.evaluate();
        printf("Result:\n\t%f\n", r);
    }
    else {
        /* Show the user where the error is at. */
        printf("\t%*s^\nError near here", (int)tep.get_last_error_position(), "");
    }

    return 0;
}