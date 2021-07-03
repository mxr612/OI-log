var
  a,b,i,j,k,n,m:integer;
  x:array[1..10000]of integer;
  y:array[1..2]of integer;
begin
  assign(input,'reward.in');reset(input);
  assign(output,'reward.out');rewrite(output);
  read(n,m); readln;
  for i:=1 to m do
  begin
    read(a,b);
    if x[a]<=x[b] then
    x[a]:=x[b]+1;
  end;
  k:=100*n;
  for i:=1 to n do k:=k+x[i];
  write(k);
  close(input); close(output);
end.