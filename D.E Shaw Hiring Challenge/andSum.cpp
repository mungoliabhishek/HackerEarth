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
#define mod 1000000007
using namespace std;
ll int a[100010];
ll int b[32];
ll int mysqr(ll int x)
{
	return (x*x)%mod;
}
ll int mypow(ll int x,ll int n)
{
	if(n==0)
	return 1;
	if(n==1)
	return x;
	else if(n%2 ==0)
	{
		return mysqr(mypow(x,n/2));
	}
	return (x*mysqr(mypow(x,n/2)))%mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int test;
	cin>>test;
	while(test--)
	{
		ll int n;
		cin>>n;
		ll int i,j,ans=0,x,y;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			for(j=0;j<32;j++)
			{
				if((a[i]&(1<<j)))
				b[j]++;
			}
		}
		for(i=0;i<32;i++)
		{
			if(b[i]!=0)
			{
				x = (mypow(2,b[i]) - 1 + mod)%mod;
				y = (1<<i);
				//~ cout<<"bit "<<i<<" "<<b[i]<<endl;
				//~ ans=(ans+(i+1)*mypow(2,b[i]))%mod;
				ans = (ans + ((x*y)%mod))%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}































