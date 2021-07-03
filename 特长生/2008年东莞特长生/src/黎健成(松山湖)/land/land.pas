const
  inf='land.in';
  ouf='land.out';
  maxn=500;

var
  a:array[1..maxn] of longint;
  m,n:longint;

procedure mul;
var
  i,g:longint;
begin
  g:=0;
  for i:=1 to m+1 do
    begin
      a[i]:=a[i]*2+g;
      g:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
  while a[m+1]<>0 do inc(m);
end;

procedure main;
var
  i:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  m:=1;
  a[1]:=1;
  for i:=1 to n*n do mul;
  a[1]:=a[1]-1;
  for i:=m downto 1 do write(a[i]);
  writeln;
end;

begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  main;
  close(input);
  close(output);
end.