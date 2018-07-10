import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class ThreeEqualParts {

	public static void main(String[] args) throws IOException
	{
		int mymax=1000000007;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test>0)
		{
			int n = Integer.parseInt(br.readLine());
			int[] a = new int[n];
			int i,mcount=0,ans;
			int flag= 0;
			String[] arr = br.readLine().split(" ");
			for(i=0;i<n;i++)
			{
				a[n-1-i] = Integer.parseInt(arr[i]);
				if(a[n-1-i]==1)
				{
					mcount++;
				}
			}
			int temp1=0,temp2=0,temp3=0;
			int first=0;
			if((mcount%3) ==0)
			{
				ans= 0;
				for(i=0;i<n;i++)
				{
					if(a[i]==1)
					{
						ans++;
					}
					if(ans==(mcount/3))
					{
						break;
					}
//					System.out.println(i+" "+ ans+" "+mcount/3);
				}
				first=i;
				for(;i>=0;i--)
				{
					temp1 = (temp1 *2 +a[i])%mymax;
				}
//				System.out.println(temp1+" " + i);
				for(i=n-1;i>=0;i--)
				{
					
					temp2 = (temp2 *2 +a[i])%mymax;
					if(temp2==temp1)
					{
						i--;
						break;
					}
				}
				for(;i>=0;i--)
				{
					temp3 = (temp3 *2 +a[i])%mymax;
					if(temp3==temp1)
					{
						i--;
						break;
					}
				}
				if(temp1==temp2 && temp2==temp3 && first<=i)
				{
					flag=1;
					
				}
			}
			if(flag==1)
			{
				System.out.println(temp1);
			}
			else
			{
				System.out.println(-1);
			}
			test--;
		}
		br.close();
	}	
}
