const
     inf='land.in';
     ouf='land.out';
     maxn=625;
var
     a,b:array[1..maxn] of longint;
     p,n,m:longint;

 procedure make;
   var
     i:longint;
   begin
     for i:=1 to maxn do a[i]:=a[i]*2;
     for i:=1 to maxn-1 do
       if a[i]>9 then
       begin
         a[i+1]:=a[i+1]+a[i] div 10;
         a[i]:=a[i] mod 10;
       end;
   end;

begin
     assign(input,inf);  reset(input);
     assign(output,ouf); rewrite(output);
     readln(n);
     if n=0 then
     begin
       writeln(0);
       close(input);
       close(output);
       exit;
     end;
     a[1]:=1;
     for p:=1 to n*n do make;
     a[1]:=a[1]-1;
     m:=0;
     for p:=maxn downto 1 do
       if a[p]<>0 then
       begin
         m:=p;
         break;
       end;
     for p:=m downto 1 do write(a[p]);
     close(input);
     close(output);
end.