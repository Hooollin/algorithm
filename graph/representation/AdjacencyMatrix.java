import java.util.Scanner;

public class AdjacencyMatrix {
    private int vertexNum;

    private int edgeNum;

    private int[][] adjMatrix;

    public AdjacencyMatrix(int n, int e) {
        if (n == 0) {
            System.out.println("nothing to create");
            return;
        }
        this.adjMatrix = new int[n][n];
        this.vertexNum = n;
        this.edgeNum = e;

        Scanner in = new Scanner(System.in);
        for (int i = 0; i < e; i++) {
            System.out.println("v1:");
            int v1 = in.nextInt();
            System.out.println("v2:");
            int v2 = in.nextInt();
            adjMatrix[v1][v2] = 1;
            adjMatrix[v2][v1] = 1;
        }

        for (int i = 0; i < adjMatrix.length; i++) {
            adjMatrix[i][i] = 1;
        }

        for (int i = 0; i < adjMatrix.length; i++) {
            for (int j = 0; j < adjMatrix[0].length; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void dfs(int start) {
        boolean[] visited = new boolean[vertexNum];
        _dfs(visited, start);
    }

    public void _dfs(boolean[] visited, int i){
        if (visited[i]) {
            return;
        }
        System.out.print(i);
        visited[i] = true;
        for (int des = 0; des < vertexNum; des++) {
            if (adjMatrix[i][des] == 1 && !visited[des]) {
                System.out.print("->");
                _dfs(visited, des);
            }
        }
    
    }

    public static void main(String[] argv) {
        int[] vertices = new int[5];
        AdjacencyMatrix adjacencyMatrix = new AdjacencyMatrix(5, 3);
        adjacencyMatrix.dfs(0);
    }
}