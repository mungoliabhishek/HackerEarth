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
int n;
int mat[20][20],flag[20][20],row_sum[20],col_sum[20];
int check(int row)
{
	int f=1;
	int i,j,ms=0;
	if(row==(n-1))
	{
		ms=0;
		for(i=0;i<n;i++)
		{
			if(flag[row][i]==1)
			ms+=mat[row][i];
		}
		if(ms!=row_sum[row])
		{
			f=0;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				ms=0;
				for(j=0;j<n;j++)
				{
					if(flag[j][i]==1)
					ms+=mat[j][i];
				}
				if(ms!=col_sum[i])
				{
					f=0;
					break;
				}
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(flag[row][i]==1)
			ms+=mat[row][i];
		}
		if(ms!=row_sum[row])
		{
			f=0;
		}
	}
	return f;
}
int solve(int x,int y)
{
	flag[x][y]=0;
	if(y==(n-1))
	{
		if(check(x))
		{
			if(x==n-1)
			{
				return 1;
			}
			else
			return solve(x+1,0);
		}
	}
	else
	{
		if(solve(x,y+1))
		{
			return 1;
		}
	}
	flag[x][y]=1;
	if(y==(n-1))
	{
		if(check(x))
		{
			if(x==n-1)
			{
				return 1;
			}
			else
			return solve(x+1,0);
		}
	}
	else
	{
		if(solve(x,y+1))
		{
			return 1;
		}
	}
	flag[x][y]=0;
	return 0;
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<"Matrix Dimension"<<endl;
	cin>>n;
	int i,j;
	cout<<"Enter Matrix values"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>mat[i][j];
			flag[i][j]=0;
		}
	}
	cout<<"Enter row sum"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>row_sum[i];
	}
	cout<<"Enter column sum"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>col_sum[i];
	}
	
	if(solve(0,0))
	{
		cout<<"Solution"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				//~ cout<<flag[i][j]<<" ";
				if(!flag[i][j])
				{
					cout<<"x"<<" ";
				}
				else
				{
					cout<<mat[i][j]<<" ";
				}
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"Solution doesn't exist"<<endl;
	}
	return 0;
}






























