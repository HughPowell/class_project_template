/*  =========================================================================
    ${PROJECT_SHORT_NAME}_selftest - run self tests

    -------------------------------------------------------------------------
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of ${PROJECT_NAME}, see ${PROJECT_URL}.

    This is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation; either version 3 of the License, or (at your
    option) any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTA-
    BILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General
    Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see http://www.gnu.org/licenses/.
    =========================================================================
*/

#include "czmq.h"
#include "../include/${PROJECT_SHORT_NAME}.h"

int main (int argc, char *argv [])
{
    bool verbose;
    if (argc == 2 && streq (argv [1], "-v")) {
        argc--;
        verbose = true;
    }
    else
        verbose = false;

    //  Do normal checks if run without arguments
    //if (argc < 2) {
        printf ("Running self tests...\n");
        myp_mystatefulmod_test (verbose);
        myp_mystatelessmod_test (verbose);
        printf ("Tests passed OK\n");
        return 0;
    //}

    return 0;
}
