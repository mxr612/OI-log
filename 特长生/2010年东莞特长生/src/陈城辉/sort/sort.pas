program sort;
var
        i,j,k,n,m:integer;
        a,b,c:array[0..210]of integer;
procedure change(var x,y:integer);
var o:integer;
begin
        o:=x;
        x:=y;
        y:=o;
end;
begin
        assign(input,'sort.in');
        reset(input);
        assign(output,'sort.out');
        rewrite(output);
        read(n);
        for i:=1 to n do
        begin
                read(a[i],b[i]);
        end;
        for i:=1 to n do
                for j:=i+1 to n do
                begin
                        if b[j]>b[i] then
                        begin
                                change(a[i],a[j]);
                                change(b[i],b[j]);
                        end
                        else if(b[j]=b[i])and(a[i]>a[j]) then
                        begin
                                change(a[i],a[j]);
                                change(b[i],b[j]);
                        end;
                end;
        j:=0;
        k:=1;
        for i:=1 to n do
        begin
                inc(j);
                if b[i]<>b[i-1]then begin k:=j;c[i]:=k;end
                else c[i]:=k;
        end;
        for i:=1 to n do
        begin
                writeln(a[i],' ',b[i],' ',c[i]);
        end;
close(input);
close(output);
end.

