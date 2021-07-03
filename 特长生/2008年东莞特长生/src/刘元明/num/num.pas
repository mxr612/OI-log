const n=10;
var
   b,c,d,e,f,g:integer;
   a:array[1..n] of integer;
   a1:array[1..n] of integer;
   f1,f2:text;
begin
      assign(f1,'num.in');
      assign(f2,'num.out');
       reset(f1); reset(f2);
       writeln('input n=');
       writeln('input g=');
       for b:=1 to n do
                     read(a[b]);
         for b:=1 to n do
                       write(a[b]);
            for b:=1 to n do
                          a1[b]:=a[b];
              for c:=1 to n-1 do
                for d:=1 to n-1 do
                       if a[c]<a[d+1] then
                                      begin
                                      e:=a[c];
                                      a[c]:=a[d+1];
                                      a[d+1]:=e;
                                      end;
  for b:=1 to n do if a1[b]=a[1] then g:=b;

        rewrite(f2,a[1]);
        writeln;
        rewrite(f2,g);
        close(f1); close(f2);
end.
