const
  inf='land.in';
  ouf='land.out';

var
  n:longint;
  ans,now,t:array [1..500] of longint;

procedure mul;
var
  i:longint;
begin
  for i:=1 to 500 do
    now[i]:=now[i]*2;
  for i:=500 downto 2 do
    begin
      now[i-1]:=now[i-1]+now[i] div 10;
      now[i]:=now[i] mod 10;
    end;
end;

procedure plus;
var
  i:longint;
begin
  t:=ans;
  for i:=1 to 500 do
    ans[i]:=t[i]+now[i];
  for i:=500 downto 2 do
    begin
      ans[i-1]:=ans[i-1]+ans[i] div 10;
      ans[i]:=ans[i] mod 10;
    end;
end;

procedure main;
var
  i:longint;
begin
  fillchar(now,sizeof(now),0);
  fillchar(ans,sizeof(ans),0);
  ans[500]:=1; now[500]:=1;
  for i:=1 to n*n-1 do
    begin
      mul;
      plus;
    end;
end;

procedure print;
var
  i,j:longint;
begin
  j:=1; while ans[j]=0 do j:=j+1;
  for i:=j to 500 do
    write(ans[i]);
end;

begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  readln(n);
  main;
  print;
  close(input);
  close(output);
end.