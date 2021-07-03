const
  inf='reward.in';
  ouf='reward.out';

type
  re=^node;
  node=record
         y:longint;
         next:re;
       end;

var
  ans,innum,list,v:array [1..10000] of longint;
  a:array [1..10000] of re;
  n,m,tail:longint;

procedure init;
var
  i,xx,yy:longint;
  p,q:re;
begin
  readln(n,m);
  fillchar(innum,sizeof(innum),0);
  for i:=1 to n do a[i]:=nil;
  for i:=1 to m do
    begin
      readln(xx,yy);
      inc(innum[xx]);
      if a[yy]=nil then
        begin
          new(a[yy]);
          a[yy]^.y:=xx;
          a[yy]^.next:=nil;
          continue;
        end;
      q:=a[yy];
      p:=a[yy]^.next;
      while p<>nil do
        begin
          p:=p^.next;
          q:=q^.next;
        end;
      new(p);
      p^.y:=xx;
      p^.next:=nil;
      q^.next:=p;
    end;
end;

function max(xx,yy:longint):longint;
begin
  if xx>yy then max:=xx
           else max:=yy;
end;

procedure dfs(xx:longint);
var
  q:re;
begin
  q:=a[xx];
  while q<>nil do
    begin
      ans[q^.y]:=max(ans[q^.y],ans[xx]+1);
      dec(innum[q^.y]);
      if innum[q^.y]=0 then
        begin
          v[q^.y]:=1;
          inc(tail);
          list[tail]:=q^.y;
          dfs(q^.y);
        end;
      q:=q^.next;
    end;
end;

procedure topsort;
var
  i,j,s:longint;
begin
  for i:=1 to n do ans[i]:=100;
  tail:=0;
  fillchar(v,sizeof(v),0);
  for i:=1 to n do
    if (v[i]=0)and(innum[i]=0) then
      begin
        inc(tail);
        list[tail]:=i;
        v[i]:=1;
        dfs(i);
      end;
  if tail<n then
    writeln('-1')
  else
    begin
      s:=0;
      for i:=1 to n do
        s:=s+ans[i];
      writeln(s);
    end;
end;

begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  init;
  topsort;
  close(input);
  close(output);
end.
