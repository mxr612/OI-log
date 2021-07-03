var i,j,n:integer;
    m:longint;
    a:array[1..10000] of longint;
    f1,f2:text;
begin
  assign(f1,'land.in');
  reset(f1);
 readln(f1,n);
 close(f1);
 m:=0;
 a[1]:=1;
 for i:=2 to n*n do
   a[i]:=1;
 for j:=2 to n*n do
 for i:=1 to j-1 do
  a[j]:=a[j]*2;
  for i:=1 to n*n do
   m:=m+a[i];
   assign(f2,'land.out');
     rewrite(f2);
   writeln(f2,m);
   close(f2);
 end.