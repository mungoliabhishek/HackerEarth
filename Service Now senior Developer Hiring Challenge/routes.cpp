
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
typedef struct node
{
	ll int time,cost,to,from;
}node;
ll int k,n,x,s,d;//per hour loss, number of cities and number of routes
class my
    {
		public:
        bool operator()(const node  t1,const node  t2)
        {
            ll int u,v,time1,time2;
			u = t1.time * k + t1.cost;
			v = t2.time * k + t2.cost;
			if(t1.from == s)
			{
				time1 = t1.time;
			}
			else
			{
				time1 = t1.time + 1;
			}
			if(t2.from == s)
			{
				time2 = t2.time;
			}
			else
			{
				time2 = t2.time + 1;
			}
			if(u<v)
			return false;
			else if(u==v)
			{
				if(time1 <= time2)
				return false;
			}
			return true;
        }
    };
void print_path(ll int u,ll int v,ll int * parent)
{
   //~ cout<<"Calling "<<u<<" "<<v<<endl;
   if(u==v)
   cout<<(u+1);
   else
   {
	   print_path(u,parent[v],parent);
	   cout<<"->"<<(v+1);
   }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>k>>n>>x;
	list<node> l[n];
	int visited[n];
	ll int price[n];
	ll int total_time[n];
	ll int parent[n];
	memset(visited,0,sizeof(visited));
	memset(price,0,sizeof(price));
	memset(total_time,0,sizeof(total_time));
	ll int i,u,v;
	node t,t2;
	for(i=0;i<x;i++)
	{
		cin>>u>>v>>t.time>>t.cost;
		u--;v--; //0-based indexing
		t.from = u;
		t.to = v;
		l[u].push_back(t);
		t.from = v;
		t.to = u;
		l[v].push_back(t);
	}
	cin>>s>>d;//source and destination
	s--;d--;//zero-based indexing
	priority_queue<node,vector<node>,my> p;
	list<node>::iterator it;
	t.to = s;
	t.from = s;
	t.time = 0;
	t.cost = 0;
	p.push(t);
	while(!p.empty())
	{
		t = p.top();
		p.pop();
		if(!visited[t.to])
		{
			visited[t.to]=1;
			if(t.from == s)
			{
				price[t.to]=price[t.from]+t.cost + (t.time * k);
				total_time[t.to] = total_time[t.from] + t.time;
			}
			else
			{
				price[t.to]=price[t.from]+t.cost + ((t.time + 1) * k);
				total_time[t.to] = total_time[t.from] + t.time + 1;
			}
			//~ cout<<t.to+1<<" "<<price[t.to]<<endl;
			parent[t.to] = t.from;
			for(it=l[t.to].begin();it!=l[t.to].end();it++)
			{
				t2 = *it;
				p.push(t2);
			}
		}
	}
	if(!visited[d])
	{
		cout<<"Error"<<endl;
	}
	else
	{
		print_path(s,d,parent);
		cout<<" "<<total_time[d]<<" "<<price[d]<<endl;
	}
	return 0;
}






























