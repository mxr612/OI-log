program minnum;
var
        i,j,k,l,n:longint;
        w,s:real;
begin
        assign(input,'minnum.in');
        reset(input);
        assign(output,'minnum.out');
        rewrite(output);
        read(n);
        i:=0;
        while s<=n do
        begin
                inc(i);
                w:=1/i;
                s:=s+w;
        end;
        write(i);
        close(input);
        close(output);
end.