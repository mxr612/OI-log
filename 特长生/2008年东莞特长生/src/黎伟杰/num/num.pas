program num(input,output);
var
   n,i,j:integer;
   a,b:array[1..100]of integer;
   max:integer;
   f:boolean;
   step:integer;
   zhan:integer;
begin
   assign(input,'num.in');
   assign(output,'num.out');
   reset(input);
   rewrite(output);
   read(n);
   for i:=1 to n do read(b[i]);
   a:=b;
   read(max);
   step:=n div 2;
   repeat
   repeat
   for i:=1 to (n-step)  do
   begin
   f:=true;
   if a[i]>a[i+step] then begin zhan:=a[i];a[i]:=a[i+step];a[i+step]:=zhan;f:=false;end;
   end;
   until f;
   step:=step-1;
   until step=0;
   writeln(a[max]);
   for i:=1 to n do if b[i]=a[max] then begin write(i); break; end;
   close(input);
   close(output);
end.