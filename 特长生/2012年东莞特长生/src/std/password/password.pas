program password;
  var a,b,c,d,i:longint;
  begin
    assign(input,'password.in');
    reset(input);
    assign(output,'password.out');
    rewrite(output);
    readln(a,b,c);
    d:=1;
    for i:=1 to b do
      d:=d*a mod c;
    writeln(d);
    close(input);
    close(output);
  end.