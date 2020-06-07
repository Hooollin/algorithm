import java.util.Set;
import java.util.HashSet;
public class AdjacencyList{
	private int vertexNum;

	private int edgeNum;

	private Set<Integer>[] adj;

	public AdjacencyList(int v){

		this.vertexNum = v;
		adj = (HashSet<Integer>[]) new HashSet[v];
		for(int i = 0; i < adj.length; i++){
			adj[i] = new HashSet<>();
		}
	}

	public int getVertexNum(){
		return this.vertexNum;
	}

	public int getEdgeNum(){
		return this.edgeNum;
	}

	public void addEdge(int v1, int v2){
		if(adj[v1].add(v2) && adj[v2].add(v1)){
			this.edgeNum += 1;
		}
	}

	public void addEdges(int start, int ...ends){
			for(int e : ends){
				addEdge(start, e);
			}
	}

	public int inDegree(int v){
		int rev = 0;
		for(int i = 0; i < adj.length; i++){
			if(i != v){
				for(int e : adj[i]){
					if(e == v){
						rev += 1;
					}
				}
			}
		}
		return rev;
	}

	public int outDegree(int v){
		return adj[v].size();
	}

	public int degree(int v){
		return inDegree(v) + outDegree(v);
	}

	public Set<Integer> adjv(int v){
		return adj[v];
	}

	public String toString() {
        StringBuilder s = new StringBuilder("(" + vertexNum + " vertices, " + edgeNum + " edges)\n");
        for (int v = 0; v < vertexNum; v++) {
            s.append(v).append(": ");
            for (int w: this.adjv(v)) {
                s.append(w).append(" ");
            }
            s.append("\n");
        }
        return s.toString();
    }

	public static void main(String[] args) {
		AdjacencyList ajl = new AdjacencyList(6);
		ajl.addEdges(0, 1, 2, 3);
		ajl.addEdges(1, 2, 3);
		System.out.println(ajl.toString());
	}
}