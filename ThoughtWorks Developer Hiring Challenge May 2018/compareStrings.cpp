
// C++ includes used for precompiling -*- C++ -*-
  
// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
  
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.
  
// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <Licenses - GNU Project - Free Software Foundation>.
  
/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */
  
// 17.4.1.2 Headers
  
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
  
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
  
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
  
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define ll long long
#define MY_LONG_MAX (((1ll<<62))|((1ll<<62)-1))
#define MY_LONG_MIN (1ll<<63)
using namespace std;
ll int n,q;
string a,b;
set<ll int> mset;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q; //length of string and number of queries
	cin>>a>>b;
	ll int i,j,t,ans;
	set<ll int>::iterator it;
	for(i=0;i<n;i++)
	{
		if(a.at(i)!=b.at(i))
		{
			mset.insert(i);
		}
	}
	for(i=0;i<q;i++)
	{
		ans=0;
		cin>>j;
		j--;
		if(b.at(j)=='1')
		{
			if(mset.empty())
			{
				ans=1;
			}
			else
			{
				it = mset.begin();
				t = *it;
				if(a.at(t)>b.at(t))
				{
					ans=0;
				}
				else
				{
					ans=1;
				}
			}
		}
		else
		{
			b.at(j) = '1';
			if(mset.find(j) == mset.end())
			{
				mset.insert(j);
			}
			else
			{
				mset.erase(mset.find(j));
			}
			if(mset.empty())
			{
				ans=1;
			}
			else
			{
				it = mset.begin();
				t = *it;
				if(a.at(t)>b.at(t))
				{
					ans=0;
				}
				else
				{
					ans=1;
				}
			}
		}
		if(ans)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}






























