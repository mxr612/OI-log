var
        i,j,k,n,temp:integer;
        a,b:array[1..100] of integer;
begin
        assign(input,'num.in');reset(input);
        assign(output,'num.out');rewrite(output);

        readln(n);
        for i := 1 to n do read(a[i]);
        for i := 1 to n do b[i] := i;
        read(k);
        for i := 1 to n-1 do
                for j := i+1 to n do
                        if a[i]>a[j] then
                        begin
                                temp := a[i];
                                a[i] := a[j];
                                a[j] := temp;
                                temp := b[i];
                                b[i] := b[j];
                                b[j] := temp;
                        end;
        writeln(a[k]);
        writeln(b[k]);

        close(input);close(output);
end.
