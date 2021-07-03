program minnum;
var s:real;
    i,k,n:longint;
begin
  assign(input,'minnum.in');
  assign(output,'minnum.out');
  reset(input);
  rewrite(output);
  readln(k);
  i:=0; s:=0;
  repeat
    i:=i+1;
    s:=s+1/i;
  until s>k;
  writeln(i);
  close(input);
  close(output);
end.

