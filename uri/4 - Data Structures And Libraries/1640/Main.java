// Complexity: O(n * h)

import java.util.*;
import java.io.*;

class Edge {
    private int dest, c;
    public Edge(int destination, int cost) {
        dest = destination;
        c = cost;
    }
    public int getDestination() {
        return dest;
    }
    public int getCost() {
        return c;
    }
}

public class Main {
    public static void main(String [] args) throws Exception {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        int n;
        boolean [] has_hotel = new boolean[10000];
        int [] d = new int[10000];
        int [] Q = new int[101];
        ArrayList [] r = new ArrayList[601];
        for (int i=0; i<601; ++i)
            r[i] = new ArrayList();
        ArrayList [] adj = new ArrayList[10000];
        for (int i=0; i<10000; ++i)
            adj[i] = new ArrayList();
        while((n = Integer.parseInt(br.readLine())) != 0) {
            for (int i=0; i<n; ++i) {
                has_hotel[i] = false;
                adj[i].clear();
            }
            has_hotel[n-1] = true;
            StringTokenizer strTok = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(strTok.nextToken());
            for (int i=0; i<h; ++i) {
                int a = Integer.parseInt(strTok.nextToken());
                has_hotel[a-1] = true;
            }
            int m = Integer.parseInt(br.readLine());
            while(m-- > 0) {
                strTok = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(strTok.nextToken()) - 1;
                int b = Integer.parseInt(strTok.nextToken()) - 1;
                int dist = Integer.parseInt(strTok.nextToken());
                adj[a].add(new Edge(b, dist));
                adj[b].add(new Edge(a, dist));
            }
            Q[0] = 0;
            int l = 1, res = -1;
            while(l > 0 && has_hotel[n-1]) {
                ++res;
                for (int i=0; i<=600; ++i)
                    r[i].clear();
                for (int i=0; i<n; ++i)
                    d[i] = Integer.MAX_VALUE;
                for (int i=0; i<l; ++i) {
                    d[Q[i]] = 0;
                    r[0].add(Q[i]);
                }
                l = 0;
                // modified dijkstra which uses the fact that we are only interested in distances <= 600
                for (int i=0; i<=600; ++i) {
                    for (Iterator it = r[i].iterator(); it.hasNext();) {
                        int c = (Integer)it.next();
                        if (d[c] < i)
                            continue;
                        if (has_hotel[c]) {
                            has_hotel[c] = false;
                            Q[l++] = c;
                        }
                        for (Iterator it2 = adj[c].iterator(); it2.hasNext(); ) {
                            Edge e = (Edge)it2.next();
                            int ndist = e.getCost() + i;
                            if (ndist <= 600 && ndist < d[e.getDestination()]) {
                                d[e.getDestination()] = ndist;
                                r[ndist].add(e.getDestination());
                            }
                        }
                    }
                }
            }
            System.out.println(has_hotel[n-1]? -1 : res);
        }
    }
}