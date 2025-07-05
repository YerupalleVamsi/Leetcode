CURRENT = []
RESULT = []
    function DFS (i, sum) {
        if (sum == target) <<Push a copy of CURRENT into RESULT>>
        else if (sum < target) {
            for ( j is from i to len(candidates) ) {
                <<Push candidates[j] into CURRENT>>
                DFS(j, sum + candidates[j])
                <<Pop one from CURRENT>>
            }
        }
        return RESULT
    }
    return DFS(0, 0)
}