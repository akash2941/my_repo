package firstProject;


import java.util.Scanner;

public class Assignment {
    Scanner sc = new Scanner(System.in);
    
    public static void main(String args []) {
    	String str = "This is string";
        int l = str.length();
        int arr[] = new int[256];
        
        for(int i=0;i<l;i++) 
        	arr[str.charAt(i)]++;
        	int max = -1;
        	char result=' ';
        	
        for(int i = 0;i<l;i++) {
        	if(max< arr[str.charAt(i)]) {
        		max = arr[str.charAt(i)];
        		result = str.charAt(i);
        		
        		
        	}
        	
        }      
        System.out.println("The maximum no of charcter " +result);
   } 
}
