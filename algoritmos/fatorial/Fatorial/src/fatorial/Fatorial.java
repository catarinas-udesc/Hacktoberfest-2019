package fatorial;

import java.util.Scanner;

public class Fatorial {

    public static void main(String[] args) {
        Scanner l = new Scanner(System.in);
        int i = l.nextInt();
        System.out.println(fat(i));
    }

    private static int fat(int i) {
        if (i==0) {
            return 1;
        }
        return i * fat(i-1);
    }
    
}
