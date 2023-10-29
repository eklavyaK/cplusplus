import java.util.*;
import java.lang.*;

public class testfile
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<>();
		for(int i = 0; i < n; i++){
			a.add(sc.nextInt());
		}
		Collections.sort(a, (x, y) -> {return y - x;});
		for(int i = 0; i < n; i++){
			System.out.print(a.get(i) + " ");
		}
		sc.close();
	}
}