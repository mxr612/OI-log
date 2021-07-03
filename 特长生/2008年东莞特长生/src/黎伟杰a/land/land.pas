program  land(input,output);
var
   a,b:array[1..500]of integer;
   i,k,yu,we:longint;
   n:integer;

   l:string;

begin
   assign(input,'land.in');
   assign(output,'land.out');
   reset(input);
   rewrite(output);
   fillchar(a,sizeof(a),0);
   fillchar(b,sizeof(b),0);
   read(yu);
   {n:=length(l);
   we:=1;
   for i:=n downto 1 do
   begin a[n+1-i]:=ord(l[i])-48;
   yu:=yu+a[n+1-i]*we;we:=we*10;
   end; }
   n:=1;a[1]:=1;b[1]:=1;
   if yu>1 then
   begin
   for k:=1 to (yu*yu-1) do
   begin
     for i:=1 to n do
      begin
       a[i]:=a[i]+a[i];
       b[i]:=b[i]+a[i];
      end;
     for i:=1 to n do

      begin
         if  a[i]>=10 then begin inc(a[i+1]);a[i]:=a[i]mod 10;end;
         if  b[i]>=10 then begin b[i+1]:=b[i+1]+b[i]div 10;b[i]:=b[i]mod 10;if i=n then inc(n);end;
      end;
   end;
   for i:=n downto 1 do write(b[i]);
   end
   else if yu=1 then write(1) else write(0);
   close(input);
   close(output);
end.