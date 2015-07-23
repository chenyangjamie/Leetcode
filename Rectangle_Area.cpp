/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B)+(G-E)*(H-F);
        
        auto left = Max(A,E);
        auto bottom = Max(B,F);
        auto right = Min(C,G);
        auto top = Min(D,H);
        
        if(left > right || bottom > top)
        return area;
        
        area -= (top-bottom) * (right-left);
        return area;
    }
private:
    int Max(int a, int b){
        if(a>b) return a;
        return b;
    }
    int Min(int a, int b){
        if(a<b) return a;
        return b;
    }
};
