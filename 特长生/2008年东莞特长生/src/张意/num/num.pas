program num;
var
 n,k,i,j,m:longint;
 a,b:array[1..100]of longint;
begin
 assign(input,'num.in');reset(input);
 assign(output,'num.out');rewrite(output);
 readln(n);
 for i:=1 to n do read(a[i]);
 readln(k);
 for i:=1 to n do b[i]:=a[i];
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if a[i]<a[j] then begin
    m:=a[i];a[i]:=a[j];a[j]:=m;
   end;
  writeln(a[k]);
  for i:=1 to n do
   if a[k]=b[i] then writeln(i);
  close(input);close(output);
end.