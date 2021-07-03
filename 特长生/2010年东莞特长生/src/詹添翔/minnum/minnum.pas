var k,s:real;
    procedure main(n:integer);
      begin
       s:=s+(1/n);
       if s>k then begin write(n);exit;end
              else main(n+1);
      end;
begin
 assign(input,'minnum.in');
 assign(output,'minnum.out');
 reset(input);
 rewrite(output);
 s:=0;
 read(k);
 main(1);
 close(input);
 close(output);
end.