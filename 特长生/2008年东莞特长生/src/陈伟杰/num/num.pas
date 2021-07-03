const
  inf='num.in';
  ouf='num.out';

var
  a,place:array [1..100] of longint;
  n,k:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      place[i]:=i;
    end;
  readln;
  readln(k);
end;

procedure sort;
var
  i,j,t:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
          t:=a[i]; a[i]:=a[j]; a[j]:=t;
          t:=place[i]; place[i]:=place[j]; place[j]:=t;
        end;
end;

begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  init;
  sort;
  writeln(a[k]);
  writeln(place[k]);
  close(input);
  close(output);
end.
