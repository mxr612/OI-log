program work(input,output);
var n,i,j,maxt,mint,ans,tmp:longint;
    t,a,b:array[0..1000] of longint;
    //f,last:array[0..1500] of longint;
    //u:array[1..10] of boolean;
    //p:array[1..10] of integer;

function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;

procedure dfs(k,time,sum:longint);
var i:longint;
begin
  if (time+t[k]>maxt) or (k>n) then begin
    if sum<ans then ans:=sum;
    exit;
  end;
  for i:=k to n do begin
    if a[i]>time then break;
    if time+t[i]<=b[i] then
      dfs(i+1,time+t[i],sum+t[i])
    else if time+t[i]>maxt then begin
      if sum<ans then ans:=sum;
      exit;
    end;
  end;
end;

procedure sort(l,r:longint);
var x,i,j,tm:longint;
begin
  i:=l; j:=r;
  x:=a[(l+r) shr 1];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then begin
      tm:=a[i]; a[i]:=a[j]; a[j]:=tm;
      tm:=b[i]; b[i]:=b[j]; b[j]:=tm;
      tm:=t[i]; t[i]:=t[j]; t[j]:=tm;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  assign(input,'work.in');
  assign(output,'work.out');
  reset(input); rewrite(output);

  readln(n);
  maxt:=0;
  mint:=maxlongint;
  for i:=1 to n do begin
    readln(t[i],a[i],b[i]);
    if b[i]>maxt then maxt:=b[i];
  end;
  //fillchar(f,sizeof(f),0);
  //for i:=mint to maxt do f[i]:=maxlongint;
  //fillchar(last,sizeof(last),0);

  ans:=maxlongint;
  sort(1,n);
  dfs(1,a[1],0);
  writeln(ans);
  {if n<=5 then begin
    ans:=maxlongint;
    fillchar(u,sizeof(u),false);
    dfs(1);
    writeln(ans);
  end else begin
    for i:=0 to maxt do
    for j:=1 to n do
      if (i>=a[j]) and (i+t[j]<=b[j]) and ((f[i+t[j]]>f[i]+t[j]) or (f[i+t[j]]=0))
      then f[i+t[j]]:=f[i]+t[j];

  for i:=mint to maxt do
  for j:=1 to n do begin
    if (b[last[i-1]]+t[j]>i) and (f[i-1]<f[i]) then begin
      f[i]:=f[i-1]; last[i]:=last[i-1];
    end;
    if (i<=b[j]) and (i-t[j]>=a[j]) and (f[i-t[j]]+t[j]<f[i])
    then  begin
      last[i]:=j; f[i]:=f[i-t[j]]+t[j];
    end;
  end;

    writeln(f[maxt]);
    for i:=1 to maxt do
      if i mod 10=0 then writeln(f[i]:4) else write(f[i]:4);
    writeln;
  end; }
  close(input); close(output);
end.