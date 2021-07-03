program snake;
var
        i,j,k,n,m,u:integer;
        a:array[0..150,0..150]of integer;
begin
        assign(input,'snake.in');
        assign(output,'snake.out');
        reset(input);
        rewrite(output);
        read(n);
        m:=2*n-1;
        for i:=1 to n do
        begin
                if i mod 2 <>0 then
                for j:=1 to i do
                begin
                        inc(k);
                        a[j,i-j+1]:=k;
                end
                else
                for j:=1 to i do
                begin
                        inc(k);
                        a[i-j+1,j]:=k;
                end;
        end;
        for i:=n+1 to m do
        begin
                u:=i-n+1;
                if i mod 2 =0 then
                for j:=n downto u do
                begin
                        inc(k);
                        a[j,i-j+1]:=k;
                end
                else
                for j:=n downto u do
                begin
                        inc(k);
                        a[i-j+1,j]:=k;
                end;
        end;




        for i:=n downto 1 do
        begin
                for j:=n downto 1 do
                begin
                        write(a[i,j],' ');
                end;
                writeln;
        end;
        close(input);
        close(output);
end.