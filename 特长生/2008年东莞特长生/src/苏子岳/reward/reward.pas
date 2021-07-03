const
  inf='reward.in';
  ouf='reward.out';
  maxn=1000;
var
  s,n,m:longint;
  cd,v,q:array[0..maxn] of integer;
  a:array[0..maxn,0..maxn] of integer;
procedure init;
  var
    x,y,i:integer;
  begin
    assign(input,inf);
    assign(output,ouf);
    reset(input);
    rewrite(output);
    readln(n,m);
    fillchar(cd,sizeof(cd),0);
    for i:=1 to m do
      begin
        readln(x,y);
        inc(cd[x]);
        inc(a[y,0]);
        a[y,a[y,0]]:=x
      end
  end;
procedure print;
  begin
    writeln(s);
    close(input);
    close(output)
  end;
procedure dfs(i,x:integer);
  var
    j:integer;
  begin
    if x>q[i]
      then q[i]:=x;
    for j:=1 to a[i,0] do
      if v[a[i,j]]=1
        then
          begin
            s:=-1;
            print;
            halt
          end
        else
          begin
            v[i]:=1;
            dfs(j,x+1)
          end
  end;
procedure work;
  var
    i,j:integer;
    f:boolean;
  begin
    for i:=1 to n do
      q[i]:=100;
    f:=false;
    for i:=1 to n do
      if cd[i]=0
        then
          begin
            fillchar(v,sizeof(v),0);
            dfs(i,q[i]);
            f:=true
          end;
    for i:=1 to n do
      for j:=1 to a[i,0] do
        if q[i]=q[j]
          then
            begin
              s:=-1;
              print;
              halt
            end;
    if f
      then
        begin
          s:=0;
          for i:=1 to n do
            inc(s,q[i])
        end
      else s:=-1
  end;
begin
  init;
  work;
  print
end.
