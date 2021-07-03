const
  maxn=300;
var
  a,b,c:array[0..maxn]of longint;
  n:longint;

procedure init;
var
  i,j:longint;
begin
  readln(n);
  for i:=1 to n do
    readln(b[i],a[i]);
end;

procedure main;
var
  i,j,x,y:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i]<a[j])or(a[i]=a[j])and(b[i]>b[j]) then
        begin
          a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
          b[0]:=b[i];b[i]:=b[j];b[j]:=b[0];
        end;
  x:=0;y:=0; a[0]:=-1;
  for i:=1 to n do
    begin
      y:=y+1;
      if a[i]=a[i-1] then c[i]:=c[i-1]
                     else c[i]:=y;
    end;
  for i:=1 to n do
    writeln(b[i],' ',a[i],' ',c[i]);
end;

begin
  assign(input,'sort.in');
  assign(output,'sort.out');
  reset(input);
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.