/*  =========================================================================
    ${PROJECT_SHORT_NAME}.h - ${PROJECT_NAME} library

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

#ifndef __${PROJECT_NAME_UPPER}_H_INCLUDED__
#define __${PROJECT_NAME_UPPER}_H_INCLUDED__

//  ${PROJECT_NAME_UPPER} version macros for compile-time API detection

#define ${PROJECT_NAME_UPPER}_VERSION_MAJOR 1
#define ${PROJECT_NAME_UPPER}_VERSION_MINOR 0
#define ${PROJECT_NAME_UPPER}_VERSION_PATCH 0

#define ${PROJECT_NAME_UPPER}_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define ${PROJECT_NAME_UPPER}_VERSION \
    ${PROJECT_NAME_UPPER}_MAKE_VERSION(${PROJECT_NAME_UPPER}_VERSION_MAJOR, ${PROJECT_NAME_UPPER}_VERSION_MINOR, ${PROJECT_NAME_UPPER}_VERSION_PATCH)

#include <czmq.h>
#if CZMQ_VERSION < 20000
#   error "${PROJECT_NAME} needs CZMQ/2.0.0 or later"
#endif

#include "myp_mystatefulmod.h"
#include "myp_mystatelessmod.h"

#endif
