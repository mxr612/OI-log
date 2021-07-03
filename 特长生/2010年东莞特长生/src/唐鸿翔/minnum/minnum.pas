var c,d,e,f,g:longint;
h,a,b:real;
begin
assign(input,'minnum.in');
reset(input);
assign(output,'minnum.out');
rewrite(output);
read(a);b:=1;h:=1;c:=1;
  repeat
  inc(c);
  h:=1/c;
  b:=b+h;
  until b>a;
 writeln(c);
 close(input);close(output);
end.
