var x,n,i,j,t:longint;
    a,c:array[1..200]of longint;
    b:array[0..200]of longint;
begin
assign(input,'sort.in');
assign(output,'sort.out');
reset(input);
rewrite(output);
 readln(n);
 for i:=1 to n do readln(a[i],b[i]);
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if b[i]<b[j] then begin
                      t:=b[i];b[i]:=b[j];b[j]:=t;
                      t:=a[i];a[i]:=a[j];a[j]:=t;
                     end;
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if (a[i]>a[j])and(b[i]=b[j]) then
     begin
      t:=b[i];b[i]:=b[j];b[j]:=t;
      t:=a[i];a[i]:=a[j];a[j]:=t;
     end;
 x:=1;b[0]:=0;
 for i:=1 to n do
  if b[i]=b[i-1] then  c[i]:=x else begin c[i]:=i;x:=i;end;
 for i:=1 to n-1 do writeln(a[i],' ',b[i],' ',c[i]);
  write(a[n],' ',b[n],' ',c[n]);
close(input);close(output);
end.