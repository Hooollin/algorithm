public class DisjointSet{
	private int[] parent;
	private int[][] edges;
	private int[] rank;
	public DisjointSet(int vertices, int[][] edges){
		this.parent = new int[vertices];
		this.rank = new int[vertices];
		this.edges = edges;
		for(int i = 0; i < parent.length; i++){
			parent[i] = -1;
			rank[i] = 0;
		}
	}

	int findParent(int x){
		while(parent[x] != -1){
			x = this.parent[x];
		}
		return x;
	}
	// 0 -> failed      1 -> successfully
	int unionVertices(int x, int y){
		int xRoot = findParent(x);
		int yRoot = findParent(y);
		if(xRoot == yRoot){
			return 0;
		}
		if(rank[xRoot] > rank[yRoot]){
			parent[yRoot] = xRoot;
		}else if(rank[yRoot] > rank[xRoot]){
			parent[xRoot] = yRoot;
		}else{
			parent[xRoot] = yRoot;
			rank[yRoot] += 1;
		}
		return 1;
	}

	public boolean hasCycle(){
		for(int i = 0; i < edges.length; i++){
			int x = edges[i][0];
			int y = edges[i][1];
			if(0 == unionVertices(x, y)){
				return true;
			}
		}
		return false;
	}

	public void print(){
		for(int i = 0; i < rank.length; i++){
			System.out.print(rank[i] + " ");
		}
		System.out.println();
		for(int i = 0; i < parent.length; i++){
			System.out.print(parent[i] + " ");
		}
	}

	public static void main(String[] args) {
		int vertices = 6;
		int[][] edges = new int[][]{{0, 1}, {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 4}};
		DisjointSet djs = new DisjointSet(vertices, edges);
		if(djs.hasCycle()){
			System.out.println("cycle detected!");
		}else{
			System.out.println("no cycles found!");
		}
		djs.print();
	}
}