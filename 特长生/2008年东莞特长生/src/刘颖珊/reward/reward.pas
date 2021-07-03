var
        i,j,k,m,n,x,y,sum,point:longint;
        f:boolean;
        a,p:array[0..30000] of integer;
        b,c,d:array[1..10000] of integer;
begin
        assign(input,'reward.in');reset(input);
        assign(output,'reward.out');rewrite(output);

        readln(n,m);
        k := n;
        for i := 1 to m do
        begin
                read(x,y);
                if a[y]=0 then a[y] := x
                else
                begin
                        point := y;
                        while p[point]<>0 do point := p[point];
                        inc(k);
                        a[k] := x;
                        p[point] := k;
                end;
                inc(c[x]);
        end;


        f := false;
        while not f do
        begin
                f := true;
                for i := 1 to n do
                        if (c[i]=0)and(d[i]=0) then
                        begin
                                f := false;
                                d[i] := 1;
                                point := i;
                                while a[point]<>0 do
                                begin
                                        if b[i]+1>b[a[point]] then b[a[point]]:=b[i]+1;
                                        dec(c[a[point]]);
                                        point := p[point];
                                end;
                        end;
        end;

        f := true;
        for i := 1 to n do if c[i]<>0 then f := false;
        if f then
        begin
                for i := 1 to n do      inc(sum,b[i]);
                writeln(sum+n*100);
        end
        else writeln(-1);

        close(input);close(output);
end.