/*
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
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
// parameter.h author Russ Combs <rucombs@cisco.com>

#ifndef PARAMETER_H
#define PARAMETER_H

// number ranges are given by:
// nullptr -> any
// # | #: | :# | #:#
// where # is any valid pos|neg dec|hex|octal number
struct Parameter
{
    enum Type
    {
        PT_TABLE,      // range is Parameter*, deflt is TBD
        PT_LIST,       // range is Parameter*, deflt is TBD
        PT_BOOL,       // if you are reading this, get more coffee
        PT_INT,        // signed 64 bits or less determined by range
        PT_REAL,       // double
        PT_PORT,       // 0 to 64K-1 unless specified otherwise
        PT_STRING,     // any string less than len chars
        PT_SELECT,     // any string appearing in range
        PT_MULTI,      // one or more strings appearing in range
        PT_ENUM,       // string converted to unsigned by range sequence
        PT_MAC,        // 6-byte mac address
        PT_IP4,        // inet_addr() compatible
        PT_ADDR,       // ip4 or ip6 CIDR
        PT_BIT_LIST,   // string that converts to bitset
        PT_ADDR_LIST,  // snort address list format?
        PT_IMPLIED,    // rule option args w/o values eg relative
        PT_MAX
    };
    const char* name;
    Type type;
    const void* range;  // nullptr|const char*|const Parameter*
    const char* deflt;  // FIXIT add defaults for tables and lists
    const char* help;

    const char* get_type() const;

    bool validate(class Value&) const;

    bool is_positional() const
    { return ( name && *name == '~' ); };

    static const Parameter* find(const Parameter*, const char*);
};

#endif

