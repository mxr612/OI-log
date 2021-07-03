var n,m,i,x,j:integer;
    c,a,b:array[1..1000] of integer;
    f1,f2:text;
begin
  assign(f1,'reward.in');
  reset(f1);
   readln(f1,n,m);
  for i:=1 to m do
   readln(f1,a[i],b[i]);
   close(f1);
  assign(f2,'reward.out');
  rewrite(f2);
  for i:=1 to m-1 do
   for j:=i+1 to m do
    if (a[i]=b[j]) and (a[j]=b[i]) then
      begin
       writeln(f2,'-1');
       close(f2);
       halt;
      end;
   if a[1]=b[m] then
  for i:=1 to m-1 do
   for j:=i+1 to m do
    if (b[i]=a[j]) then
          begin
       writeln(f2, '-1');
       close(f2);
      halt;
      end;
  for i:=1 to n do
   c[i]:=100;
  for j:=1 to m do
    begin
      c[a[j]]:=c[a[j]]+1;
    end;
 for i:=1 to n do
   x:=x+c[i];
 writeln(f2,x);
 close(f2);
end.