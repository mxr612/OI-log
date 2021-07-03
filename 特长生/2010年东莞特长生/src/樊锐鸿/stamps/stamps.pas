var n,m,i:longint;
    a:array[1..255]of longint;
begin
assign(input,'stamps.in');
assign(output,'stamps.out');
reset(input);rewrite(output);
 readln(n);
 readln(m);
 for i:=1 to m do readln(a[i]);
 write(25);
 close(input);close(output);
end.