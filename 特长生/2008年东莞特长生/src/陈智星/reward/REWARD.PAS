var
  a,b,c:array[1..2000] of longint;
  n,m,sum:longint;
procedure rr;
  var
    f1:text;
    i:integer;
  begin
    assign(f1,'reward.in');
    reset(f1);
    readln(f1,n,m);
    for i:=1 to m do
      readln(f1,a[i],b[i]);
    close(f1);
  end;
procedure main;
  var
    i,j:integer;
  begin
    for i:=1 to n do
      c[i]:=100;
    for j:=1 to m do
      for i:=1 to n do
        if c[a[i]]<=c[b[i]] then c[a[i]]:=c[b[i]]+1;
    for i:=1 to n do
      sum:=sum+c[i];
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if (a[i]=b[j]) and (b[i]=a[j]) then sum:=-1;
  end;
procedure ww;
  var
    f2:text;
  begin
    assign(f2,'reward.out');
    rewrite(f2);
    writeln(f2,sum);
    close(f2);
  end;
begin
  rr;
  main;
  ww;
end.