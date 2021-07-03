var
  a,b,x:array[1..20000] of longint;
  n,m,i,min:longint;
  p:boolean;
begin
  assign(input,'reward.in'); reset(input);
  assign(output,'reward.out'); rewrite(output);
  min:=0;
  readln(n,m);
  for i:=1 to n do x[i]:=100;
  for i:=1 to m do begin
    readln(a[i],b[i]);
    if x[a[i]]<=x[b[i]] then x[a[i]]:=x[b[i]]+1;
  end;
  p:=true;
  for i:=1 to m do
    if x[a[i]]<=x[b[i]] then p:=false;
  if p then
    for i:=1 to n do min:=min+ x[i]
  else min:=-1;
  writeln(min);
  close(input); close(output);
end.
