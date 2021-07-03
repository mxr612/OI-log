var n,q:longint;
    s:real;
    sum:array[1..10000]of longint;
procedure land;
begin sum[1]:=1;
      for q:=2 to n*n do
        sum[q]:=sum[q-1]+sum[q-1];
      for q:=1 to n*n do
      s:=s+sum[q];
end;
begin assign(input,'land.in');
      assign(output,'land.out');
      reset(input);
      rewrite(output);
      readln(n);
      land;
      writeln(s:0:0);
      close(input);
      close(output);
end.
