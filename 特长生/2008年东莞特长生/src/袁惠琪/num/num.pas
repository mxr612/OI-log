var
        i,j,k,n,t:longint;
        a:array[1..105,1..2] of longint;
begin
        assign(input,'num.in');reset(input);
        assign(output,'num.out');rewrite(output);
        readln(n);
        for i:=1 to n do begin
                read(a[i,1]);
                a[i,2]:=i;
        end;
        readln(k);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if a[i,1] < a[j,1] then begin
                                t:=a[i,1];
                                a[i,1]:=a[j,1];
                                a[j,1]:=t;
                                t:=a[i,2];
                                a[i,2]:=a[j,2];
                                a[j,2]:=t;
                        end;
        writeln(a[k,1]);
        writeln(a[k,2]);
        close(input);close(output);
end.
