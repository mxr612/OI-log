Program stamps;
var n,m,i,j,k,max,a,b,z,count:longint;
    x:array[1..100] of byte;
    canbe:array[1..25500] of boolean;
    hey:boolean;
begin
assign(input,'stamps.in');
reset(input);
assign(output,'stamps.out');
rewrite(output);
 readln(n);
 readln(m);
 for i:=1 to m do read(x[i]);
 {Type 1}
 for i:=1 to m do
  for j:=1 to n do
   canbe[x[i]*j]:=true;
 {Type 2 - Full }
 for i:=1 to n do
  for j:=n-i downto 1 do
   for z:=2 to m do begin
   canbe[x[z]*i+x[z-1]*j]:=true;
   canbe[x[z]*j+x[z-1]*i]:=true; end;
 hey:=false;
 for i:=1 to 25500 do begin
  if (canbe[i]) and not(hey) then count:=count+1;
  if (canbe[i])and(canbe[i+1]=false) then hey:=true;
 end;
 writeln(count);
close(input);
close(output);
end.
