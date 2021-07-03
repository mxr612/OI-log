program land(input,output);
var
  n,t,i:longint;
  a:array[1..10000]of longint;
begin
  assign(input,'land.in'); reset(input);
  assign(output,'land.out'); rewrite(output);
  read(n);
  a[1]:=1;  a[2]:=2;
  for i:=3 to n*n do
    a[i]:=a[i-1]*2;
  for i:=1 to n*n do
    t:=t+a[i];
  write(t);
  close(input); close(output);
end.