program land;
var
 n,i,j,k,m,p,a:longint;
begin
 assign(input,'land.in');
 reset(input);
 assign(output,'land.out');
 rewrite(output);
 readln(n);
 k:=n*n; m:=n; j:=k-2;
  p:=j;
  while p<>0 do begin
   m:=m*n;
   dec(p);
   a:=a+m;
  end;
 a:=a+1+n;
 writeln(a);
 close(input);close(output);
end.