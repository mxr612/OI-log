var
        i,j,j1,k,k1,n:longint;
        a:array[0..510] of longint;
begin
        assign(input,'land.in');reset(input);
        assign(output,'land.out');rewrite(output) ;
        readln(n) ;
        a[1]:=2;k:=1;
        for i:=3 to n*n+1 do begin
        for j:=1 to k do begin
                a[j]:=a[j-1] div 10 +a[j] *2;
                a[j-1]:=a[j-1] mod 10;
        end;
        while a[k] > 10 do begin
                a[k+1] :=a[k+1]+a[k] div 10;
                a[k] :=a[k] mod 10;
                k:=k+1;
        end;
        end;
        i:=1;
        a[1]:=a[1]-1;
        while a[i] < 0  do begin
                a[i]:=a[i] +10;
                a[i+1]:=a[i+1]-1;
        end;
        for i:=k downto 1 do write(a[i]);
        writeln;
        close(input);close(output);
end.



