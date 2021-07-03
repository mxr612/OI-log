var
  i,j,n,k,m:integer;
  a,b:array[1..100] of integer;
  f1,f2:text;
begin
  assign(f1,'num.in');
  reset(f1);
  readln(f1,n);
  for i:=1 to n do
   begin
    read(f1,a[i]);
    b[i]:=a[i];
   end;
  readln(f1,k);
  close(f1);
  for i:=1 to n-1 do
   for j:=i+1 to n do
     if a[i]<a[j] then
        begin
          m:=a[i];
          a[i]:=a[j];
          a[j]:=m;
        end;
   assign(f2,'num.out');
     rewrite(f2);
    writeln(f2,a[k]);
   for i:=1 to n do
     if a[k]=b[i] then
       begin
         writeln(f2,i);
       end;
   close(f2);
  end.

