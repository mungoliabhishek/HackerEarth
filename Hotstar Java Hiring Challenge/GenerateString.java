
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class GenerateString {

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test>0)
		{
			char[] arr = br.readLine().toCharArray();
			int n = arr.length;
			int q = Integer.parseInt(br.readLine());
			int i;
			for(i=0;i<n;i++)
			{
				if(vowel(arr[i]) && q>0)
				{
					arr[i]= (char) (arr[i]+1);
					q--;
				}
			}
			System.out.println(arr.toString());
			test--;
		}
		
	}

	private static boolean vowel(char c) {
		// TODO Auto-generated method stub
		if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u')
			return true;
		return false;
	}

	
}
