var
   n,i,k:longint;
   t,s:double;
begin
   assign(input,'minnum.in');reset(input);
   assign(output,'minnum.out');rewrite(output);

   readln(k);

   s:=0;i:=0;
   while s<=k do
   begin
      inc(i);
      t:=1/i;
      s:=s+t
   end;

   writeln(i);

   close(input);close(output)
end.
