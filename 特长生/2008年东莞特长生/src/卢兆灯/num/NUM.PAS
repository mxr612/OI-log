var
  i,j,k,n,l:integer;
  a,b:array[1..100]of integer;
begin
  assign(input,'num.in'); reset(input);
  assign(output,'num.out'); rewrite(output);
  read(n); readln;
  for i:=1 to n do read(a[i]);
  readln; read(k);
  b:=a;
  for i:=1 to n-1 do
  for j:=i to n do
  if b[i]<b[j] then
  begin
    l:=b[i];
    b[i]:=b[j];
    b[j]:=l;
  end;
  i:=1;
  while a[i]<>b[k] do i:=i+1;
  write(b[k]);writeln;
  write(i);
  close(input); close(output);
end.                          