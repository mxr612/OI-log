const
  inf='work.in';
  ouf='work.out';
  maxnum=10000000;

var
  n,nowmax,now,ans:longint;
  t,a,b:array [1..1000] of longint;
  f:array [0..1500] of longint;

procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    readln(t[i],a[i],b[i]);
  ans:=maxnum;
  now:=0;
  nowmax:=-1;
end;

procedure sort;
var
  i,j,temp:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        begin
          temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
          temp:=b[i]; b[i]:=b[j]; b[j]:=temp;
          temp:=t[i]; t[i]:=t[j]; t[j]:=temp;
        end;
end;

function max(xx,yy:longint):longint;
begin
  if xx>yy then max:=xx
           else max:=yy;
end;

procedure dfs(dep:longint);
var
  i,temp:longint;
begin
  if now>=ans then exit;
  if dep=n+1 then
    begin
      ans:=now;
      exit;
    end;
  if nowmax+t[dep]<=b[dep] then
    begin
      temp:=nowmax;
      nowmax:=max(a[dep],nowmax)+t[dep];
      now:=now+t[dep];
      dfs(dep+1);
      nowmax:=temp;
      now:=now-t[dep];
      if (dep<n)and(a[dep]=a[dep+1]) then
        dfs(dep+1);
    end
  else dfs(dep+1);
end;


begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  init;
  sort;
  dfs(1);
  writeln(ans);
  close(input);
  close(output);
end.
