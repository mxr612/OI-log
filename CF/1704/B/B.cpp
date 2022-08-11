/**
 * @file B.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2022-07-31
 * @brief 
 */

#include <stdio.h>
#include <algorithm>

const int MXI = 1e9,
          MXN = 200020;
class XDS {
    int ll, rr;
    struct Node {
        int min,max;
        Node *ls, *rs;
    } * root;

    Node *make_node() {
        Node *x = NULL;
        while (!x) x = (Node *)calloc(sizeof(Node), 1);
        x->min = MXI,x->max = 0;
        return x;
    }

    void merge_up(Node *x) {
        if(x){
            x->min=MXI,x->max=0;
            if (x->ls) x->min = std::min(x->min, x->ls->min),x->max=std::max(x->max,x->ls->max);
            if (x->rs) x->min = std::min(x->min, x->rs->min),x->max=std::max(x->max,x->rs->max);
        }
    }

    void insert(Node *&x, int l, int r, const int P, const int W) {
        if (r < l || r < P || P < l) return;
        if (!x) x = make_node();
        if (l < r)
            insert(x->ls, l, (l + r) / 2, P, W), insert(x->rs, (l + r) / 2 + 1, r, P, W), merge_up(x);
        else
            x->min = x->max=W;
    }

    int query_min(Node *x, int l, int r, const int L, const int R) {
        if (!x || r < l || r < L || R < l || R < L) return 0;
        return (L <= l && r <= R) ? (x->min) : (std::min(query_min(x->ls, l, (l + r) / 2, L, R), query_min(x->rs, (l + r) / 2 + 1, r, L, R)));
    }
    int query_max(Node *x, int l, int r, const int L, const int R) {
        if (!x || r < l || r < L || R < l || R < L) return 0;
        return (L <= l && r <= R) ? (x->max) : (std::max(query_max(x->ls, l, (l + r) / 2, L, R), query_max(x->rs, (l + r) / 2 + 1, r, L, R)));
    }

   public:
    XDS() {
        ll = 1, rr = MXN-5;
        root = NULL;
    }
    void insert(int p, int w) { insert(root, ll, rr, p, w); }
    int min(int L, int R) { return query_min(root, ll, rr, L, R); }
    int max(int L, int R) { return query_max(root, ll, rr, L, R); }
}arr,val;

int main(){
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
#endif

    int t,n,x,a;

    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&x),x*=2;
        for(int l=1,r=1;r<=n;++r){
            scanf("%d",&a);
            arr.insert(r,a);
            // while(arr.max(l,r)-arr.min(l,r)>x)++l;
            // if(l<r)
            //     val.insert(r,val.min(l,r-1)+1);
            // else
            //     val.insert(r,val.min(r-1,r-1)+1);
            printf("%d,%d ",arr.max(r,r),arr.min(r,r));
        }
        printf("%d\n",val.min(n,n));
    }

    return 0;
}