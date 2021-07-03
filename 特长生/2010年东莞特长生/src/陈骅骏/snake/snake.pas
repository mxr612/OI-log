const
   maxn=100;
var
   a:array[1..maxn,1..maxn]of longint;
   i,j,k,m,n:longint;
begin
   assign(input,'snake.in');reset(input);
   assign(output,'snake.out');rewrite(output);

   readln(n);

   k:=n*n;
   for i:=2 to 2*n do
   begin
      if i and 1=0 then
      begin
         for j:=1 to i-1 do
         begin
            if (i-j>n) or (j>n) then continue;
            a[j,i-j]:=k;
            dec(k)
         end
      end
      else
      begin
         for j:=i-1 downto 1 do
         begin
            if (i-j>n) or (j>n) then continue;
            a[j,i-j]:=k;
            dec(k)
         end
      end
   end;

   for i:=1 to n do
   begin
      write(a[i,1]);
      for j:=2 to n do write(' ',a[i,j]);
      writeln
   end;

   close(input);close(output)
end.
