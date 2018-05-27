import java.util.*;
import java.lang.*;
import java.io.*;
 
public class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner cin = new Scanner(System.in);
        int n = Integer.parseInt(cin.nextLine());
        while(n > 0) {
            n --;
            System.out.println(convertExpr(cin.nextLine()));
        }
    }
 
    public static String convertExpr(String s) {
        StringBuffer result = new StringBuffer();
        Stack<Node> st = buildTree(s);
        Deque<Node> q = new ArrayDeque<Node>();
        q.add(st.pop());
        while(!q.isEmpty()) {
            Node n = q.remove();
            result.append(n.key);
            if(!n.isLeafNode()) {
                q.add(n.left);
                q.add(n.right);
            }
        }
        return result.reverse().toString();
    }
    public static Stack<Node> buildTree(String s) {
        Stack<Node> st = new Stack<Node>();
        for(int i = 0; i < s.length(); i++) {
            char ele = s.charAt(i);
            Node n = new Node(ele);
            if(Character.isUpperCase(ele)) {
                n.right = st.pop();
                n.left = st.pop(); 
            }
            st.push(n);
        }
        return st;
    }
 
    public static class Node {
        char key;
        Node left;
        Node right;
 
        Node(char key) {
            this.key = key;
        }
 
        public boolean isLeafNode() {
            return Character.isLowerCase(this.key);
        }
    }
}