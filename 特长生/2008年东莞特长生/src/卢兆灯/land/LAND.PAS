var
  i,j,k,n:longint;
  a:array[1..500] of integer;
begin
  assign(input,'land.in'); reset(input);
  assign(output,'land.out'); rewrite(output);
  read(n);
  a[1]:=1; k:=1;
  for i:=1 to n*n do
  begin
    for j:=1 to k do
    a[j]:=a[j]*2;
    if a[k]>10 then k:=k+1;
    for j:=1 to k do
    if a[j]>10 then
    begin
      a[j+1]:=a[j+1]+a[j] div 10;
      a[j]:=a[j] mod 10;
    end;
  end;
  a[1]:=a[1]-1;
  for i:=k downto 1 do write(a[i]);
  close(input); close(output);
end.


