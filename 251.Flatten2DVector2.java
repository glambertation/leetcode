class MyIterator implements Iterator<Integer> {
    Iterator<List<Integer>> rowIter;
    Iterator<Integer> colIter;
    Iterator<Integer> preColIter; // 专门给remove用
    public MyIterator(List<List<Integer>> vec2d) {
        rowIter = vec2d.iterator();
        colIter = null;
        preColIter = null;
    }

    public boolean hasNext(){
        while (rowIter.hasNext() && (colInter == null || !colIter.hasNext())){
        colIter = rowIter.next().iterator();
        }
        return colIter != null && colIter.hasNext();
    }

    public Integer next(){
        if(hasNext()){
            preColIter = colIter; // 删的时候删它
            return colIter.next();
        }else {
            prevColiter = null;
            return null;
        }
    }

    public void remove(){
        if (prevColIter == null) return;
        prevColIter.remove();
    }


}
