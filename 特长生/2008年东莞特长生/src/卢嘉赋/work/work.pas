const
     inf='work.in';
     ouf='work.out';
     maxn=1005;
type
     arr=record
           t,a,b:longint;
        end;
var
     c:array[1..maxn ] of arr;
     v:array[1..maxn] of boolean;
     n,s,best:longint;

 procedure qsort(l,r:longint);
   var
     i,j,mid:longint;
     t:arr;
   begin
     if l>=r then exit;
     i:=l; j:=r; mid:=c[(l+r) div 2].a;
     repeat
       while c[i].a<mid do inc(i);
       while c[j].a>mid do dec(j);
       if i<=j then
       begin
         t:=c[i];
         c[i]:=c[j];
         c[j]:=t;
         inc(i);  dec(j);
       end;
     until i>j;
     qsort(l,j);
     qsort(i,r);
   end;

 procedure init;
   var
     i:longint;
   begin
     readln(n);
     for i:=1 to n do
       readln(c[i].t,c[i].a,c[i].b);
     fillchar(v,sizeof(v),true);
     s:=0;
     best:=maxlongint;
   end;

 procedure dfs(x,e:longint);
   var
     i:longint;
     flag:boolean;
   begin
     if s>best then exit;
     flag:=true;
     for i:=x to n do
       if (c[i].a<=e)and(c[i].t+e<=c[i].b)and(v[i]) then
       begin
         flag:=false;
         v[i]:=true;
         s:=s+c[i].t;
         dfs(i+1,c[i].b);
         s:=s-c[i].t;
         v[i]:=false;
//         if c[i+1].a<>c[i].a then break;
       end;
     if flag then if s<best then best:=s;
   end;

begin
     assign(input,inf);  reset(input);
     assign(output,ouf); rewrite(output);
     init;
     qsort(1,n);
     dfs(1,c[1].a);
     writeln(best);
     close(input);
     close(output);
end.
