program reward(input,output);
var money:array [1..10000] of integer;
    b:array [1..20000,1..2] of integer;
    bz,bzt,into:array [0..10000] of integer;
    z:array [1..10000] of boolean;
    n,m,i,j,t,t1,ans:longint;
begin
  assign(input,'reward.in');
  assign(output,'reward.out');
  reset(input);
  rewrite(output);
  read(input,n,m);
  fillchar(bzt,sizeof(bzt),0);
  fillchar(into,sizeof(into),0);
  for i:=1 to m do
  begin
    read(input,b[i,1],b[i,2]);
    inc(bzt[b[i,2]]);
    inc(into[b[i,1]]);
  end;
  bzt[n]:=m+1-bzt[n];
  for i:=n-1 downto 1 do
    bzt[i]:=bzt[i+1]-bzt[i];
  for i:=1 to m do
  begin
    bz[bzt[b[i,2]]]:=i;
    inc(bzt[b[i,2]]);
  end;
  bzt[0]:=0;
  for i:=1 to n do dec(bzt[i]);
  for i:=1 to n do begin z[i]:=true;  money[i]:=100; end;
  ans:=0;
  for i:=1 to n do
  begin
    t:=20001; t1:=0;
    for j:=1 to n do
      if (z[j]) and (t>into[j])
      then begin t:=into[j]; t1:=j; end;
    if t>0
    then begin ans:=-1; break; end;
    z[t1]:=false;
    for j:=bzt[t1-1]+1 to bzt[t1] do
    begin
      t:=b[bz[j],1];
      if money[t]<money[t1]+1
      then money[t]:=money[t1]+1;
      dec(into[t]);
    end;
  end;
  if ans>-1
  then for i:=1 to n do inc(ans,money[i]);
  write(output,ans);
  close(input);
  close(output);
end.
