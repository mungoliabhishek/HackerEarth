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
ll int a[10010],b[10010];
ll int fits(ll int i,ll int j,ll int k)
{
	if(a[i]<=b[j] && (a[i]+k)>=b[j])
	return 1;
	return 0;
}
ll int myfind(ll int index,ll int l,ll int h,ll int k)
{
	ll int m,ans=-1;
	while(l<=h)
	{
		m = ((h-l)>>1) + l;
		if(a[m]>b[index])
		{
			h=m-1;
		}
		else if((a[m]+k)<b[index])
		{
			l=m+1;
		}
		else
		{
			ans=m;
			h=m-1;
		}
	}
	return ans;
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int test;
	ll int n,m,k;
	ll int i,j,ans;
	cin>>test;
	while(test--)
	{
		cin>>n>>m>>k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<m;i++)
		{
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+m);
		ans=0;
		int l=0,h=n-1;
		for(i=0;i<m;i++)
		{
			j = myfind(i,l,h,k);
			if(j!=-1)
			{
				l=j+1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}






























