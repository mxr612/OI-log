var
        i,j,n:longint;
        a,b:array[0..501] of longint;
begin
        assign(input,'land.in');reset(input);
        assign(output,'land.out');rewrite(output);

        readln(n);
        a[1] := 1;a[0]:=1;
        for i := 1 to n*n do
        begin
                fillchar(b,sizeof(b),0);
                for j := 1 to a[0] do
                begin
                        b[j+1] := (a[j]*2+b[j]) div 10;
                        b[j] := (a[j]*2+b[j]) mod 10;
                end;
                if b[j+1]<>0 then inc(a[0]);
                for j := 1 to a[0] do a[j] := b[j];
        end;
        dec(a[1]);
        for i := a[0] downto 1 do       write(a[i]);
        writeln;

        close(input);close(output);
end.


