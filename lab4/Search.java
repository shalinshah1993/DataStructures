import java.util.Scanner;

public class Search{

	public Search(int a[]){
		i = 0;
		int temp;
		temp = a.length ;
		b = new int[temp];
		b = a ;
	}

	int linearSearch(int x,int a[]){
		i = 0;
		while(i < a.length){
			if(a[i] == x)
				break;
			else 
				i++;
		}
		if(i == a.length){
			System.out.println("No such element exist");
			return 0;
		}else{
			return i+1;
		}
		
	}
	
	int binarySearch(int x,int a[]){
		int mid = a.length/2;
		//System.out.print("andar");
		int first = 0;
		int last = a.length;
		while(a[mid] != x){
			mid = first + (last - first)/2;
			//System.out.println(first+" "+mid+" "+last);
			if(x > a[mid]){
				first = mid+1;
			}
			else if(x < a[mid]){
				last = mid - 1;
			}
		}
		return mid+1;
	}
	
	int max(int a[]){
		i = 0;
		int max = a[0];
		while(i < a.length){
			if(max < a[i])
				max = a[i];
			i++;
		}
		return max;
	}
	
	int min(int a[]){
		i = 0;
		int min = a[0];
		while(i < a.length){
			if(min > a[i])
				min = a[i];
			i++;
		}
		return min;
	}
	
	public static void main(String[] args){
		Scanner sn = new Scanner(System.in);
		int array[] = {1,2,3,4,5,6,7,8,9,10,11}; 
		Search s = new Search(array);
		System.out.print("Enter the element you want to search:");
		int input = sn.nextInt();
		int temp = s.linearSearch( input , array);
		if(temp != 0)
			System.out.println("The position of the element : "+temp);
		System.out.println("The maximum element is : "+ s.max(array));
		System.out.println("The minimum element is : "+ s.min(array));
		System.out.println("Binary search gives : "+s.binarySearch(input, array));
	}

private int[] b;
private int i;
}