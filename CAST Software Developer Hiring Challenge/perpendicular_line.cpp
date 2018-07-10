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
#define MY_LONG_MIN (1ll<<63sub)
using namespace std;
ll int my_gcd(ll int x,ll int y)
{
	if(x==0)
	return y;
	if(y==0)
	return x;
	if(x>y)
	return my_gcd(x%y,y);
	return my_gcd(x,x%y);
}
ll int my_sign(ll int x)
{
	if(x<0)
	return -1;
	return 1;
}
ll int my_abs(ll int x)
{
	if(x<0)
	x=-1 * x;
	return x;
}
ll int x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int test;
	cin>>test;
	while(test--)
	{
		int flag =0;
		ll int g1,g2,t1,t2,t3,t4;
		cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3>>x_4>>y_4;
		if((x_1==x_2 && y_1 == y_2)||(x_3==x_4 && y_3 == y_4))
		{
			flag=-1;
		}
		else
		{
			g1 = my_gcd(my_abs(y_2 - y_1),my_abs(x_2 - x_1));
			g2 = my_gcd(my_abs(x_4 - x_3),my_abs(y_4 - y_3));
			t1  = (y_2 - y_1)/g1;
			t2 = (x_2 - x_1)/g1;
			t3 = (x_4 - x_3)/g2;
			t4 = (y_4 - y_3)/g2;
			if(t1==t3 && t1==0)
			{
				flag=1;
			}
			else if(t2==t4 && t2==0)
			{
				flag=1;
			}
			else if((my_abs(t1)==my_abs(t3)) && (my_abs(t2)==(t4)))
			{
				if((my_sign(t1) * my_sign(t2) * -1) == (my_sign(t3) * my_sign(t4)))
				{
					flag=1;
				}
			}
		}
		if(flag==1)
		cout<<"YES"<<endl;
		else if(flag==-1)
		{
			cout<<"INVALID"<<endl;
		}
		else
		cout<<"NO"<<endl;
	}
	return 0;
}































