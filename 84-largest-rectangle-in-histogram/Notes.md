<h2>largest-rectangle-in-histogram Notes</h2><hr>        // idea: is to find the next smaller and prev smaller ele for each index 
        // then cal area by subtracting nextSmaller - prevSmaller - 1
        // as in area we can only include the bars which are greater than the current