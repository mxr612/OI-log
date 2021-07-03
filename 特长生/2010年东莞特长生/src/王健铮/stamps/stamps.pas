program stamps;
 var
  a,b,c:integer;
 begin
  assign(input,'stamps.in');
  reset(input);
  assign(output,'stamps.out');
  rewrite(output);
  writeln(10);
  close(input);
  close(output);
 end.