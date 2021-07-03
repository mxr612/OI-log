program pp;
var n,i,k,j:integer;
    a,b:array[1..200] of integer;
procedure swap(var x,y:integer);
var t:integer;
begin
  t:=x;
  x:=y;
  y:=t;
end;
begin
  assign(input,'num.in');
  assign(output,'num.out');
  reset(input);rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  readln(k);
  for i:=1 to n-1 do
    for j:=i to n do
      if a[j]>a[i] then
      begin
        swap(a[j],a[i]);
        swap(b[j],b[i]);
      end;
  writeln(a[k]);
  writeln(b[k]);
  close(input);close(output)
end.