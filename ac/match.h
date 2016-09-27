/*
Aho-Corasick keyword tree + automaton implementation for Python.
Copyright (C) 2016 Timo Petmanson ( tpetmanson@gmail.com )

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef AC__MATCH_H
#define AC__MATCH_H

#include "ac.h"

BEGIN_NAMESPACE(ac)

class CppMatch {
private:
    int start, end;
    std::string label;
public:
    CppMatch(const int start, const int end, const std::string& label);
    CppMatch(const int start, const int end, const char* label);

    int get_start() const { return start; }
    int get_end() const { return end; }
    std::string get_label() const { return label; }

    bool is_before(const CppMatch& m) const;
    bool operator==(const CppMatch& m) const;
    bool operator<(const CppMatch& m) const;
    size_t size() const;
    std::string str() const;
};


MatchVector remove_overlaps(MatchVector matches);


END_NAMESPACE

#endif