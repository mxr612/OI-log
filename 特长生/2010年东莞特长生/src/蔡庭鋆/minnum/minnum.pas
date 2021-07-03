program x01;
var i,j,k:longint;  t:real;
begin
   assign(input,'minnum.in');
   reset(input);
   assign(output,'minnum.out');
   rewrite(output);

   readln(k);   i:=0;  t:=0;
   while t<=k do begin
     inc(i);
     t:=t+(1/i);
     if t>k then break;
   end;
   writeln(i);

   close(input);
   close(output);
end.