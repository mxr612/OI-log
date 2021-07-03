var
        i,j,m,n,x,y,sum:longint;
        f:boolean;
        a:array[1..1000,0..1000] of integer;
        b:array[1..10000] of integer;
begin
        assign(input,'reward.in');reset(input);
        assign(output,'reward.out');rewrite(output);

        readln(n,m);
        for i := 1 to m do
        begin
                read(x,y);
                a[y,x] := 1;
                inc(a[x,0]);
        end;
        f := false;
        while not f do
        begin
                f := true;
                for i := 1 to n do
                        if a[i,0]=0 then
                                for j := 1 to n do
                                        if a[i,j]=1 then
                                        begin
                                                f := false;
                                                if b[i]+1>b[j] then b[j] := b[i]+1;
                                                a[i,j] := 0;
                                                dec(a[j,0]);
                                        end;
        end;
        f := true;
        for i := 1 to n do if a[i,0]<>0 then f := false;
        if f then
        begin
                for i := 1 to n do      inc(sum,b[i]);
                writeln(sum+n*100);
        end
        else writeln(-1);

        close(input);close(output);
end.

