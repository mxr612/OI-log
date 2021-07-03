var
        i,a,b,c,s,n:longint;
begin
        assign(input,'work.in');reset(input);
        assign(output,'work.out');rewrite(output);
        readln(n);
        for i:=1 to n do begin
                readln(a,b,c) ;
                s:=s+a;
        end;
        writeln(s);
        close(input);close(output);
end.