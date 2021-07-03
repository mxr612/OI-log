const
  inf='reward.in';
  ouf='reward.out';
  maxn=10000;
var
  a:array[1..maxn,1..maxn] of boolean;
  f:array[1..maxn] of boolean;
  p,q,v:array[0..maxn] of longint;
  ans,n,m:longint;

procedure work;
var
  i,j,s:longint;
begin
  ans:=0;
  fillchar(q,sizeof(q),0);
  for i:=1 to n do
    if v[i]=0 then break;
  repeat
    if v[i]<>0 then
      begin
        writeln(-1);
        exit;
      end;
    if i=q[ans] then
      begin
        for i:=1 to n do
          if (v[i]=0) and not f[i] then break;
      end;
    inc(ans);
    q[ans]:=i;
    if ans=n then break;
    f[i]:=true;
    for j:=1 to n do
      if a[q[ans],j] then
        begin
          dec(v[j]);
          if v[j]=0 then i:=j;
        end;
  until false;
  fillchar(p,sizeof(p),0);
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
      if a[q[i],q[j]] and (p[q[j]]+1>p[q[i]]) then
        p[q[i]]:=p[q[j]]+1;
  s:=0;
  for i:=1 to n do s:=s+p[i];
  writeln(s+100*n);
end;

procedure main;
var
  i,x,y,fx,fy:longint;
begin
  readln(n,m);
  fillchar(a,sizeof(a),false);
  fillchar(v,sizeof(v),0);
  for i:=1 to m do
    begin
      readln(x,y);
      a[x,y]:=true;
      inc(v[y]);
    end;
  work;
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