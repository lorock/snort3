/*
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
** Copyright (C) 2013-2013 Sourcefire, Inc.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License Version 2 as
** published by the Free Software Foundation.  You may not use, modify or
** distribute this program under any other version of the GNU General
** Public License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef THREAD_H
#define THREAD_H

#include <string>

#define THREAD_LOCAL_TBD
//#define THREAD_LOCAL

// this is a gnu extension that at present is slightly faster than the 
// c++11 form
#define THREAD_LOCAL __thread

// the c++11 form currently seems to be slightly slower than __thread
// possibly due to dynamic initialization requirements 
//#define THREAD_LOCAL thread_local

unsigned get_instance_id();
unsigned get_instance_max();
const char* get_instance_file(std::string&, const char* name);

#endif
