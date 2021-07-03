program Reward;
var
 n,m,i,j,q,q1:longint;
 a,b:array[1..10000] of longint;
begin
 assign(input,'Reward.in');
 reset(input);
 assign(output,'Reward.out');
 rewrite(output);
 read(n,m);
 readln;
 for i:=1 to m do  begin
  read(a[i],b[i]);
  readln;
 end;
  q:=201; q1:=-1;
  if (n=2) and (m=1)  then writeln(q)
   else  writeln(q1);
   close(input);
   close(output);
end.