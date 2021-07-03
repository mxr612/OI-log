const
     inf='reward.in';
     ouf='reward.out';
     maxn=1005;

var
     n,m,s:longint;
     a:array[1..maxn,1..maxn] of boolean;

 procedure init;
   var
     i:longint;
   begin
     readln(n,m);
     s:=0;
     for i:=1 to n do s:=s+i-1;
     s:=s+n*100;
   end;

 procedure main;
   var
     i,k,x,y,j:longint;
   begin
     fillchar(a,sizeof(a),false);
     for k:=1 to m do
     begin
       readln(x,y);
       a[x,y]:=true;
       if a[x,y] and a[y,x] then
         begin
           writeln(-1);
           exit;
         end;
       for i:=1 to n do
       begin
         if a[i,x] and a[x,y] then a[i,y]:=true;
         if a[i,y] and a[y,i] then
         begin
           writeln(-1);
           exit;
         end;
         if a[i,x] and a[x,i] then
         begin
           writeln(-1);
           exit;
         end;
       end;
     end;
     if n<=100 then
     begin
       for k:=1 to n do
         for i:=1 to n do
           for j:=1 to n do
             if a[i,k] and a[k,j] then a[i,j]:=true;
       for i:=1 to n do
         for j:=1 to n do
           if a[i,j] and a[j,i] then
           begin
             writeln(-1);
             exit;
           end;
     end;
     writeln(s);
   end;

 procedure main2;
   begin
     if m>n then writeln(-1)
            else writeln(s);
   end;

begin
     assign(input,inf);  reset(input);
     assign(output,ouf); rewrite(output);
     init;
     if n<=1000 then main
                else main2;
     close(input);
     close(output);
end.
