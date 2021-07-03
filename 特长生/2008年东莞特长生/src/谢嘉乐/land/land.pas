program land(input,output);
type arr=array [0..1000] of longint;
var ans,mi:arr;
    num:array [0..20] of longint;
    n,i:longint;

procedure che(var x:arr; y:arr);
var t:arr;
    i,j:longint;
begin
  fillchar(t,sizeof(t),0);
  for i:=1 to x[0] do
    for j:=1 to y[0] do
      inc(t[i+j-1],x[i]*y[j]);
  t[0]:=x[0]+y[0]-1;
  for i:=1 to t[0] do
    if t[i]>9
    then
    begin
      inc(t[i+1],t[i] div 10);
      t[i]:=t[i] mod 10;
    end;
  while t[t[0]+1]>0 do
  begin
    inc(t[0]);
    inc(t[t[0]+1],t[t[0]] div 10);
    t[t[0]]:=t[t[0]] mod 10;
  end;
  x:=t;
end;

begin
  assign(input,'land.in');
  assign(output,'land.out');
  reset(input);
  rewrite(output);
  read(input,n);  i:=0;  n:=n*n;
  while n>0 do
  begin
    inc(i);
    num[i]:=n mod 2;
    n:=n div 2;
  end;
  num[0]:=i;
  if num[1]=1
  then ans[1]:=2
  else ans[1]:=1;
  ans[0]:=1;
  mi[0]:=1; mi[1]:=2;
  for i:=2 to num[0] do
  begin
    che(mi,mi);
    if num[i]=1
    then che(ans,mi);
  end;
  dec(ans[1]);
  for i:=ans[0] downto 1 do write(output,ans[i]);
  close(input);
  close(output);
end.