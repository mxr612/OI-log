program stamps;
var
        n,m,o,i,j,k,t:integer;
        a:array[0..200]of integer;
        b:array[-255..30000]of integer;
begin
        assign(input,'stamps.in');
        assign(output,'stamps.out');
        reset(input);
        rewrite(output);
        read(n);
        read(m);
        for i:=1 to m do
        begin
                read(a[i]);
                b[a[i]]:=1;
        end;
        for i:=1 to m do
                for j:=i+1 to m do
                        if a[i]>a[j] then begin
                                o:=a[i];
                                a[i]:=a[j];
                                a[j]:=o;
                                end;
        k:=1;
        while b[k]<>0 do
        begin
                inc(k);
                for j:=1 to m do
                begin
                        t:=k-a[j];
                        if(b[t]<>0)and(b[t]<n)then
                                if(b[k]=0)or(b[t]<b[k])then b[k]:=b[k-a[j]]+1;
                end;
        end;
        writeln(k-1);
        close(input);
        close(output);
end.



