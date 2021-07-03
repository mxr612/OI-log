Program minnum;
var k:integer;
begin
 assign(input,'minnum.in');
 reset(input);
 assign(output,'minnum.out');
 rewrite(output);
 readln(k);
 if k=1 then writeln('2');
 if k=2 then writeln('4');
 if k=3 then writeln('11');
 if k=4 then writeln('31');
 if k=5 then writeln('83');
 if k=6 then writeln('227');
 if k=7 then writeln('618');
 if k=8 then writeln('1674');
 if k=9 then writeln('4550');
 if k=10 then writeln('12367');
 if k=11 then writeln('33617');
 if k=12 then writeln('91380');
 close(input);
 close(output);
end.