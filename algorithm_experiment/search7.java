import java.math.BigInteger;
import java.util.*;
public class Main {
    private static int flag;
    private static int n;
    private static void dfs(BigInteger x, int dep) {
        if (flag == 1) return;
        if (x.mod(BigInteger.valueOf(n)).compareTo(BigInteger.ZERO) == 0) {
            System.out.println(x);
            flag = 1;
            return;
        }
        if (dep >= 20) return;
        dfs(x.multiply(BigInteger.valueOf(10)), dep + 1);
        dfs(x.multiply(BigInteger.valueOf(10)).add(BigInteger.ONE), dep + 1);
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        flag = 0;
        n = in.nextInt();
        Main.dfs(BigInteger.ONE, 0);
    }
}
