var
   a,c,n:integer;
   total:longint;
   f1,f2:text;
begin
   assign(f1,'land.in');
   assign(f2,'land.out');
   reset(f1);reset(f2);
   read(f1,n);
   a:=n*n;
   for c:=1 to a do
   total:=1+2+4+8+








   rewrite(f2,total);
   close(f1); close(f2);
end.