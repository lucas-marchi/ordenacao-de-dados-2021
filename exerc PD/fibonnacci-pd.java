class Fibonacci {

    public static int simpleFind(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        return simpleFind (n - 1) + simpleFind (n -2);
    }
    
    public static int bottomupFind (int n) {
        int[] fib = new int[n+2];
        fib[0] = 1;
        fib[1] = 1;
        for(int i = 2; i <= n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
    
    public static void main(String[] args) {
        for(int i = 0; i < 18; i++) system.out.print(simpleFind[i]+",");
        system.out.println();
        
        for(int i = 0; i < 18; i++) system.out.print(bottomupFind[i]+",");
        system.out.println();
    }
}