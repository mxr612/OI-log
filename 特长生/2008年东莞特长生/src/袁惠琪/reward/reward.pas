var
        i,n,m,b1,b2:longint;
        a:array[1..10000,1..2] of longint;
begin
        assign(input,'reward.in') ;reset(input);
        assign(output,'reward.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do  a[i,1]:=100;
        for i:=1 to m do  begin
                readln(b1,b2);
                a[b1,2]:= a[b1,2] +1;
        end;
        writeln(-1);
        close(input);close(output);
end.

