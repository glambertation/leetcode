class Vector2D {
    int[][] v;
    int row, col;

    public Vector2D(int[][] v){
        this.v = v;
        row = 0;
        col = 0;
        }
    }

    public int next(){
        if(hasNext()) {
            return v[row][col++];
        }
        return -1;
    }

    public boolean hasNext() {
        while(row<v.length && col == v[row].length){
            row++;
            col = 0;
        }
        return (row < v.length);    
     }

}
