const
  maxn=30000;
var
  f:array[0..maxn]of boolean;
  a,t:array[0..maxn]of longint;
  n,m:longint;

procedure main;
var
  i,j,k:longint;
begin
  readln(n);
  readln(m);
  for i:=1 to m do
    readln(a[i]);
  for i:=1 to maxn do t[i]:=maxlongint;
  f[0]:=true;t[0]:=0;
  for i:=0 to maxn do
    if not f[i] then
      begin
        writeln(i-1);
        exit;
      end
    else
      begin
        for j:=1 to m do
          begin
            if t[i]<n then f[i+a[j]]:=true;
            if t[i]+1<t[i+a[j]] then t[i+a[j]]:=t[i]+1;
          end;
      end;
end;

begin
  assign(input,'stamps.in');
  assign(output,'stamps.out');
  reset(input);
  rewrite(output);
  main;
  close(input);
  close(output);
end.
