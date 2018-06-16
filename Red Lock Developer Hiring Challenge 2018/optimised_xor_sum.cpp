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
ll int n,q;
ll int a[100010];
ll int p[100010][41];
unordered_map<ll int,ll int> mp2,mp3;
ll int tp[41];
ll int mysqr(ll int x)
{
	return (x*x)%mod;
}
ll int mypow(ll int a,ll int x)
{
	if(x==0)
	return 1;
	if(x==1)
	return a;
	if(x&1)
	{
		return (a * mysqr(mypow(a,x/2)))%mod;
	}
	return mysqr(mypow(a,x/2));
}
ll int mync2(ll int x)
{
	if(mp2.find(x)==mp2.end())
	{
		mp2[x] = (((x * (x-1))%mod) * mypow(2,mod-2))%mod;
	}
	return mp2[x];
	 
}
ll int mync3(ll int x)
{
	if(mp3.find(x)==mp3.end())
	{
		mp3[x] = (((((x * (x-1))%mod) * (x-2))%mod) * mypow(6,mod-2))%mod;
	}
	return mp3[x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	ll int i,j,l,r,ans,t;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		a[i] = a[i]%mod;
		for(j=0;j<41;j++)
		{
			p[i][j]=0;
			if(a[i]&(1ll<<j))
			{
				p[i][j]=1;
			}
			if(i!=0)
			p[i][j] = p[i-1][j]+p[i][j];
		}
	}
	cin>>q>>j;
	for(i=0;i<q;i++)
	{
		cin>>l>>r;
		l--;r--;
		t=r-l+1;
		if(t<3) //no soln possible
		{
			ans=0;
		}
		else
		{
			ans=0;
			if(l==0)
			{
				for(j=0;j<41;j++)
				{
					if((t-p[r][j])>=0)
					{
						ans = (ans + (((1ll<<j)%mod) * ((p[r][j] * mync2(t-p[r][j]))%mod))%mod)%mod;
					}
					if(p[r][j]>=3)
					{
						ans = (ans + (((1ll<<j)%mod) * mync3(p[r][j]))%mod)%mod;
					}
					//~ cout<<j<<" "<<p[r][j]<<" "<<ans<<endl;
				}
			}
			else
			{
				ans=0;
				for(j=0;j<41;j++)
				{
					tp[j] = p[r][j]-p[l-1][j];
				}
				for(j=0;j<41;j++)
				{
					if((t-tp[j])>=0)
					{
						ans = (ans + (((1ll<<j)%mod) * ((tp[j] * mync2(t-tp[j]))%mod))%mod)%mod;
					}
					if(p[r][j]>=3)
					{
						ans = (ans + (((1ll<<j)%mod) * mync3(tp[j]))%mod)%mod;
					}
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
































