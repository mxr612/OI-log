const
     inf='num.in';
     ouf='num.out';
     maxn=1000;
type
    arr=record
          s,w:longint;
        end;
var
     a:array[1..maxn] of arr;
     n,k:longint;

 procedure qsort(l,r:longint);
   var
     i,j,mid:longint;
     t:arr;
   begin
     if l>=r then exit;
     i:=l; j:=r; mid:=a[(l+r) div 2].s;
     repeat
       while a[i].s>mid do inc(i);
       while a[j].s<mid do dec(j);
       if i<=j then
       begin
         t:=a[i];
         a[i]:=a[j];
         a[j]:=t;
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
     begin
       read(a[i].s);
       a[i].w:=i;
     end;
     readln(k);
   end;

begin
     assign(input,inf);  reset(input);
     assign(output,ouf); rewrite(output);
     init;
     qsort(1,n);
     writeln(a[k].s);
     writeln(a[k].w);
     close(input);
     close(output);
end.