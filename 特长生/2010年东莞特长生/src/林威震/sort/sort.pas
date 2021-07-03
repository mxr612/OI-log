var a:array[0..200,1..3]of longint;
    i,j,n:longint;
begin
 assign(input,'sort.in');
 assign(output,'sort.out');
 reset(input);
 rewrite(output);
 read(n);
 for i:=1 to n do read(a[i,1],a[i,2]);
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if (a[i,2]<a[j,2])or(a[i,2]=a[j,2])and(a[i,1]>a[j,1]) then
    begin
     a[0]:=a[i];
     a[i]:=a[j];
     a[j]:=a[0];
    end;
 for i:=1 to n do a[i,3]:=i;
 for i:=2 to n do
  if a[i,2]=a[i-1,2] then a[i,3]:=a[i-1,3];
 for i:=1 to n do
  writeln(a[i,1],' ',a[i,2],' ',a[i,3]);
 close(input);
 close(output);
end.