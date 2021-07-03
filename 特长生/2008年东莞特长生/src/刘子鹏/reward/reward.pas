program reward(input,output);
var n,m,i,j,p,ans,now,remain:longint;
    d:array[1..10000] of longint;
    edge:array[1..20000,1..2] of longint;
    st,en:array[1..10000] of longint;
    f:array[1..10000] of boolean;
    find:boolean;

procedure sort(l,r:longint);
var x,i,j,t:longint;
begin
  i:=l; j:=r;
  x:=edge[(l+r) shr 1,2];
  repeat
    while edge[i,2]<x do inc(i);
    while edge[j,2]>x do dec(j);
    if i<=j then begin
      t:=edge[i,1]; edge[i,1]:=edge[j,1]; edge[j,1]:=t;
      t:=edge[i,2]; edge[i,2]:=edge[j,2]; edge[j,2]:=t;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  assign(input,'reward.in');
  assign(output,'reward.out');
  reset(input); rewrite(output);

  readln(n,m);
  fillchar(d,sizeof(d),0);
  for i:=1 to m do begin
    readln(edge[i,1],edge[i,2]);
    inc(d[edge[i,1]]);
  end;
  sort(1,m);
  fillchar(st,sizeof(st),0);
  p:=edge[1,2];
  st[p]:=1;
  en[p]:=1;
  for i:=2 to m do
    if edge[i,2]=p then
      en[p]:=i
    else begin
      p:=edge[i,2];
      st[p]:=i;
      en[p]:=i;
    end;
  ans:=0;
  remain:=n;
  now:=100;
  while remain>0 do begin
    find:=false;
    fillchar(f,sizeof(f),true);
    for i:=1 to n do
      if (d[i]=0) and f[i] then begin
        find:=true;
        inc(ans,now);
        d[i]:=maxlongint;
        if st[i]>0 then
          for j:=st[i] to en[i] do begin
            dec(d[edge[j,1]]); f[edge[j,1]]:=false;
          end;
        dec(remain);
      end;
    inc(now);
    if not find then begin
      ans:=-1; break;
    end;
  end;
  writeln(ans);
  close(input); close(output);
end.
